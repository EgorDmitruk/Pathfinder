#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int mx_check_b_sum(const char *file) {
    
    char *str = NULL;
    char *s = malloc(16);
    int i, num, result = 0;
    int fd = open(file, O_RDONLY);

    for(i = 0; i < mx_count_lines(file) + 1; i++) {
        num = mx_read_line(&str, 30, '\n', fd);
        if(num == 1)
            continue;
        else {//no working
            int sub_pos = mx_get_substr_index(str, ",");
            mx_copy_from_char(s, str, sub_pos, '\0');
            result += mx_atoi(s);
            //printf("result is: %i\n",result);
        }
    }
    if(result < __INT_MAX__ && result > 0)
        return result;
    else
        return -1;
}

// int main(void) {
//     int number = mx_check_b_sum("test.txt");
//     printf("Nice! %i\n",number);
//     return 0;
// }
