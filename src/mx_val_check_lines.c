#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int mx_check_lines(const char *file) {
    //island1-island2,length_of_bridge
    char *str = NULL;
    int i, num, subs;
    int fd = open(file, O_RDONLY);
    for(i = 0; i < mx_count_lines(file) + 1; i++) {
        num = mx_read_line(&str, 30, '\n', fd);
        if(num == 1)
            continue;
        else {
            subs = mx_get_substr_index(str, "-");
            if(subs != -1) {
                //printf("Sub(d) found at: %i\n", subs);
                if(mx_isalpha(str[subs - 1]) && mx_isalpha(str[subs + 1])) {
                    //continue;
                }
                else {
                    //printf("Mistake line is: %i\n",i);        
                    return i + 1;
                }
            }
            else {
                //printf("Mistake line is: %i\n",i);        
                return i + 1;
                }
                subs = mx_get_substr_index(str, ",");
                if (subs != -1) {
                    if (mx_isalpha(str[subs - 1])) {
                        char *number_start = &str[subs + 1];
                        if (mx_isnumber(number_start)) {
                            while (mx_isnumber(number_start)) {
                                number_start++;
                            }
                            if (*number_start == '\0') {
                                continue;
                            } else {
                                return i + 1;
                            }
                        } else {
                            return i + 1;
                        }
                    } else {
                        return i + 1;
                    }
                } else {
                    return i + 1;
                }
        }   
    }
    return 0;
}

// int main(void) {
//     int number = mx_check_lines("test.txt");
//     printf("All cool! %i\n",number);
//     return 0;
// }
