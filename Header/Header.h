#ifndef HEADER_H
#define HEADER_H

typedef struct {
    unsigned int CR;
    unsigned int CFGR;
    unsigned int CIR;
    unsigned int APB2RSTR;
    unsigned int APB1RSTR;
    unsigned int AHBENR;
    unsigned int APB2ENR;
    unsigned int APB1ENR;
    unsigned int BDCR;
    unsigned int AHBRSTR;
    unsigned int CFGR2;
} RCC_DT;

typedef struct {
    unsigned int CRL;
    unsigned int CRH;
    unsigned int IDR;
    unsigned int ODR;
    unsigned int BSRR;
    unsigned int BRR;
    unsigned int LCKR;
} GPIO_DT;

typedef struct {
    unsigned int SR;
    unsigned int DR;
    unsigned int BRR;
    unsigned int CR1;
    unsigned int CR2;
    unsigned int CR3;
    unsigned int GPTR;
} UART_DT;

#define RCC_BASE     0X40021000
#define GPIOA_BASE   0x40010800
#define UART_BASE   0x40013800   //UART1 base addresss is used.


#define RCC   ((volatile RCC_DT *) RCC_BASE)
#define GPIOA ((volatile GPIO_DT *) GPIOA_BASE)
#define UART ((volatile UART_DT *) UART_BASE)


#endif
