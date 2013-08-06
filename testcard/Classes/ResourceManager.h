//
//  ResourceManager.h
//  card
//
//  Created by ����ר�� on 13-7-30.
//
//

#ifndef __card__ResourceManager__
#define __card__ResourceManager__
#include "cocos2d.h"
#include <map>
using namespace cocos2d;
using namespace std;

class CResourceManager
{
public:
    static CResourceManager * getInstance();
    
    ~CResourceManager();
    
    bool init();
    
    bool playEffects(unsigned int effectId, const Point &pt, Layer *pLayer);
    
    bool registerEffects(unsigned int effectId, Array *parrFrame);
    
private:
    CResourceManager();
    
    //������Ч����
    map<unsigned int, Array *> m_mapEffects;
    
};

#endif /* defined(__card__ResourceManager__) */
