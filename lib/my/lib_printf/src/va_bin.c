/*
** EPITECH PROJECT, 2021
** Bin va
** File description:
** Bin va list
*/

#include "../include/my.h"

void my_put_binair(long long nb)
{
    long long tmp = nb;
    int i = 0, n = 0;
    char *truc = malloc(sizeof(char) * 8);
    char *res;

    while (tmp > 0) {
        i++;
        tmp /= 2;
    }
    truc = "01";
    res = malloc(i);
    res[i] = '\0';
    while (i > 0) {
        n = nb % 2;
        nb /= 2;
        res[i - 1] = truc[n];
        i--;
    }
    my_putstr(res);
}

void va_bin(va_list *list)
{
    my_put_binair(va_arg(*list, long long));
}
