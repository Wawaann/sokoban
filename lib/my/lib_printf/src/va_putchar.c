/*
** EPITECH PROJECT, 2021
** putchar va
** File description:
** Le putchar avec va
*/

#include "../include/my.h"

void va_putchar(va_list *list)
{
    char c = va_arg(*list, int);
    my_putchar(c);
}