/*
** EPITECH PROJECT, 2021
** my_str_isprintable.c
** File description:
** Renvoie 1 si la chaîne de caractère ne
** contient que des caractère affichable,
** 0 sinon.
*/

int my_str_isprintable(char const *str)
{
    int	i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 32 && str[i] < 127)
            i += 1;
        else
            return 0;
    }
    return 1;
}
