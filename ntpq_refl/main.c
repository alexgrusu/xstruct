#include <stdio.h>
#include <string.h> // strtok
#include "functions.h"
#include <inttypes.h>
#include "ntpq.h"

int8_t input_command[CMD_INPUT_SIZE] = "/usr/bin/ntpq -np | /bin/grep \"*\"";

int32_t main(int32_t argc, int8_t **argv)
{
  unix_cmd_monitor unix_cmd;

  ntpq_output ntpq;

  init_unix_cmd_monitor(&unix_cmd, input_command, CMD_INPUT_SIZE, CMD_OUTPUT_SIZE);

  read_shell_output(&unix_cmd);

  printf("\'ntpq -np\' output:\n");
  fwrite(unix_cmd.shell_output, 1, unix_cmd.out_len, stdout);

  read_ntpq_output(&ntpq, unix_cmd.shell_output);

  printf("\nntpq structure\n");
  printf("remote ip: %s\n", ntpq.remote);
  printf("ref id:    %s\n", ntpq.refid);
  printf("stratum:   %d\n", ntpq.stratum);
  printf("type:      %s\n", ntpq.type);
  printf("when:      %d\n", ntpq.when);
  printf("poll:      %d\n", ntpq.poll);
  printf("reach:     %d\n", ntpq.reach);
  printf("delay:     %lf\n",ntpq.delay);
  printf("offset:    %lf\n", ntpq.offset);
  printf("jitter:    %lf\n", ntpq.jitter);

  free_unix_cmd_monitor(&unix_cmd);

  return 0;
}