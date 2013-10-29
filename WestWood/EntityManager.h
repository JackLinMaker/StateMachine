//
//  EntityManager.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__EntityManager__
#define __WestWood__EntityManager__

#include <map>
#include <cassert>
#include <string>
using namespace std;

class BaseGameEntity;
typedef map<int, BaseGameEntity*> EntityMap;

#define EntityMgr EntityManager::Instance()

class EntityManager
{
public:
    static EntityManager* Instance();
    
    void RegisterEntity(BaseGameEntity* NewEntity);
    
    BaseGameEntity* GetEntityFromID(int id) const;
    
    void RemoveEntity(BaseGameEntity* pEntity);
private:
    EntityMap m_EntityMap;
    
    EntityManager(){}
    
    EntityManager(const EntityManager&);
    
    EntityManager& operator=(const EntityManager&);
    
};

#endif /* defined(__WestWood__EntityManager__) */
