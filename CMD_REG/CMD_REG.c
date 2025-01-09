#include "CMD_REG.h".h"
#include <string.h>

#define MAX_COMMANDS 10 

static shell_cmd commands[MAX_COMMANDS];
static int command_count = 0;


int register_command(const char *command, const char *help, int (*handler)(int argc, char *argv[])) {
    if (command_count >= MAX_COMMANDS) {
        return -1; 
    }
    commands[command_count++] = (shell_cmd){command, handler, help};
    return 0;
}


const shell_cmd *get_registered_commands(size_t *count) {
    if (count) {
        *count = command_count;
    }
    return commands;
}
