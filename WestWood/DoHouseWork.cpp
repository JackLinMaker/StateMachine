//
//  DoHouseWork.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "DoHouseWork.h"
#include "MinersWife.h"
#include "Location.h"
#include "EntityNames.h"
#include "Common.h"
DoHouseWork* DoHouseWork::Instance()
{
    static DoHouseWork instance;
    return &instance;
}

void DoHouseWork::Enter(MinersWife *wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Time to do some more housework!";
}

void DoHouseWork::Execute(MinersWife *wife)
{
    switch (RandInt(0, 2)) {
        case 0:
            
            cout << "\n" << GetNameOfEntity(wife->ID()) << ": Moppin' the floor";
            
            break;
            
        case 1:
            
            cout << "\n" << GetNameOfEntity(wife->ID()) << ": Washin' the dishes";
            
            break;
            
        case 2:
            
            cout << "\n" << GetNameOfEntity(wife->ID()) << ": Makin' the bed";
            
            break;
    }
}

void DoHouseWork::Exit(MinersWife *wife)
{

}

bool DoHouseWork::OnMessage(MinersWife *wife, const Telegram &msg)
{
    return false;
}
