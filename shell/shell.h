#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>

typedef struct ShellCommand {
    const char *command;
    int (*handler)(int argc, char *argv[]);
    const char *help;
}shell_cmd;



void shell_process_command(const char *line);
void shell_put_line(const char *line);

#endif
