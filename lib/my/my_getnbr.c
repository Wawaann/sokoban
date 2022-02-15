/*
** EPITECH PROJECT, 2021
** my_getnbr
** File description:
** Extrait un nombre d'une chaîne de caractère.
*/

int my_char_isnum(char c)
{
    if (c >= '9' || c <= '0')
        return 0;
    return 1;
}

int my_getnbr(char const *str)
{
    long var = 0;
    int neg = 1, i = 0;

    for (; (str[i] < '0' || str[i] > '9') && str[i] != '\0'; i++) {
        if  (str[i] == '-' && my_char_isnum(str[i + 1]) == 1)
            neg = -1;
    }
    for (; str[i] != 0 && str[i] >= '0' && str[i] <= '9'; i++) {
        var *= 10;
        var = var + str[i] - 48;
    }
    var *= neg;
    if (var >= 2147483647 || var <= -2147483647)
        return 0;
    return var;
}
