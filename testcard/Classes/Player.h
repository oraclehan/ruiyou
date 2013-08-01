//
//  Player.h
//  card
//
//  Created by 开发专用 on 13-7-29.
//
//

#ifndef card_Player_h
#define card_Player_h

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;

class CSkin : public CCLayer
{
public:
    CSkin();
    
    ~CSkin();
    
    CREATE_FUNC(CSkin);
    
    void loadForPlayer(unsigned int iPlayerId);
    
    unsigned int m_iPlayerId;
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
    CC_SYNTHESIZE_RETAIN(CCSprite*, m_pMainBg, MainBg);
};



//玩家类
class CPlayer : public CCObject
{
public:
    CPlayer();
    
    ~CPlayer();
    
    void init();
    //属性 health mana xxx
    
    //技能
    
    //天赋
    
    //外观，暂时用一个小卡片代替
    CC_SYNTHESIZE_RETAIN(CSkin*, m_pSkin, Skin);
    
    //其他属性

    CC_SYNTHESIZE(unsigned int, m_iPlayerId, PlayerId)
    
public:
    //玩家使用技能攻击敌人，物理攻击也认为是一个技能
    void attack(unsigned int enemyId, unsigned int skillId);
};

class CPlayerManager
{
public:
    static CPlayerManager * sharedPlayerManager();
    
    bool useSkill(unsigned int recvid);
    
    void setPlayerId(unsigned int uiPlayerId);
    
private:
    CPlayerManager();
    
    CCDictionary m_arrayEnemy;
    
    unsigned int m_uiPlayerId;
};


#endif
