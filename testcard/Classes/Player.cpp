//
//  Player.cpp
//  card
//
//  Created by 开发专用 on 13-7-29.
//
//

#include "Player.h"
#include "ResourceManager.h"

CPlayer::CPlayer()
{
    m_pSkin = NULL;
}

CPlayer::~CPlayer()
{
    CC_SAFE_RELEASE(m_pSkin);
}

void CPlayer::init()
{
    if (!m_pSkin)
    {
        CSkin*pSkin = CSkin::create();
        if (!pSkin)
        {
            CCLOGERROR("CSkin::create() failed");
            return;
        }
        setSkin(pSkin);
    }
    
    m_pSkin->loadForPlayer(m_iPlayerId);
}

CSkin::CSkin()
{
    m_pMainBg = NULL;
}

CSkin::~CSkin()
{
    CC_SAFE_RELEASE(m_pMainBg);
}

void CSkin::loadForPlayer(unsigned int iPlayerId)
{
    //直接加载一个图片得了
    Sprite *pMainBg = Sprite::create("player.jpg");
    pMainBg->setAnchorPoint(Point::ZERO);
    
    setContentSize(pMainBg->getContentSize());
    addChild(pMainBg);
    
    m_iPlayerId = iPlayerId;
    
    if (0 == iPlayerId)
    {
        LabelTTF *pLabel = LabelTTF::create("Me!", "Marker Felt", 30);
        pLabel->setPosition(Point(getContentSize().width/2, getContentSize().height/2));
        addChild(pLabel);
    }
    else
    {
        LabelTTF *pLabel = LabelTTF::create("Enemy!", "Marker Felt", 30);
        pLabel->setPosition(Point(getContentSize().width/2, getContentSize().height/2));
        addChild(pLabel);
    }
}

//void CSkin::setPosition(const CCPoint &position)
//{
//    if (m_pMainBg)
//    {
//        m_pMainBg->setPosition(position);
//        
//        //刷新其他物件的位置
//    }
//}

//const CCSize& CSkin::getContentSize()
//{
//    if (m_pMainBg)
//    {
//        return m_pMainBg->getContentSize();
//        //刷新其他物件的位置
//    }
//    return CCSizeZero;
//}

bool CSkin::ccTouchBegan(Touch *pTouch, Event *pEvent)
{
    Rect rect(getPosition().x, getPosition().y,getContentSize().width, getContentSize().height);
    Point pt = CCDirector::getInstance()->convertToGL(pTouch->getLocationInView());
    if (rect.containsPoint(pt))
    {
        return true;
    }
    return false;
}
void CSkin::ccTouchMoved(Touch *pTouch, Event *pEvent)
{
    
}
void CSkin::ccTouchEnded(Touch *pTouch, Event *pEvent)
{
    Point pt = CCDirector::getInstance()->convertToGL(pTouch->getLocationInView());
    if (CPlayerManager::sharedPlayerManager()->useSkill(m_iPlayerId))
    {
    //this->convertToNodeSpace(pt)
        CResourceManager::sharedResourceManager()->playEffects(0, convertToNodeSpace(pt), this);
    }
    
}

void CSkin::onEnter()
{
    CCLayer::onEnter();
    CCDirector::getInstance()->getTouchDispatcher()->addTargetedDelegate(this, 1, true);
}

void CSkin::onExit()
{
    CCLayer::onExit();
    CCDirector::getInstance()->getTouchDispatcher()->removeDelegate(this);
}

static CPlayerManager *s_SharedPlayerManager = NULL;

CPlayerManager* CPlayerManager::sharedPlayerManager()
{
    if (!s_SharedPlayerManager)
    {
        s_SharedPlayerManager = new CPlayerManager;
    }
    return s_SharedPlayerManager;
}

bool CPlayerManager::useSkill(unsigned int recvid)
{
    if (recvid == m_uiPlayerId)
    {
        CCLOGINFO("touched my self");
        //释放增益技能
        return false;
    }
    //释放伤害技能
    return true;
}

CPlayerManager::CPlayerManager()
{
    
}

void CPlayerManager::setPlayerId(unsigned int uiPlayerId)
{
    m_uiPlayerId = uiPlayerId;
}

