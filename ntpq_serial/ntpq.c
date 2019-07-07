#include "ntpq.h"

void init_ntpq_ctx(ntpq_output *ntpq)
{
  int32_t i = 0;

  if(ntpq == NULL)
  {
    printf("ntpq pointer NULL\n");
    exit(EXIT_FAILURE);
  }

  alloc_sync_str_t(FC, &ntpq->remote,  &(ntpq->access[i++]), &ntpq->access_type[i], IP_ADDR_LEN);
  
  alloc_sync_str_t(FC, &ntpq->refid,  &(ntpq->access[i++]), &ntpq->access_type[i], IP_ADDR_LEN);

  alloc_sync_int32_t(FC, &ntpq->stratum, &(ntpq->access[i++]), &ntpq->access_type[i], SO_INT32_T);

  alloc_sync_int8_t(FC, &ntpq->type, &(ntpq->access[i++]), &ntpq->access_type[i], SO_INT8_T);

  alloc_sync_int32_t(FC, &ntpq->when, &(ntpq->access[i++]), &ntpq->access_type[i], SO_INT32_T);

  alloc_sync_int32_t(FC, &ntpq->poll, &(ntpq->access[i++]), &ntpq->access_type[i], SO_INT32_T);

  alloc_sync_int32_t(FC, &ntpq->reach, &(ntpq->access[i++]), &ntpq->access_type[i], SO_INT32_T);

  alloc_sync_float_t(FC, &ntpq->delay, &(ntpq->access[i++]), &ntpq->access_type[i], SO_FLOAT_T);

  alloc_sync_float_t(FC, &ntpq->offset, &(ntpq->access[i++]), &ntpq->access_type[i], SO_FLOAT_T);

  alloc_sync_float_t(FC, &ntpq->jitter, &(ntpq->access[i++]), &ntpq->access_type[i], SO_FLOAT_T);
}

void free_ntpq_ctx(ntpq_output *ntpq)
{
  int8_t i = 0;

  if(ntpq != NULL)
  {
    for(i = 0; i < NTPQ_OUT_CTX_MEMBERS; i++)
    {
      free(ntpq->access[i]);
    }
  }
  else
  {
    printf("ntpq pointer NULL\n");
    exit(EXIT_FAILURE);
  }
}

void read_ntpq_output(ntpq_output *ntpq, int8_t *ntpq_output)
{
  int32_t i = 0;
  int8_t *ptr = NULL;
  int8_t delim = ASCII_SPACE;

  ptr = strtok(ntpq_output, &delim);

	while(ptr != NULL)
  {
    if((ntpq->access_type[i] == _str_type_))
    {
      if(!i)
        strcpy(ntpq->access[i], ptradd(ptr, 1));
      else
        strcpy(ntpq->access[i], ptr);
    }
    else if(ntpq->access_type[i] == _char_type_)
    {
      *((int8_t *) ntpq->access[i]) = *ptr;
    }
    else if(ntpq->access_type[i] == _int32_type_)
    {
      *((int32_t *) ntpq->access[i]) = atoi(ptr);
    }
    else if(ntpq->access_type[i] == _float_type_)
    {
      *((float *) ntpq->access[i]) = atof(ptr);
    }
    i++;
		ptr = strtok(NULL, &delim);
	}
}
