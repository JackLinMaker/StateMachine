//
//  WifesGlobalState.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "WifesGlobalState.h"
#include "MinersWife.h"
#include "EntityNames.h"
#include "Location.h"
#include "VisitBathroom.h"
#include "Common.h"

WifesGlobalState* WifesGlobalState::Instance()
{
    static WifesGlobalState instance;
    return &instance;
}

void WifesGlobalState::Execute(MinersWife *wife)
{
    if(RandFloat() < 0.1)
    {
        wife->GetFSM()->ChangeState(VisitBathroom::Instance());
    }
}