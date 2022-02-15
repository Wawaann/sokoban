/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** Donne la racine carré de nb.
*/

int my_compute_square_root(int nb)
{
    int a = 0;

    if (nb <= 0)
        return 0;
    while (a * a != nb) {
        a += 1;
        if (a > nb)
            return 0;
    }
    return a;
}
