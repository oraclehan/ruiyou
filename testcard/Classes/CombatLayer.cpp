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
        CCSprite * pSprite1 = CCSprite::create("background2.jpg");
        CC_BREAK_IF(!pSprite1);
        
        pSprite1->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
                                 CCDirector::sharedDirector()->getVisibleSize().height/2));
        addChild(pSprite1);
        
        //载入玩家外观
        CPlayer *pPlayer = new CPlayer;
        pPlayer->setPlayerId(0);
        pPlayer->init();
        pPlayer->getSkin()->setPosition(ccp(20,0));
        
        addChild(pPlayer->getSkin());
//
        //载入玩家外观
        CPlayer *pNewPlayer = new CPlayer;
        pNewPlayer->setPlayerId(1);
        pNewPlayer->init();
        pNewPlayer->getSkin()->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width-20
                                           - pNewPlayer->getSkin()->getContentSize().width,0));
        
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
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, 2, true);
}

void CombatLayer::onExit()
{
    CCLayer::onExit();
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
}

bool CombatLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
    return true;
}
void CombatLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
    
}
void CombatLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
//    CCPoint pt = CCDirector::sharedDirector()->convertToGL(pTouch->getLocationInView());
//    CResourceManager::sharedResourceManager()->playEffects(0, pt, this);
}

