/*
** EPITECH PROJECT, 2022
** sources
** File description:
** utils2
*/

#include "../include/my.h"

void my_put_adress(long long nb)
{
    my_put_hexa(nb, 'x');
}

char *my_revstr (char *str)
{
    int i = 0;
    int end = my_strlen(str) - 1;
    char temp;

    while (i < end) {
        temp = str[i];
        str[i] = str[end];
        str[end] = temp;
        i += 1;
        end -= 1;
    }
    return str;
}