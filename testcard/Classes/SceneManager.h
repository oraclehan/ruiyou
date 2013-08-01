//
//  SceneManager.h
//  card
//
//  Created by 开发专用 on 13-7-29.
//
//

#ifndef card_SceneManager_h
#define card_SceneManager_h
#include "cocos2d.h"
#include "map"

using namespace cocos2d;

//场景ID列表
typedef enum{
    EN_SCENE_NONE =0,
    EN_SCENE_MAIN,      //主界面
    EN_SCENE_COMBAT    //人机对战
} EN_SCENE_ID;

//场景ID对应的创建回调函数类型CCLayer::Create
typedef Layer* (*SEL_CREATE)();

#define layer_create_selector(_SELECTOR) (SEL_CREATE)(&_SELECTOR)

class CSceneManager
{
public:
    
    ~CSceneManager();
    
    static CSceneManager *sharedSceneManager();
    
    bool registerSceneId(EN_SCENE_ID enScenceId, SEL_CREATE pfnCreate);
    
    void runWithSceneId(EN_SCENE_ID enScenceId);
    
    //所有的场景需要来这里进行注册，否则无法进入
    bool init();
    
private:
    
    CSceneManager();
    
    std::map<EN_SCENE_ID, SEL_CREATE> m_mapSceneCreate;
    
};

#endif
