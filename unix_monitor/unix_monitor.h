#ifndef _UNIX_MONITOR_H_
#define _UNIX_MONITOR_H_

#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdlib.h>

typedef struct unix_cmd_ctx
{
  FILE *fd;
  int8_t *input_cmd;
  int8_t *shell_output;
  size_t in_len;
  size_t out_len;
  size_t out_alloc;

} unix_cmd_monitor;

void init_unix_cmd_monitor(unix_cmd_monitor *cmd_mon, int8_t *input_cmd, int32_t cmd_in_len, int32_t cmd_out_len);
void free_unix_cmd_monitor(unix_cmd_monitor *cmd_mon);
void read_shell_output(unix_cmd_monitor *cmd_mon);

#endif