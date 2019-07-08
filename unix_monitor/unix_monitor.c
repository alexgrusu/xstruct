/*
 * Copyright (c) 2019 by Alexandru - George Rusu. All Rights Reserved.
 */

#include "unix_monitor.h"
#include "../my_alloc/my_alloc.h"

void read_shell_output(unix_cmd_monitor *cmd_mon)
{
  int8_t chread;
  size_t chlen;

  while((chlen = fread(&chread, 1, sizeof(int8_t), cmd_mon->fd)) != 0)
  {
    if(cmd_mon->out_len + chlen >= cmd_mon->out_alloc)
    {
      cmd_mon->out_alloc <<= 1;
      cmd_mon->shell_output = my_realloc(FC, (void *) cmd_mon->shell_output, "int8_t", &cmd_mon->out_alloc, NULL);
    }
    cmd_mon->shell_output[cmd_mon->out_len] = chread;
    cmd_mon->out_len += chlen;
  }
}

void init_unix_cmd_monitor(unix_cmd_monitor *cmd_mon, int8_t *input_cmd, int32_t cmd_in_len, int32_t cmd_out_len)
{
  cmd_mon->fd = popen(input_cmd, "r");

  if(!cmd_mon->fd)
  {
    printf("Could not open pipe\n");
    return;
  }

  cmd_mon->in_len = cmd_in_len;
  cmd_mon->input_cmd =  my_alloc(FC, "int8_t", &cmd_mon->in_len, NULL);
  memcpy(cmd_mon->input_cmd, input_cmd, cmd_mon->in_len);

  cmd_mon->out_len = 0;
  cmd_mon->out_alloc = cmd_out_len;
  cmd_mon->shell_output = my_alloc(FC, "int8_t", &cmd_mon->out_alloc, NULL);
}

void free_unix_cmd_monitor(unix_cmd_monitor *cmd_mon)
{
  free(cmd_mon->shell_output);
  free(cmd_mon->input_cmd);
  pclose(cmd_mon->fd);
}
