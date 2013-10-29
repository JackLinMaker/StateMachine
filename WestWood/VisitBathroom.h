//
//  VisitBathroom.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__VisitBathroom__
#define __WestWood__VisitBathroom__

#include <iostream>
#include "State.h"
using namespace std;
class MinersWife;

class VisitBathroom : public State<MinersWife> {
public:
    static VisitBathroom* Instance();
    
    virtual void Enter(MinersWife* wife);
    
    virtual void Execute(MinersWife* wife);
    
    virtual void Exit(MinersWife* wife);
    
    virtual bool OnMessage(MinersWife* wife, const Telegram& msg);

private:
    VisitBathroom(){}
    
    VisitBathroom(const VisitBathroom&);
    
    VisitBathroom& operator=(const VisitBathroom&);
};

#endif /* defined(__WestWood__VisitBathroom__) */
