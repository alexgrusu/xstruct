#ifndef _NTPQ_H_
#define _NTPQ_H_

#include <stdio.h>
#include <inttypes.h>
#include "struct.h"
#include "../unix_monitor/unix_monitor.h"

#define CMD_INPUT_SIZE   128
#define CMD_OUTPUT_SIZE  256


void read_ntpq_output(ntpq_output *ntpq, int8_t *ntpq_output);
void read_shell_output(unix_cmd_monitor *cmd_mon);

void init_unix_cmd_monitor(unix_cmd_monitor *cmd_mon, int8_t *input_cmd, int32_t cmd_in_len, int32_t cmd_out_len);
void free_unix_cmd_monitor(unix_cmd_monitor *cmd_mon);
#endif