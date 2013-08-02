//
//  MainLayer.cpp
//  card
//
//  Created by 开发专用 on 13-7-29.
//
//

#include "MainLayer.h"
#include "SimpleAudioEngine.h"
#include "cocos-ext.h"
#include "SceneManager.h"

using namespace cocos2d;
using namespace CocosDenshion;
using namespace cocos2d::extension;

// on "init" you need to initialize your instance
bool MainLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    Sprite * pSprite = Sprite::create("HelloWorld.png");
    //CC_BREAK_IF(!pSprite);
    if (!pSprite)
    {
        CCLOGERROR("create mainlayer helloword failed");
        return false;
    }
    
    pSprite->setPosition(Point(Director::getInstance()->getVisibleSize().width/2,
                              Director::getInstance()->getVisibleSize().height/2));
    addChild(pSprite);
    
//    CCSprite * pSprite1 = CCSprite::create("background.png");
//    //CC_BREAK_IF(!pSprite);
//    if (!pSprite1)
//    {
//        CCLOGERROR("create mainlayer background failed");
//        return false;
//    }
//    
//    pSprite1->setPosition(ccp(CCDirector::sharedDirector()->getVisibleSize().width/2,
//                             CCDirector::sharedDirector()->getVisibleSize().height/2));
//    addChild(pSprite1);
    
//    CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("explosion.plist");
//    CCTexture2D * texture=CCTextureCache::sharedTextureCache()->addImage("explosion.png");
//    
//    CCArray *frames = CCArray::createWithCapacity(35);
//    for(int i = 1; i <= 35; i++)
//    {
//        CCString *frameName;
//        
//        frameName=CCString::createWithFormat("explosion_%02d.png",i);
//        
//        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(frameName->getCString());
//        frames->addObject(frame);
//    }
//    
//    CCSprite *pSprite = CCSprite::createWithSpriteFrameName("explosion_01.png");
//    pSprite->setPosition(ccp(100, 100));
//    
//    
//    CCAnimation *animation = CCAnimation::createWithSpriteFrames(frames);
//    animation->setDelayPerUnit(0.05);
//    animation->setRestoreOriginalFrame(false);
//    CCAnimate * animate = CCAnimate::create(animation);
//    //CCRepeat * showNet=  CCRepeat::create(animate, 1);
//    
//    pSprite->runAction(CCRepeatForever::create(animate));
//    
//    addChild(pSprite,200);
//    return true;
    
    
    LabelTTF *title = LabelTTF::create("Touch Me!3324234", "Marker Felt", 30);
    Scale9Sprite *pScaleSprite = Scale9Sprite::create("Icon-72.png");
    ControlButton *button = ControlButton::create(title, pScaleSprite);
    button->setPosition(Point(EGLView::getInstance()->getVisibleSize().width /2,
                            EGLView::getInstance()->getVisibleSize().height /2));
    button->setPreferredSize(pScaleSprite->getContentSize());
    addChild(button);
    button->addTargetWithActionForControlEvents(this, cccontrol_selector(MainLayer::onChangeScene),Control::EventType::TOUCH_UP_INSIDE);
    
    LabelTTF *pControduce = CCLabelTTF::create("lobby layer!!", "Marker Felt", 50);
    pControduce->setPosition(Point(CCDirector::getInstance()->getVisibleSize().width/2,
                                 CCDirector::getInstance()->getVisibleSize().height/2 + 100));
    addChild(pControduce);
    return true;
}

void MainLayer::onChangeScene(Object* pObject, cocos2d::extension::Control::EventType controlEvent)
{
    CSceneManager::sharedSceneManager()->runWithSceneId(EN_SCENE_COMBAT);
}



