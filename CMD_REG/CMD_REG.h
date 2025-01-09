#ifndef CMD_REG_H
#define CMD_REG_H

#include "shell.h"

int register_command(const char *command, const char *help, int (*handler)(int argc, char *argv[]));
const shell_cmd *get_registered_commands(size_t *count);

extern int cmd_led(int argc, char *argv[]);
extern int cmd_help(int argc, char *argv[]);
extern int cmd_led_toggle(int argc, char *argv[]);



#endif
