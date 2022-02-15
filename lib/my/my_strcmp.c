/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** Renvoie la différence entre deux str.
*/

int my_strcmp(char const *s1, char const *s2)
{
    int n = 0;

    while (s1[n] == s2[n] && s1[n] != '\0' && s2[n] != '\0')
        n += 1;
    return s1[n] - s2[n];
}
