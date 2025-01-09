#include "header.h"
#include "UART.h"

void UART_config() {
    RCC->APB2ENR |= (1 << 14);     
    RCC->APB2ENR |= (1 << 2);      

    GPIOA->CRH &= ~(0xFF0);        
    GPIOA->CRH |= (0xB << 4);      
    GPIOA->CRH |= (0x4 << 8);      

    UART->BRR = 0x341;            
    UART->CR1 &= ~(1 << 12);     
    UART->CR2 = 0x00;             
    UART->CR1 |= (1 << 3);       
    UART->CR1 |= (1 << 2);       
    UART->CR1 |= (1 << 13);      
}


char uart_getc(void) {
    while (!(UART->SR & (1 << 5))); 
    return UART->DR;
}

void uart_putc(char c) {
    while (!(UART->SR & (1 << 7))); 
    UART->DR = c;
}

void uart_puts(const char *s) {
    while (*s) {
        uart_putc(*s++);
    }
}

int uart_gets(char *buffer, int len) {
    char *ptr = buffer;
    char c;

    while ( (c = uart_getc()) != '\n'  && (ptr - buffer) < len - 1) {
        if (c != '\r') {
            *ptr++ = c;
            uart_putc(c);
        }
    }

    *ptr = '\0';
    return ptr - buffer;
}
