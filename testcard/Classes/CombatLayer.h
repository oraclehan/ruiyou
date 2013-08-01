//
//  CombatLayer.h
//  card
//
//  Created by 开发专用 on 13-7-29.
//
//

#ifndef card_CombatLayer_h
#define card_CombatLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Player.h"

using namespace cocos2d;


//背景，包括背景图片，音乐，背景动画等等
class CBackGround : public CCObject
{
    
};

//主战斗处理类
class CombatLayer : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(CombatLayer);
    
    CC_SYNTHESIZE_RETAIN(CBackGround*, m_pBackGround, BackGround);
    
    virtual void onEnter();
    virtual void onExit();

    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
};



#endif
