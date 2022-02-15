/*
** EPITECH PROJECT, 2021
** my_strncpy
** File description:
** Renvoie une copie de n caractère d'une
** chaîne de caractère.
*/

char *my_strncpy(char *dest, char *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i = i + 1;
    }
    if (i + 1 == n)
        dest[i] = '\0';
    return dest;
}
