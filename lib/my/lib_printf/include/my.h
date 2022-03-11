/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** Functions prototypes of my lib.
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <dirent.h>

#ifndef MY
    #define MY

//::::::::::::::::Basic lib functions::::::::::::::::
void my_putchar(char c);
void my_put_nbr(int nb);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
char *my_revstr(char *str);
void my_put_adress(long long nb);
void my_put_octal(long long nb);
void my_put_hexa(long long nb, char ch);
char *my_int_to_str(int nb);

//::::::::::::::: Fonction va_list :::::::::::::::7
void va_putchar(va_list *list);
void va_putstr(va_list *list);
void va_nbr(va_list *list);
void va_unsinbr(va_list *list);
void va_bin(va_list *list);
void va_octal(va_list *list);
void va_hexa_min(va_list *list);
void va_hexa_maj(va_list *list);
void va_adress(va_list *list);
void va_printable(va_list *list);
void va_putpercent(va_list *list);

//:::::::::: Fonction my_printf :::::::::::::::::
void my_printf(char *s, ...);

void my_ls(DIR *dir);

#endif
