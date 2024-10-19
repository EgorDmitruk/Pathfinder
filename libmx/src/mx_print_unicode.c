#include "../inc/libmx.h"

void mx_print_unicode(wchar_t c) {
    char symbol[5];

    if (c < 0x80) {
        symbol[0] = ((c >> 0) & 0x7F) | 0x00;
        symbol[1] = '\0';
        symbol[2] = '\0';
        symbol[3] = '\0';
        symbol[4] = '\0';
    }
    else if (c < 0x0800) {
        symbol[0] = ((c >> 6) & 0x1F) | 0xC0;
        symbol[1] = ((c >> 0) & 0x3F) | 0x80;
        symbol[2] = '\0';
        symbol[3] = '\0';
        symbol[4] = '\0';
    }
    else if (c < 0x010000) {
        symbol[0] = ((c >> 12) & 0x0F) | 0xE0;
        symbol[1] = ((c >> 6 ) & 0x3F) | 0x80;
        symbol[2] = ((c >> 0 ) & 0x3F) | 0x80;
        symbol[3] = '\0';
        symbol[4] = '\0';
    }
    else if (c < 0x110000) {
        symbol[0] = ((c >> 18) & 0x07) | 0xF0;
        symbol[1] = ((c >> 12) & 0x3F) | 0x80;
        symbol[2] = ((c >> 6 ) & 0x3F) | 0x80;
        symbol[3] = ((c >> 0 ) & 0x3F) | 0x80;
        symbol[4] = '\0';
    }
    write(1, symbol, mx_strlen(symbol));
}
