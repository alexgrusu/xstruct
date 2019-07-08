/*
 * Copyright (c) 2019 by Alexandru - George Rusu. All Rights Reserved.
 */

#ifndef _STRUCT_H_
#define _STRUCT_H_

#define MAC(x, y, z, w) x z y;
typedef struct ntpq_out_ctx
{
  #include "members.h"
} ntpq_output;
#undef MAC

#endif