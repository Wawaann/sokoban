/*
** EPITECH PROJECT, 2021
** my_str_isnum
** File description:
** Renvoie 1 si la chaîne de caractère ne
** contient que des chiffre, 0 sinon.
*/

int my_str_isnum(char const *str)
{
    int	i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 48 && str[i] <= 57)
            i += 1;
        else
            return 0;
    }
    return 1;
}