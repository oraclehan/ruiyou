//
//  SceneManager.h
//  card
//
//  Created by ����ר�� on 13-7-29.
//
//

#ifndef card_SceneManager_h
#define card_SceneManager_h
#include "cocos2d.h"
#include "map"

using namespace cocos2d;

//����ID�б�
typedef enum{
    EN_SCENE_NONE =0,
    EN_SCENE_MAIN,      //������
    EN_SCENE_COMBAT    //�˻���ս
} EN_SCENE_ID;

//����ID��Ӧ�Ĵ����ص���������CCLayer::Create
typedef Layer* (*SEL_CREATE)();

#define layer_create_selector(_SELECTOR) (SEL_CREATE)(&_SELECTOR)

class CSceneManager
{
public:
    
    ~CSceneManager();
    
    static CSceneManager *sharedSceneManager();
    
    bool registerSceneId(EN_SCENE_ID enScenceId, SEL_CREATE pfnCreate);
    
    void runWithSceneId(EN_SCENE_ID enScenceId);
    
    //���еĳ�����Ҫ���������ע�ᣬ�����޷�����
    bool init();
    
private:
    
    CSceneManager();
    
    std::map<EN_SCENE_ID, SEL_CREATE> m_mapSceneCreate;
    
};

#endif
