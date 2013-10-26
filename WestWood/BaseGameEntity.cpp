//
//  BaseGameEntity.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "BaseGameEntity.h"

int BaseGameEntity::m_iNextValidID = 0;

BaseGameEntity::BaseGameEntity(int id)
{
    SetID(id);
}

BaseGameEntity::~BaseGameEntity()
{

}

int BaseGameEntity::ID() const
{
    return m_ID;
}

void BaseGameEntity::SetID(int val)
{
    assert( (val >= m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID");
    
    m_ID = val;
    
    m_iNextValidID = m_ID + 1;
}