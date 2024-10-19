#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if(str == NULL)
        return -1;

    int word_count = 0;
    int in_word_check = 0;

    while(*str) {
        if(*str == c) 
            in_word_check = 0;
        else if(in_word_check == 0) {
            in_word_check = 1;
            word_count++;
        }
        str++;
    }
    return word_count;
}
