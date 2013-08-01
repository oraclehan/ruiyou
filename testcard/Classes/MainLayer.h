//
//  MainLayer.h
//  card
//
//  Created by 开发专用 on 13-7-29.
//
//

#ifndef card_MainLayer_h
#define card_MainLayer_h

#include "cocos2d.h"
#include "cocos-ext.h"

class MainLayer : public cocos2d::CCLayer
{
public:
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(MainLayer);
    
    void onChangeScene(cocos2d::CCObject*, cocos2d::extension::CCControlEvent);
};


#endif
