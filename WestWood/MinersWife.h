//
//  MinersWife.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef __WestWood__MinersWife__
#define __WestWood__MinersWife__

#include <iostream>
#include <string>

#include "State.h"
#include "BaseGameEntity.h"
#include "Location.h"
#include "Miner.h"
#include "StateMachine.h"

class MinersWife : public BaseGameEntity
{
public:
    MinersWife(int id);
    
    ~MinersWife();
    
    void Update();
    
    StateMachine<MinersWife>* GetFSM() const;
    
    location_type Location() const;
    
    void ChangeLocation(const location_type loc);
private:
    StateMachine<MinersWife>* m_pStateMachine;
    
    location_type m_Location;
};

#endif /* defined(__WestWood__MinersWife__) */
