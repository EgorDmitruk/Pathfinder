#include "../libmx/inc/libmx.h"
#include "../inc/header.h"

int mx_count_lines(const char *file) {
    int fd = open(file, O_RDONLY);

    char buffer;
    int bytes_read = 0;
    int line_count = 0;

    while((bytes_read = read(fd,&buffer,1))> 0) {
        if(buffer == '\n')
            line_count++;
    }

    return line_count;
}

// int main(void) {
//     char *str;
//     printf("Lines: %i\n", mx_count_lines("test.txt"));
//     printf("Lines by func: %i\n", mx_read_line(&str, 1, '\n', open("test.txt", O_RDONLY)));
//     printf("%s\n", str);
// }
