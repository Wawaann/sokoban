/*
** EPITECH PROJECT, 2021
** my_isneg
** File description:
** Renvoie N si nb est négatif, P sinon.
*/

char my_putchar(char c);

void my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else
        my_putchar('P');
}
