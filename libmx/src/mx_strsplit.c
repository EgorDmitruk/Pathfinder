#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    if(s == NULL)
        return NULL;

    int arr_size = mx_count_words(s,c);
    char **new_arr = (char **)malloc((arr_size + 1) * sizeof(char *));
    
    if(new_arr == NULL)
        return NULL;

    int word_start = -1;
    int word_len = 0;
    int j = 0;
    bool in_word = false;

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] != c && !in_word) {
            word_start = i;
            in_word = true;
        }
        if((s[i] == c || s[i+1] == '\0') && in_word) {
            word_len = (s[i] == c) ? i - word_start :  i - word_start + 1;
            new_arr[j] = mx_strndup(s + word_start, word_len);
            j++;
            in_word = false;
        }
    }
    new_arr[arr_size] = NULL;
    return new_arr;
}
