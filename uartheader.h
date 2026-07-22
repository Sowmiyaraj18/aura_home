#ifndef UARTHEADER_H
#define UARTHEADER_H

#include <lpc21xx.h>

static void UART0_CONFIG(void) {
    PINSEL0 |= 0x00000005;
    U0LCR = 0x83;
    U0DLL = 98;
    U0DLM = 0;
    U0LCR = 0x03;
}

static char UART0_RX(void) 
{
    while (!(U0LSR & 0x01));
    return U0RBR;
}

static void UART0_TX(char ch) 
{
    while (!(U0LSR & 0x20));
    U0THR = ch;
}

static void UART0_STR(const char *str) {
    while (*str) {
        UART0_TX(*str++);
    }
}

#endif
