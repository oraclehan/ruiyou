//
//  SceneManager.cpp
//  card
//
//  Created by 开发专用 on 13-7-29.
//
//

#include "SceneManager.h"
#include "MainLayer.h"
#include "CombatLayer.h"

static CSceneManager *s_SharedSceneManager = NULL;

CSceneManager::CSceneManager()
{

}

CSceneManager::~CSceneManager()
{
    
}

bool CSceneManager::init()
{
    bool bRet = false;
    do
    {
        bRet = registerSceneId(EN_SCENE_MAIN, layer_create_selector(MainLayer::create));
        CC_BREAK_IF(!bRet);
        
        bRet = registerSceneId(EN_SCENE_COMBAT, layer_create_selector(CombatLayer::create));
        CC_BREAK_IF(!bRet);
        
    } while (false);
    
    return bRet;
}

CSceneManager *CSceneManager::sharedSceneManager()
{
    if (!s_SharedSceneManager)
    {
        s_SharedSceneManager = new CSceneManager();
        assert(s_SharedSceneManager);
        if (!s_SharedSceneManager)
        {
            CCLOGERROR("create SceneManager Failed");
        }
        s_SharedSceneManager->init();
    }
    
    return s_SharedSceneManager;
}

bool CSceneManager::registerSceneId(EN_SCENE_ID enScenceId, SEL_CREATE pfnCreate)
{
    if (pfnCreate && m_mapSceneCreate.find(enScenceId) == m_mapSceneCreate.end())
    {
        m_mapSceneCreate[enScenceId] = pfnCreate;
        return true;
    }
    else
    {
        if (!pfnCreate)
        {
            CCLOGWARN("sceneid %d's create func is null", enScenceId);
        }
        else
        {
            CCLOGWARN("sceneid %d's create func already regeist", enScenceId);
        }
    }
    return false;
}

void CSceneManager::runWithSceneId(EN_SCENE_ID enScenceId)
{
    std::map<EN_SCENE_ID, SEL_CREATE>::iterator itor = m_mapSceneCreate.find(enScenceId);
    if (m_mapSceneCreate.end() != itor)
    {
        if (itor->second)
        {
            Layer *pLayer = itor->second();
            if (!pLayer)
            {
                CCLOGERROR("secneid %d's create func returns null", enScenceId);
                return;
            }
            
            Scene *pScene = Scene::create();
            if (!pScene)
            {
                CCLOGERROR("CCSene::create failed");
                return;
            }
            
            
            pScene->addChild(pLayer);
            if (CCDirector::getInstance()->getRunningScene())
            {
                CCDirector::getInstance()->replaceScene(pScene);
            }
            else
            {
                CCDirector::getInstance()->runWithScene(pScene);
            }
            
            return;
        }
    }
    CCLOGWARN("sceneid %d not execute", enScenceId);
}

