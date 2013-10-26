//
//  EntityNames.h
//  WestWood
//
//  Created by 林光海 on 13-10-26.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef WestWood_EntityNames_h
#define WestWood_EntityNames_h

#include <string>

enum
{
    ent_Miner_Bob,
    
    ent_Elsa
};

inline std::string GetNameOfEntity(int n)
{
    switch (n) {
        case ent_Miner_Bob:
            return "Miner Bob";
            break;
        case ent_Elsa:
            return "Elsa";
            break;
        default:
            return "UNKNOWN!";
            break;
    }
}

#endif
