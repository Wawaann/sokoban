/*
** EPITECH PROJECT, 2021
** Unsigned int
** File description:
** unsigned int avec va
*/

#include "../include/my.h"

void put_unsi_nbr(unsigned int nb)
{
    long n = nb;

    if (n >= 10) {
        my_put_nbr(n / 10);
        my_putchar((n % 10) + '0');
    } else
        my_putchar(n + '0');
}

void va_unsinbr(va_list *list)
{
    put_unsi_nbr(va_arg(*list, unsigned int));
}
