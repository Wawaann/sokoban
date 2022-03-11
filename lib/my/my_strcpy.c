/*
** EPITECH PROJECT, 2021
** my_strcpy
** File description:
** fonction qui copy un str
*/

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src)
{
    int x = my_strlen(src);

    dest[x];
    for (int i = 0; i <= x; i += 1) {
        dest[i] = src[i];
    }
    return dest;
}
