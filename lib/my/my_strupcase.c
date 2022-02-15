/*
** EPITECH PROJECT, 2021
** my_strupcase
** File description:
** Met tout en maj.
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 97 && str[i] <= 122) {
            str[i] = str[i] - 32;
            i += 1;
        } else
            i += 1;
    }
    return str;
}
