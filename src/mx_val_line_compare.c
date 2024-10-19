#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int mx_line_compare(const char *file) {

    char *str = NULL;
    char buff1[64];
    char buff2[64];
    int i, num;
    int fd = open(file, O_RDONLY);

    for(i = 0; i < mx_count_lines(file) + 1; i++) {
        num = mx_read_line(&str, 30, '\n', fd);
        //printf("cur line index: %i\n",num);
        if(num == 1)
            continue;
        else {
            int sub_pos = mx_get_substr_index(str, "-");
            mx_strncpy(buff1, str, sub_pos);
            mx_copy_from_char(buff2, str, sub_pos, ',');
            //printf("%s\n",buff1);
            //printf("%s\n",buff2);
            int result = mx_strcmp(buff1,buff2);
            
            if(result == 0)
                return i + 1;
            else {
                mx_memset(buff1,0,sizeof(buff1));
                mx_memset(buff2,0,sizeof(buff2));
            }
        }
    }
    return 0;
}        

// int main(void) {
//     int number = mx_line_compare("test.txt");
//     printf("Nice! %i\n",number);
//     return 0;
// }

