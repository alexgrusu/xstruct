#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_alloc.h"

const int8_t _str_type_ = 's';
const int8_t _char_type_ = 'c';
const int8_t _int32_type_ = 'i';
const int8_t _float_type_ = 'f';

int32_t debug_alloc = 0;

void *my_alloc(const int8_t *func_caller, const int8_t *type, size_t *size, int32_t *allocated_memory)
{
/*
 * Brief:
 *  Allocates the requested memory and returns a pointer to it.
 * 
 * Parameters:
 *  param[in]  pointer to function caller
 *  param[in]  type of allocated memory
 *  param[in]  requested memory in bytes
 *  param[out] counter of allocated memory
 * 
 * Returns:
 *  This function returns a pointer to the allocated memory, or NULL if the request fails.
 */
  void  *p = NULL;

  p = calloc(*size, SO_INT8_T);

  if(!p)
  {
    fprintf(stderr, "%s failed to allocate memory.\n", func_caller);
    exit(EXIT_FAILURE);
  }
  else
  {
    if(allocated_memory != NULL)
    {
      *allocated_memory += *size;
    }

    if(debug_alloc & PRINT_ALLOC)
    {
      printf("%s alloc %s at address %p a total amount of %ld bytes.\n", func_caller, type, p, *size);
    }
    return p;
  }
}

void *my_realloc(const int8_t *func_caller, void *p, const int8_t *type, size_t *size, int32_t *allocated_memory)
{
/*
 * Brief:
 *  Attempts to resize the memory block pointed to by ptr that was previously allocated with a call to malloc or calloc
 * 
 * Parameters:
 *  param[in]  pointer to function caller
 *  param[in]  memory block pointed to by ptr that was previously allocated
 *  param[in]  type of allocated memory
 *  param[in]  requested memory in bytes
 *  param[out] counter of allocated memory
 * 
 * Returns:
 *  This function returns a pointer to the reallocated memory, or NULL if the request fails.
 */
  void *rp = NULL;
  
  rp = realloc(p, *size);

  if(!rp)
  {
    fprintf(stderr, "%s failed to reallocate memory.\n", func_caller);
    exit(EXIT_FAILURE);
  }
  else
  {
    if(allocated_memory != NULL)
    {
      *allocated_memory += *size;
    }

    memset(rp + (*size >> 1), 0, *size >> 1);
    
    if(debug_alloc & PRINT_ALLOC)
    {
      printf("%s realloc %s at address %p a total amount of %ld bytes.\n", func_caller, type, p, *size);
    }
    return rp;
  }
}

void alloc_sync_int32_t(const int8_t *func_caller, int32_t **p, void **access, int8_t *access_type, size_t size)
{  
/*
 * Brief:
 *  Allocates the requested memory and syncronizes the access pointer with the pointer to the allocated memory.
 *  Sets the type of requested memory.
 * 
 * Parameters:
 *  param[in]  pointer to function caller
 *  param[in]  pointer where to allocate memory
 *  param[in]  access pointer for sync
 *  param[in]  sets type of allocated data
 *  param[in]  size of memory in bytes
 */
  *p = my_alloc(FC, "int32_t", &size, NULL);
  
  *access = *p;

  if(access_type)
    *access_type = _int32_type_;
}

void alloc_sync_int8_t(const int8_t *func_caller, int8_t **p, void **access, int8_t *access_type, size_t size)
{
/*
 * Brief:
 *  Allocates the requested memory and syncronizes the access pointer with the pointer to the allocated memory.
 *  Sets the type of requested memory.
 * 
 * Parameters:
 *  param[in]   pointer to function caller
 *  param[in]   pointer where to allocate memory
 *  param[out]  access pointer for sync
 *  param[out]  initialized type
 *  param[in]   size of memory in bytes
 */
  *p = my_alloc(FC, "int8_t", &size, NULL);
  
  *access = *p;

  if(access_type)
    *access_type = _char_type_;
}

void alloc_sync_float_t(const int8_t *func_caller, float **p, void **access, int8_t *access_type, size_t size)
{  
/*
 * Brief:
 *  Allocates the requested memory and syncronizes the access pointer with the pointer to the allocated memory.
 *  Sets the type of requested memory.
 * 
 * Parameters:
 *  param[in]   pointer to function caller
 *  param[in]   pointer where to allocate memory
 *  param[out]  access pointer for sync
 *  param[out]  initialized type
 *  param[in]   size of memory in bytes
 */
  *p = my_alloc(FC, "float", &size, NULL);
  
  *access = *p;

  if(access_type)
    *access_type = _float_type_;
}

void alloc_sync_str_t(const int8_t *func_caller, int8_t **p, void **access, int8_t *access_type, size_t size)
{
/*
 * Brief:
 *  Allocates the requested memory and syncronizes the access pointer with the pointer to the allocated memory.
 *  Sets the type of requested memory.
 * 
 * Parameters:
 *  param[in]   pointer to function caller
 *  param[in]   pointer where to allocate memory
 *  param[out]  access pointer for sync
 *  param[out]  initialized type
 *  param[in]   size of memory in bytes
 */
  *p = my_alloc(FC, "float", &size, NULL);
  
  *access = *p;

  if(access_type)
    *access_type = _str_type_;
}
