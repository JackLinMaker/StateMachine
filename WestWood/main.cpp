//
//  main.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include "Miner.h"
#include "MinersWife.h"
#include "EntityNames.h"
#include "Location.h"
#include "MessageDispatcher.h"
#include "EntityManager.h"

using namespace std;


int main(int argc, const char * argv[])
{
    srand((unsigned)time(NULL));

    Miner* Bob = new Miner(ent_Miner_Bob);
    
    MinersWife* Elsa = new MinersWife(ent_Elsa);
    
    EntityMgr->RegisterEntity(Bob);
    
    EntityMgr->RegisterEntity(Elsa);
    
    for(int i = 0; i < 30; i++)
    {
        Bob->Update();
        
        Elsa->Update();
        
        Dispatch->DispatchDelayedMessage();
        
        usleep(800);
    }
    delete Bob;
    delete Elsa;
    return 0;
}

