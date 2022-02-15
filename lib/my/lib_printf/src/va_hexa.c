/*
** EPITECH PROJECT, 2021
** my_put_hexa
** File description:
** Affiche un nombre en hexadecimal
*/

#include "../include/my.h"
#include <stdarg.h>
#include <stdio.h>

#include "../include/my.h"

void my_put_hexa(long long nb, char ch)
{
    long long tmp = nb;
    int i = 0, n = 0;
    char *res;
    char *truc = malloc(15);

    if (ch == 'x')
        truc = "0123456789abcdef";
    else
        truc = "0123456789ABCDEF";
    for (; tmp > 0; i++)
        tmp /= 16;
    res = malloc(i);
    res[i] = '\0';
    for (; i > 0; i--) {
        n = nb % 16;
        nb /= 16;
        res[i - 1] = truc[n];
    }
    my_putstr(res);
}

void va_hexa_min(va_list *list)
{
    my_put_hexa(va_arg(*list, int), 'x');
}

void va_hexa_maj(va_list *list)
{
    my_put_hexa(va_arg(*list, int), 'X');
}

