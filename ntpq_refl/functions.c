#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "struct.h"
#include "functions.h"

#undef MAC
#define MAC(x, y, z, w) offsetof(ntpq_output, z),
int32_t structOffset[] = 
{
  #include "members.h"
};
#undef MAC

#define MAC(x, y, z, w) w,
void (*func_ptr[])(void *, int32_t, void *) =
{
  #include "members.h"
};
#undef MAC

void copy_int(void *ptr, int32_t offset, void *token)
{
  *((int32_t *)((int8_t *)ptr + offset)) = atoi(token);
}

void copy_string(void *ptr, int32_t offset, void *token)
{
  strcpy((int8_t *)ptr + offset, (int8_t *)token);
}

void copy_float(void *ptr, int32_t offset, void *token)
{
  *((float *)((int8_t *)ptr + offset)) = atof(token);
}

