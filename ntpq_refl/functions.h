#ifndef _FUNC_H_
#define _FUNC_H_

extern int structOffset[];

extern void (*func_ptr[])(void *, int, void *);

void copy_int(void *ptr, int offset, void *token);

void copy_string(void *ptr, int offset, void *token);

void copy_float(void *ptr, int offset, void *token);

#endif