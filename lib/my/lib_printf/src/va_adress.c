/*
** EPITECH PROJECT, 2021
** my_put_adress
** File description:
** Affiche les adresses
*/

#include "../include/my.h"
#include <stdarg.h>

void va_adress(va_list *list)
{
    my_putstr("0x");
    my_put_hexa(va_arg(*list, long long), 'x');
}
