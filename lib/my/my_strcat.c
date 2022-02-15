/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** Rassemble deux chaîne de caractère en une.
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int a = my_strlen(dest);
    int i = 0;

    while (src[i] != '\0') {
        dest[a + i] = src[i];
        i += 1;
    }
    dest[a + i] = '\0';
    return dest;
}
