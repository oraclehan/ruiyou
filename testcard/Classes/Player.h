//
//  Player.h
//  card
//
//  Created by ����ר�� on 13-7-29.
//
//

#ifndef card_Player_h
#define card_Player_h

#include "cocos2d.h"
#include "cocos-ext.h"

using namespace cocos2d;

class CSkin : public Layer
{
public:
    CSkin();
    
    ~CSkin();
    
    CREATE_FUNC(CSkin);
    
    void loadForPlayer(unsigned int iPlayerId);
    
    unsigned int m_iPlayerId;
    
    virtual void onEnter();
    virtual void onExit();
    
    virtual bool ccTouchBegan(Touch *pTouch, Event *pEvent);
    virtual void ccTouchMoved(Touch *pTouch, Event *pEvent);
    virtual void ccTouchEnded(Touch *pTouch, Event *pEvent);
    
    CC_SYNTHESIZE_RETAIN(Sprite*, m_pMainBg, MainBg);
};



//�����
class CPlayer : public Object
{
public:
    CPlayer();
    
    ~CPlayer();
    
    void init();
    //���� health mana xxx
    
    //����
    
    //�츳
    
    //��ۣ���ʱ��һ��С��Ƭ����
    CC_SYNTHESIZE_RETAIN(CSkin*, m_pSkin, Skin);
    
    //��������

    CC_SYNTHESIZE(unsigned int, m_iPlayerId, PlayerId)
    
public:
    //���ʹ�ü��ܹ������ˣ�������Ҳ��Ϊ��һ������
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
    
    
    unsigned int m_uiPlayerId;
};


#endif
