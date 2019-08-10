/*
 * Copyright (c) 2019 by Alexandru - George Rusu. All Rights Reserved.
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>
#include "../my_alloc/my_alloc.h"
#include "../unix_monitor/unix_monitor.h"
#include "ntpq.h"
#include "struct.h"
#include "functions.h"


void read_ntpq_output(ntpq_output *ntpq, int8_t *ntpq_output)
{
  int32_t i = 0;
  const int8_t *delim = " ";
  int8_t *ptr;

  ptr = strtok(ntpq_output, delim);
  
  while(ptr != NULL)
  {
    func_ptr[i](ntpq, structOffset[i], ptr);
    i++;
    ptr = strtok(NULL, delim);
  }
}
