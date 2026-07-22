 #ifndef LCDHEADER_H
#define LCDHEADER_H

#include <string.h>
#include "config.h"

#define RS      (1 << 12)
#define RW      (1 << 13)
#define EN      (1 << 18)
#define DATA    (0xFF << 4)

static void delay_ms(unsigned int ms) {
    T0TCR = 0x02;
    T0PR = 15000 - 1;
    T0TCR = 0x01;
    while (T0TC < ms);
    T0TCR = 0x00;
}

static void LCD_Latch(void) {
    IO0SET = EN;
    delay_ms(1);
    IO0CLR = EN;
    delay_ms(1);
}

static void LCD_COMMAND(unsigned char cmd) {
    IO0CLR = RW | RS;
    IO0CLR = DATA;
    IO0SET = (cmd & 0xFF) << 4;
    LCD_Latch();
    delay_ms(2);
}

static void LCD_DATA(unsigned char data) {
    IO0CLR = RW;
    IO0SET = RS;
    IO0CLR = DATA;
    IO0SET = (data & 0xFF) << 4;
    LCD_Latch();
    delay_ms(1);
}

static void LCD_STR(const char *str) {
    while (*str) {
        LCD_DATA(*str++);
    }
}

static void LCD_INIT(void) {
    IO0DIR |= RS | RW | EN | DATA;
    IO0CLR = RS | RW | EN;
    delay_ms(20);
    LCD_COMMAND(0x38);
    LCD_COMMAND(0x0C);
    LCD_COMMAND(0x06);
    LCD_COMMAND(0x01);
}

static void scroll_left_to_right(const char *msg) {
    int len = strlen(msg);
    int i, j;
    char display_buf[21];

    for (i = 0; i < len + 20; i++) {
        LCD_COMMAND(0x01);
        LCD_COMMAND(0x80);

        for (j = 0; j < 20; j++) {
            int idx = i - 20 + j;
            if (idx >= 0 && idx < len) {
                display_buf[j] = msg[idx];
            } else {
                display_buf[j] = ' ';
            }
        }
        display_buf[20] = '\0';
        LCD_STR(display_buf);
        delay_ms(200);
    }
}

#endif
