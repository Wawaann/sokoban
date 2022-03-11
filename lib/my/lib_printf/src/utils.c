/*
** EPITECH PROJECT, 2021
** Utils
** File description:
** Fonction utiles
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_put_nbr(int nb)
{
    long n = nb;
    if (n < 0) {
        my_putchar('-');
        n = n * -1;
    }
    if (n >= 10) {
        my_put_nbr(n / 10);
        my_putchar((n % 10) + '0');
    } else
        my_putchar(n + '0');
}

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}
