//
//  main.cpp
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#include <iostream>
#include <unistd.h>
#include "Miner.h"
#include "MinersWife.h"
#include "EntityNames.h"
#include "Location.h"
using namespace std;


int main(int argc, const char * argv[])
{

    Miner Bob(ent_Miner_Bob);
    
    MinersWife Elsa(ent_Elsa);
    
    for(int i = 0; i < 20; ++i)
    {
        Bob.Update();
        Elsa.Update();
        usleep(800);
        
    }
    return 0;
}

