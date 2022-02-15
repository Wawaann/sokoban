/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** Rassemble deux chaîne de caractère jusqu'à n caractère.
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int nb)
{
    int a = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0' && i < nb) {
        dest[a + i] = src[i];
        i += 1;
    }
    dest[a + i] = '\0';
    return dest;
}
