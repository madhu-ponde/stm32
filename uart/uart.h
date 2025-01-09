#include "header.h"
#ifndef UART_H
#define UART_H


void UART_config(void);
char uart_getc(void);
void uart_putc(char c);
void uart_puts(const char *s);
int uart_gets(char *buffer, int len);


#endif
