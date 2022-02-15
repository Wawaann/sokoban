/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** Affiche un nombre.
*/

char my_putchar(char c);

int my_put_nbr(int nb)
{
    long n = 0;

    if (nb < 0) {
        my_putchar(45);
        nb = nb * -1;
    }
    if (nb > 9) {
        n = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(n + 48);
    } else
        my_putchar(nb + 48);
    return 0;
}
