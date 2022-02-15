/*
** EPITECH PROJECT, 2021
** disp_stdarg
** File description:
** Je sais pas ce qu sais
*/

#include "../include/my.h"
#include  <stdio.h>

int isgood(char ch)
{
    char good[] = "csdbSiluopuxX%";

    for (int i = 0; i < my_strlen(good); i++) {
        if (ch == good[i]) {
            return 1;
        }
    }
    return 0;
}

int get_flag(char c)
{
    int i = 0;
    char flag[] = "csdiuxXbopS%";

    for (; flag[i] != c; i++);
    return i;
}

void my_printf(char *s, ...)
{
    va_list list;

    va_start(list, *s);
    void(*t_ptrf[])(va_list *list) = {va_putchar, va_putstr, va_nbr
    , va_nbr, va_unsinbr, va_hexa_min, va_hexa_maj
    , va_bin, va_octal, va_adress, va_printable, va_putpercent};

    for (int i = 0; i < my_strlen(s); i++) {
        if (s[i] == '%' && isgood(s[i + 1]) == 1) {
            t_ptrf[get_flag(s[i + 1])](&list);
            i++;
        }
        else
            my_putchar(s[i]);
    }
    va_end(list);
}
