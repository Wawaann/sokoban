/*
** EPITECH PROJECT, 2021
** my_str_isupper
** File description:
** Renvoie 1 si la chaîne de caractère ne
** contient que des majuscules, 0 sinon.
*/

int my_str_isupper(char const *str)
{
    int	i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90)
            i += 1;
        else
            return 0;
    }
    return 1;
}
