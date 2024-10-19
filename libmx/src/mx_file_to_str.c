#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if(file == NULL)
        return NULL;
    
    FILE *fp = fopen(file, "r");
    if(fp == NULL)
        return NULL;

    fseek(fp, 0, SEEK_END);
    unsigned long file_zise = ftell(fp);
    rewind(fp);

    char *str = (char *)malloc(file_zise + 1);
    if(str == NULL) {
        fclose(fp);
        return NULL;
    }

    if(fread(str,1,file_zise,fp) != file_zise) {
        free(str);
        fclose(fp);
        return NULL;
    }

    str[file_zise] = '\0';
    fclose(fp);
    return str;

}
