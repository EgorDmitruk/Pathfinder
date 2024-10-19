#ifndef LIBMX_H
#define LIBMX_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#include <stddef.h>
#include <stdbool.h>
#include <fcntl.h>
#include <limits.h>
#include <stddef.h>

typedef struct s_list {
void *data;
struct s_list *next;
} t_list;

void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_print_unicode(wchar_t c);
void mx_print_strarr(char **arr, const char *delim);
void mx_printint(int n);
double mx_pow(double n, unsigned int pow);
int mx_sqrt(int x);
char *mx_nbr_to_hex(unsigned long nbr);
unsigned long mx_hex_to_nbr(const char *hex);
char *mx_itoa(int number);
int mx_strlen(const char *s);
void mx_foreach(int *arr, int size, void (*f)(int));
int mx_binary_search(char **arr, int size, const char *s, int *count);
int mx_bubble_sort(char **arr, int size);
int mx_quicksort(char **arr, int left, int right);
void mx_swap_char(char *s1, char *s2);
void mx_str_reverse(char *s);
void mx_strdel(char **str);
void mx_del_strarr(char ***arr);
int mx_get_char_index(const char *str, char c);
char *mx_strdup(const char *s1);
char *mx_strndup(const char *s1, size_t n);
char *mx_strcpy(char *dst, const char *src);
char *mx_strncpy(char *dst, const char *src, int len);
int mx_strcmp(const char *s1, const char *s2);
char *mx_strcat(char *restrict s1, const char *restrict s2);
char *mx_strstr(const char *haystack, const char *needle);
int mx_get_substr_index(const char *str, const char *sub);
int mx_count_substr(const char *str, const char *sub);
int mx_count_words(const char *str, char c);
char *mx_strnew(const int size);
char *mx_strtrim(const char *str);
int mx_isspace(char c);
char *mx_del_extra_spaces(const char *str);
char **mx_strsplit(const char *s, char c);
char *mx_strjoin(const char *s1, const char *s2);
char *mx_file_to_str(const char *file);
char *mx_replace_substr(const char *str, const char *sub, const char *replace);
int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd);
void *mx_memset(void *b, int c, size_t len);
void *mx_memcpy(void *restrict dst, const void *restrict src, size_t n);
void *mx_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
int mx_memcmp(const void *s1, const void *s2, size_t n);
void *mx_memchr(const void *s, int c, size_t n);
void *mx_memrchr(const void *s, int c, size_t n);
void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len);
void *mx_memmove(void *dst, const void *src, size_t len);
void *mx_realloc(void *ptr, size_t size);
t_list *mx_create_node(void *data);
void mx_push_front(t_list **list, void *data);
void mx_push_back(t_list **list, void *data);
void mx_pop_front(t_list **head);
void mx_pop_back(t_list **head);
int mx_list_size(t_list *list);
t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *));

int mx_atoi(char *s);
int mx_isdigit(int n);
int mx_isalpha(int c);
bool mx_isnumber(const char *str);
void mx_strshaffle(char *str);
int mx_count_lines(const char *file);
int mx_check_lines(const char *file);
void mx_copy_from_char(char *dst,const char *src, int start, char ch); 
int mx_line_compare(const char *file);
int mx_check_duplicate(const char *file);
int mx_check_b_sum(const char *file);

void add_to_intarr(int** arr, int* arr_size, int num);
void add_to_intptrarr(int*** arr, int* arr_size, int* arr_ptr);
void add_to_strarr(char*** arr, int* arr_size, char* str);
void copy_int_array(int** dst, int*src, int size);
void delete_int_array(int*** arr, int arr_size);
void delete_str_array(char*** arr, int arr_size);
int mx_read_line_buff(char **lineptr, size_t buf_size, char delim, const int fd, bool cleanBuffer);
int pathfinder_atoi(const char *str);
bool is_arr_cont_int(int* arr, int arr_size, int num);
void int_quicksort(int **arr, int left, int right);
char *mx_strchr(const char *s, int c);

#endif



