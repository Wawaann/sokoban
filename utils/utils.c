/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-mysokoban-ewan.bigotte
** File description:
** utils
*/

#include "../include/my.h"

void usage(void)
{
    my_printf("USAGE\n");
    my_printf("     ./my_sokoban map\n");
    my_printf("DESCRIPTION\n");
    my_printf("     map file representing the");
    my_printf(" warehouse map, containing '#’ for walls");
    my_printf(",\n     'P’ for the player, 'X’ for boxes and 'O’");
    my_printf("for storage locations.\n");
}

int my_arrlen(char **arr)
{
    int len = 0;

    for (; arr[len]; len++);
    return len;
}
