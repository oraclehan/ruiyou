//
//  CombatLayer.cpp
//  card
//
//  Created by 开发专用 on 13-7-29.
//
//

#include "CombatLayer.h"
#include "Player.h"
#include "ResourceManager.h"
using namespace cocos2d;
using namespace cocos2d::extension;

bool CombatLayer::init()
{
    bool bRet = false;
    do
    {
        if (!CCLayer::init())
        {
            return false;
        }
        //加入战斗背景
        Sprite * pSprite1 = Sprite::create("background.jpg");
        CC_BREAK_IF(!pSprite1);
        
        pSprite1->setPosition(Point(CCDirector::getInstance()->getVisibleSize().width/2
                                    + CCDirector::getInstance()->getVisibleOrigin().x,
                                 CCDirector::getInstance()->getVisibleSize().height/2
                                    + CCDirector::getInstance()->getVisibleOrigin().y));
        addChild(pSprite1);
        
        //载入玩家外观
        CPlayer *pPlayer = new CPlayer;
        pPlayer->setPlayerId(0);
        pPlayer->init();
        pPlayer->getSkin()->setPosition(Point(CCDirector::getInstance()->getVisibleOrigin().x + 20,CCDirector::getInstance()->getVisibleOrigin().y));
        
        addChild(pPlayer->getSkin());
//
        //载入玩家外观
        CPlayer *pNewPlayer = new CPlayer;
        pNewPlayer->setPlayerId(1);
        pNewPlayer->init();
        pNewPlayer->getSkin()->setPosition(Point(CCDirector::getInstance()->getVisibleOrigin().x + CCDirector::getInstance()->getVisibleSize().width-20
                                           - pNewPlayer->getSkin()->getContentSize().width,CCDirector::getInstance()->getVisibleOrigin().y));
        
        addChild(pNewPlayer->getSkin());
//
//        
        CPlayerManager::sharedPlayerManager()->setPlayerId(pPlayer->getPlayerId());
        
        
//        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("explosion.plist");
//        CCTexture2D * texture=CCTextureCache::sharedTextureCache()->addImage("explosion.png");
//        
//        CCArray *frames = CCArray::createWithCapacity(35);
//        for(int i = 1; i <= 35; i++)
//        {
//            CCString *frameName;
//            
//            frameName=CCString::createWithFormat("explosion_%02d.png",i);
//            
//            CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName->getCString());
//            frames->addObject(frame);
//        }
//        
//        CCSprite *pSprite = CCSprite::createWithSpriteFrameName("explosion_01.png");
//        pSprite->setPosition(ccp(50,50));
//        
//        
//        CCAnimation *animation = CCAnimation::createWithSpriteFrames(frames);
//        animation->setDelayPerUnit(0.05);
//        animation->setRestoreOriginalFrame(false);
//        CCAnimate * animate = CCAnimate::create(animation);
//        //CCRepeat * showNet=  CCRepeat::create(animate, 2);
//        
//        pSprite->runAction(CCRepeatForever::create(animate));
//        addChild(pSprite);
        
        bRet = true;
    } while (false);
    return true;
}
void CombatLayer::onEnter()
{
    CCLayer::onEnter();
    CCDirector::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, 2, true);
}

void CombatLayer::onExit()
{
    CCLayer::onExit();
    CCDirector::getInstance()->getTouchDispatcher()->removeDelegate(this);
}

bool CombatLayer::ccTouchBegan(Touch *pTouch, Event *pEvent)
{
    return true;
}
void CombatLayer::ccTouchMoved(Touch *pTouch, Event *pEvent)
{
    
}
void CombatLayer::ccTouchEnded(Touch *pTouch, Event *pEvent)
{
//    CCPoint pt = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
//    CResourceManager::sharedResourceManager()->playEffects(0, pt, this);
}

