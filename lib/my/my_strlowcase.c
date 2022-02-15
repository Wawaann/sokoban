/*
** EPITECH PROJECT, 2021
** my_lowcase
** File description:
** Met tout les caractère d'une
** chaîne de caractère en minuscule.
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90) {
            str[i] = str[i] + 32;
            i += 1;
        } else
            i += 1;
    }
    return str;
}
