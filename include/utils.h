/*
** EPITECH PROJECT, 2025
** mysh1
** File description:
** utils.h
*/

#ifndef UTILS_H_
    #define UTILS_H_

void free_array(char **arr);

char **str_split(char *str, char separator);
void my_putstr(char *str, int canal);
int my_strlen(char *str);
char *my_itoa(int n);
char *my_strdup(char const *src);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strndup(char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *read_file(char *file);
int array_count(char **arr);
int my_getnbr(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
void my_put_hex(unsigned long value, int width, int canal);
void my_putnbr(int nb, int canal);

#endif
