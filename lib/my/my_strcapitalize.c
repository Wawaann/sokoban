/*
** EPITECH PROJECT, 2021
** my_strcapitalize
** File description:
** Met des majuscules au début de chaque mot.
*/

#include <stdio.h>

char *my_strlowcase(char *str);

int testn(char ch)
{
    if (ch < 48 && ch > 57)
        return 1;
    return 0;
}

int testc(char ch)
{
    if (ch >= 23 && ch <= 47)
        return 1;
    return 0;
}

char change_char(char ch)
{
    if (ch >= 'a' && ch <= 'z')
        ch -= 32;
    return ch;
}

char *my_strcapitalize(char *str)
{
    int i = 1;

    my_strlowcase(str);
    if (str[0] >= 97 && str[0] <= 122)
        str[0] = str[0] - 32;
    while (str[i] != '\0') {
        if (testc(str[i - 1]) == 1 || str[i - 1] <= ';'
            && testn(str[i - 1]) == 1)
            str[i] = change_char(str[i]);
        i += 1;
    }
    return str;
}
