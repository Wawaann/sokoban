/*
** EPITECH PROJECT, 2021
** my_putchar
** File description:
** Affiche un caractère.
*/

#include <unistd.h>

char my_putchar(char c)
{
    write(1, &c, 1);
}
