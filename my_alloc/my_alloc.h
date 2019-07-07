#ifndef _MY_ALLOC_H_
#define _MY_ALLOC_H_

#define FC __func__

#define PRINT_ALLOC          0x0

#define SO_INT8_T            sizeof(int8_t)
#define SO_INT32_T           sizeof(int32_t)
#define SO_FLOAT_T           sizeof(float)

void *my_alloc(const int8_t *func_caller, const int8_t *type, size_t *size, int32_t *allocated_memory);
void *my_realloc(const int8_t *func_caller, void *p, const int8_t *type, size_t *size, int32_t *allocated_memory);

void alloc_sync_int32_t(const int8_t *func_caller, int32_t **p, void **access, int8_t *access_type, size_t size);
void alloc_sync_int8_t(const int8_t *func_caller, int8_t **p, void **access, int8_t *access_type, size_t size);
void alloc_sync_float_t(const int8_t *func_caller, float **p, void **access, int8_t *access_type, size_t size);
void alloc_sync_str_t(const int8_t *func_caller, int8_t **p, void **access, int8_t *access_type, size_t size);

#endif

