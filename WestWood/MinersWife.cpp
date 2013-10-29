//
//  MinersWife.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "MinersWife.h"
#include "DoHouseWork.h"
#include "WifesGlobalState.h"

MinersWife::MinersWife(int id):BaseGameEntity(id),m_Location(shack),m_bCooking(false)
{
    m_pStateMachine = new StateMachine<MinersWife>(this);
    
    m_pStateMachine->SetCurrentState(DoHouseWork::Instance());
    
    m_pStateMachine->SetGlobalState(WifesGlobalState::Instance());
}

MinersWife::~MinersWife()
{
    delete m_pStateMachine;
}

void MinersWife::Update()
{
    m_pStateMachine->Update();
}

bool MinersWife::HandleMessage(const Telegram &msg)
{
    return m_pStateMachine->HandleMessage(msg);
}

StateMachine<MinersWife>* MinersWife::GetFSM() const
{
    return m_pStateMachine;
}

location_type MinersWife::Location() const
{
    return m_Location;
}

void MinersWife::ChangeLocation(const location_type loc)
{
    m_Location = loc;
}

bool MinersWife::Cooking() const
{
    return m_bCooking;
}

void MinersWife::SetCooking(bool val)
{
    m_bCooking = val;
}

