//
//  VisitBathroom.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include "VisitBathroom.h"
#include "MinersWife.h"
#include "Location.h"
#include "EntityNames.h"

VisitBathroom* VisitBathroom::Instance()
{
    static VisitBathroom instance;
    return &instance;
}

void VisitBathroom::Enter(MinersWife *wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose";
}

void VisitBathroom::Execute(MinersWife *wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Ahhhhhh! Sweet relief!";
    
    wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife *wife)
{
    cout << "\n" << GetNameOfEntity(wife->ID()) << ": Leavin' the Jon";
}