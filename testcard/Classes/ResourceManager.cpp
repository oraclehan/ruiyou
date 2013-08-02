//
//  ResourceManager.cpp
//  card
//
//  Created by 开发专用 on 13-7-30.
//
//

#include "ResourceManager.h"
#include "cocos2d.h"

static CResourceManager *s_SharedResouceManager = NULL;


CResourceManager * CResourceManager::sharedResourceManager()
{
    if (!s_SharedResouceManager)
    {
        s_SharedResouceManager = new CResourceManager;
        if (!s_SharedResouceManager)
        {
            CCLOGERROR("new CResouceManager failed");
            assert(false);
            return NULL;
        }
        
        if (!s_SharedResouceManager->init())
        {
            CCLOGERROR("Instance Init failed");
            assert(false);
        }
    }
    return s_SharedResouceManager;
}

bool CResourceManager::init()
{
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("explosion.plist");
    TextureCache::getInstance()->addImage("explosion.png");
    
    Array *frames = Array::createWithCapacity(35);
    for(int i = 1; i <= 35; i++)
    {
        String *frameName;
        
        frameName=String::createWithFormat("explosion_%02d.png",i);
        
        SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(frameName->getCString());
        frames->addObject(frame);
    }
    
    registerEffects(0, frames);

    return true;
}

bool CResourceManager::registerEffects(unsigned int effectId, Array *parrFrame)
{
    if (!parrFrame)
    {
        return false;
    }
    
    if (m_mapEffects.find(effectId) != m_mapEffects.end())
    {
        CCLOGERROR("effect %d has exist!", effectId);
        return false;
    }
    m_mapEffects[0] = parrFrame;
    m_mapEffects[0]->retain();
    return true;
}

CResourceManager::CResourceManager()
{
    
}

CResourceManager::~CResourceManager()
{
    
}

bool CResourceManager::playEffects(unsigned int effectId, const Point &pt, Layer *pLayer)
{

    map<unsigned int, Array*>::iterator itor;
    itor = m_mapEffects.find(effectId);
    
    if (itor == m_mapEffects.end())
    {
        CCLOGERROR("Cant find effects for id %d", effectId);
        return false;
    }
    
    Sprite *pSprite = CCSprite::createWithSpriteFrame((SpriteFrame*)itor->second->objectAtIndex(0));
    Animation *animation = CCAnimation::createWithSpriteFrames(itor->second);
    animation->setDelayPerUnit(0.05);
    animation->setRestoreOriginalFrame(false);
    Animate * animate = Animate::create(animation);
    Repeat *repeat = Repeat::create(animate, 1);
    FiniteTimeAction * callFunc=CallFunc::create(CC_CALLBACK_0(Sprite::removeFromParent, pSprite));
    //FiniteTimeAction * callFunc=CallFunc::create(pSprite, callfunc_selector(Sprite::removeFromParent));
    pSprite->runAction(CCSequence::create(repeat, callFunc, NULL));
    pSprite->setPosition(pt);
    pLayer->addChild(pSprite);
    
    return true;
}