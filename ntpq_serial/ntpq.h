#ifndef _NTPQ_H_
#define _NTPQ_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../my_alloc/my_alloc.h"

#define CMD_INPUT_SIZE       128
#define CMD_OUTPUT_SIZE      16
#define IP_ADDR_LEN          15

#define ASCII_SPACE          32

#define NTPQ_OUT_CTX_MEMBERS 10

#define ptradd(ptr, delta) (ptr = (typeof(ptr)) ((size_t) ptr + (size_t) delta))
#define ptrsync(ptr_dst, ptr_src) (ptr_dst = ((size_t) ptr_src))

typedef struct ntpq_out_ctx
{
  void *access[NTPQ_OUT_CTX_MEMBERS];
  int8_t access_type[NTPQ_OUT_CTX_MEMBERS];
  int8_t *status;
  int8_t *remote;
  int8_t *refid;
  int32_t *stratum;
  int8_t *type;
  int32_t *when;
  int32_t *poll;
  int32_t *reach;
  float *delay;
  float *offset;
  float *jitter;
} ntpq_output;

extern const int8_t _str_type_;
extern const int8_t _char_type_;
extern const int8_t _int32_type_;
extern const int8_t _float_type_;

void init_ntpq_ctx(ntpq_output *ntpq);
void free_ntpq_ctx(ntpq_output *ntpq);
void read_ntpq_output(ntpq_output *ntpq, int8_t *ntpq_output);

#endif