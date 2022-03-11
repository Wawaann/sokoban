/*
** EPITECH PROJECT, 2021
** putstr va_list
** File description:
** Putstr avec va_list
*/

#include "../include/my.h"

void va_putstr(va_list *list)
{
    my_putstr(va_arg(*list, char *));
}
