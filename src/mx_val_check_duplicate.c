#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int mx_check_duplicate(const char *file) {

    int lines = mx_count_lines(file) + 1;
    char *str = NULL;
    char buff1[64];
    char buff2[lines][2056];
    int i, num, index = 0;
    int fd = open(file, O_RDONLY);

    for(i = 0; i < mx_count_lines(file) + 1; i++) {
        num = mx_read_line(&str, 30, '\n', fd);
        if(num == 1)
            continue;
        else {
            int sub_pos = mx_get_substr_index(str, ",");
            mx_strncpy(buff1, str, sub_pos);
            mx_strcpy(buff2[index], buff1);
            mx_memset(buff1,0,sizeof(buff1));
            index++;

            continue;
        }
    }
    for(int i = 0; i < lines; i++) {
        for (int j = i + 1; j < lines; j++) {
            //printf("buff2[i] = %s ; buff2[j] = %s\n", buff2[i],buff2[j]);
            if(mx_strcmp(buff2[i], buff2[j]) == 0)
                return i + 2;
        }
        
    }
    return 0;
}        

// int main(void) {
//     int number = mx_check_duplicate("test.txt");
//     printf("Nice! %i\n",number);
//     return 0;
// }
