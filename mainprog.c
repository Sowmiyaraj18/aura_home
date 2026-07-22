#include <lpc21xx.h>
#include <string.h>

#include "lcdheader.h"
#include "uartheader.h"

#define light1      (1 << 14)
#define light2      (1 << 15)
#define light3      (1 << 16)
#define light4      (1 << 17)

char ch;
char rx_buf[120];
int i = 0;

static void UpdateDisplay(void) {
    int l1 = (IO0PIN & light1) ? 0 : 1;
    int l2 = (IO0PIN & light2) ? 0 : 1;
    int l3 = (IO0PIN & light3) ? 0 : 1;
    int l4 = (IO0PIN & light4) ? 0 : 1;
    
    LCD_COMMAND(0x80);
    LCD_STR(l1 ? "LIGHT_1:ON " : "LIGHT_1:OFF");
    LCD_COMMAND(0xC0);
    LCD_STR(l2 ? "LIGHT_2:ON " : "LIGHT_2:OFF");
    LCD_COMMAND(0x94);
    LCD_STR(l3 ? "LIGHT_3:ON " : "LIGHT_3:OFF");
    LCD_COMMAND(0xD4);
    LCD_STR(l4 ? "LIGHT_4:ON " : "LIGHT_4:OFF");
}

static void ProcessCommand(const char *cmd) {
    if (strcmp(cmd, "light1on") == 0) {
        IOCLR0 = light1;
        UpdateDisplay();
        UART0_STR("ACK:ON\n");
    } 
    else if (strcmp(cmd, "light1off") == 0) {
        IOSET0 = light1;
        UpdateDisplay();
        UART0_STR("ACK:OFF\n");
    } 
    else if (strcmp(cmd, "light2on") == 0) {
        IOCLR0 = light2;
        UpdateDisplay();
        UART0_STR("ACK:ON\n");
    } 
    else if (strcmp(cmd, "light2off") == 0) {
        IOSET0 = light2;
        UpdateDisplay();
        UART0_STR("ACK:OFF\n");
    } 
    else if (strcmp(cmd, "light3on") == 0) {
        IOCLR0 = light3;
        UpdateDisplay();
        UART0_STR("ACK:ON\n");
    } 
    else if (strcmp(cmd, "light3off") == 0) {
        IOSET0 = light3;
        UpdateDisplay();
        UART0_STR("ACK:OFF\n");
    } 
    else if (strcmp(cmd, "light4on") == 0) {
        IOCLR0 = light4;
        UpdateDisplay();
        UART0_STR("ACK:ON\n");
    } 
    else if (strcmp(cmd, "light4off") == 0) {
        IOSET0 = light4;
        UpdateDisplay();
        UART0_STR("ACK:OFF\n");
    } 
    else {
        UART0_STR("ERR:UNKNOWN_CMD\n");
    }
}

int main(void) {
    IODIR0 |= light1 | light2 | light3 | light4;
    IOSET0 = light1 | light2 | light3 | light4;
    LCD_INIT();
    UART0_CONFIG();
    scroll_left_to_right("AURA HOME:An Integrated IoT framework for cloud based domestic automation");
    LCD_COMMAND(0x01);
    UpdateDisplay();

    while (1) {
        ch = UART0_RX();
        if (ch != '\r' && ch != '\n') {
            rx_buf[i++] = ch;
            if (i >= sizeof(rx_buf) - 1) {
                i = 0;
                rx_buf[0] = '\0';
            }
            rx_buf[i] = '\0';

            if (strcmp(rx_buf, "light1on") == 0 || strcmp(rx_buf, "light1off") == 0 ||
                strcmp(rx_buf, "light2on") == 0 || strcmp(rx_buf, "light2off") == 0 ||
                strcmp(rx_buf, "light3on") == 0 || strcmp(rx_buf, "light3off") == 0 ||
                strcmp(rx_buf, "light4on") == 0 || strcmp(rx_buf, "light4off") == 0) {
                
                ProcessCommand(rx_buf);
                i = 0;
                rx_buf[0] = '\0';
            }
        }
    }
}
