//
//  Common.h
//  WestWood
//
//  Created by 林光海 on 13-10-29.
//  Copyright (c) 2013年 林光海. All rights reserved.
//

#ifndef WestWood_Common_h
#define WestWood_Common_h

static int RandInt(int min, int max)
{
    return min + (rand() % (int)(max - min + 1));
}

static float RandFloat()
{
    return (float)rand()/(float)RAND_MAX;
}

#endif
