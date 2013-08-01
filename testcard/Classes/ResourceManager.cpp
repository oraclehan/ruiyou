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
    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("explosion.plist");
    CCTextureCache::sharedTextureCache()->addImage("explosion.png");
    
    CCArray *frames = CCArray::createWithCapacity(35);
    for(int i = 1; i <= 35; i++)
    {
        CCString *frameName;
        
        frameName=CCString::createWithFormat("explosion_%02d.png",i);
        
        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName->getCString());
        frames->addObject(frame);
    }
    
    registerEffects(0, frames);

    return true;
}

bool CResourceManager::registerEffects(unsigned int effectId, CCArray *parrFrame)
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

bool CResourceManager::playEffects(unsigned int effectId, const CCPoint &pt, CCLayer *pLayer)
{

    map<unsigned int, CCArray*>::iterator itor;
    itor = m_mapEffects.find(effectId);
    
    if (itor == m_mapEffects.end())
    {
        CCLOGERROR("Cant find effects for id %d", effectId);
        return false;
    }
    
    CCSprite *pSprite = CCSprite::createWithSpriteFrame((CCSpriteFrame*)itor->second->objectAtIndex(0));
    CCAnimation *animation = CCAnimation::createWithSpriteFrames(itor->second);
    animation->setDelayPerUnit(0.05);
    animation->setRestoreOriginalFrame(false);
    CCAnimate * animate = CCAnimate::create(animation);
    CCRepeat *repeat = CCRepeat::create(animate, 1);
    
    CCFiniteTimeAction * callFunc=CCCallFunc::create(pSprite, callfunc_selector(CCSprite::removeFromParent));
    pSprite->runAction(CCSequence::create(repeat, callFunc, NULL));
    pSprite->setPosition(pt);
    pLayer->addChild(pSprite);
    
    return true;
}