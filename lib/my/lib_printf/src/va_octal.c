/*
** EPITECH PROJECT, 2021
** Octal
** File description:
** octal va_list
*/

#include "../include/my.h"

void my_put_octal(long long nb)
{
    long long tmp = nb;
    int i = 0, n = 0;
    char *truc = malloc(sizeof(char) * 8);
    char *res;

    while (tmp > 0) {
        i++;
        tmp /= 8;
    }
    truc = "01234567";
    res = malloc(i);
    res[i] = '\0';
    while (i > 0) {
        n = nb % 8;
        nb /= 8;
        res[i - 1] = truc[n];
        i--;
    }
    my_putstr(res);
}

void va_octal(va_list *list)
{
    my_put_octal(va_arg(*list, long long));
}
