#include "shell.h"
#include "GPIO.h"
#include "UART.h"
#include "CMD_REG.h"
#include<string.h>
#include<stdio.h>

static int state=0;

void shell_put_line(const char *line) 
{
    uart_puts(line);
    uart_puts("\r\n");
}
int cmd_led_toggle(int argc, char *argv[])
{
    state = !state; 
    led_state(state);
    shell_put_line(state ? "LED toggled ON" : "LED toggled OFF");
    return 0;
}
int cmd_led(int argc, char *argv[]) 
{
    if (argc != 2) {
        shell_put_line("Usage: LED <ON|OFF>");
        return -1;
    }

    if (strcasecmp(argv[1], "ON") == 0) {
      state=1;
			led_state(state);
        shell_put_line("\nLED is ON");
    } else if (strcasecmp(argv[1], "OFF") == 0) {
			  state=0;
        led_state(0);
        shell_put_line("\nLED is OFF");
    } else {
        shell_put_line("\nInvalid argument. Use ON or OFF");
        return -1;
    }

    return 0;
}
/*
int cmd_help(int argc, char *argv[]) {
    shell_put_line("  LED <ON> - TO TURN ON LED");
	  shell_put_line("  LED <OFF> - TO TURN OFF LED");
    return 0;
}*/


int cmd_help(int argc, char *argv[]) 
{
    shell_put_line("Available commands:");
