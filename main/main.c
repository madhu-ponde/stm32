#include "GPIO.h"
#include "header.h"
#include "UART.h"
#include "shell.h"
#include "CMD_REG.h"


int main(void) {
   
    GPIO_config();
    UART_config();
    
	  char line[100];
	
	shell_put_line("CLI Ready. Type HELP to list the available commands.");

   
    register_command("LED", "Control the LED (ON/OFF)", cmd_led);
    register_command("HELP", "List available commands", cmd_help);
	  register_command("TOGGLE", "Toggle the LED state", cmd_led_toggle);


    while (1) {
        uart_puts("$");
        if (uart_gets(line, sizeof(line)) > 0) {
            shell_process_command(line);
        }
    }

