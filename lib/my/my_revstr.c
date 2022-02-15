/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** Inverse un str
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int d = 0;
    int f = my_strlen(str) - 1;
    char swap;

    while (d < f) {
        swap = str[d];
        str[d] = str[f];
        str[f] = swap;
        d += 1;
        f -= 1;
    }
    return str;
}
