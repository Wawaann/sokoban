/*
** EPITECH PROJECT, 2021
** my_str_isalpha
** File description:
** Renvoie 1 si la chaîne de caractère ne contient
** que des lettres de l'alphabet, 0 sinon.
*/

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 65 && str[i] <= 90 || str[i] >= 97 && str[i] <= 122)
            i += 1;
        else
            return 0;
    }
    return 1;
}
