//
//  CombatLayer.h
//  card
//
//  Created by ����ר�� on 13-7-29.
//
//

#ifndef card_CombatLayer_h
#define card_CombatLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"
#include "Player.h"

using namespace cocos2d;


//��������������ͼƬ�����֣����������ȵ�
class CBackGround : public Object
{
    
};

//��ս��������
class CombatLayer : public cocos2d::Layer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(CombatLayer);
    
    CC_SYNTHESIZE_RETAIN(CBackGround*, m_pBackGround, BackGround);
    
    virtual void onEnter();
    virtual void onExit();

    virtual bool ccTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void ccTouchMoved(Touch *pTouch, Event *pEvent);
    virtual void ccTouchEnded(Touch *pTouch, Event *pEvent);
    
};



#endif
