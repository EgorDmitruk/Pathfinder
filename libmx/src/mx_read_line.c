#include "../inc/libmx.h"

void mx_free(char *b1, char *b2) {
    free(b1);
    free(b2);
}

char *catfree(char const *s1, char const *s2) {
    if (s1 == NULL && s2 == NULL)
        return NULL;
    else if (s1 == NULL && s2)
        return mx_strdup(s2);
    else if (s1 && s2 == NULL)
        return mx_strdup(s1);
        
    char *new_str = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
    new_str = mx_strcat(mx_strcpy(new_str, s1), s2);
    char *d = (char *)s1;
    mx_strdel(&d);

    return new_str;
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (buf_size == 0) 
        return -2;
    
    buf_size = 1;
    int bytes, res = 0;
    char *temp = *lineptr;
    *lineptr = NULL;
    char *buffer = mx_strnew(buf_size);
    
    while ((bytes = read(fd, buffer, buf_size)) > 0) {
        if (mx_get_char_index(buffer, delim) >= 0) {
            buffer[mx_get_char_index(buffer, delim)] = '\0';
            *lineptr = catfree(*lineptr, buffer);
            res += mx_strlen(buffer);
            
            mx_free(buffer,temp);
            return res;
        }
        *lineptr = catfree(*lineptr, buffer);
        res += bytes;
    }
    if (res == 0) {
        *lineptr = temp;
        free(buffer);

        int num = (bytes == -1) ? -2 : -1;
        return num;
    }
    free(buffer);
    return res;
}

// int main(void) {
//     char *str;
//     int fd = open("fragment.txt", O_RDONLY);
//     int res = mx_read_line(&str, 7, '\n', fd); //res = 8, str = "FADE IN:"
//     printf("res is: %i\n", res);
//     printf("str is: %s\n", str);
//     res = mx_read_line(&str, 35, 'a', fd); //res = 34, str = "
//     printf("res is: %i\n", res);
//     printf("str is: %s\n", str);
// //ON COMPUTER SCREEN
// //
// //so close it h"

//     res = mx_read_line(&str, 15, '.', fd); //res = 15, str = "s no boundaries"
//     printf("res is: %i\n", res);
//     printf("str is: %s\n", str);
//     res = mx_read_line(&str, 10, '\n', fd); //res = 0, str = ""
//     printf("res is: %i\n", res);
//     printf("str is: %s\n", str);
// }
