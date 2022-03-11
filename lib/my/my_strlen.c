/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** Renvoie la longueur de la chaîne
** de caractère.
*/

int my_strlen(char const *str)
{
    int c = 0;

    for (; str[c]; c++);
    return c;
}
