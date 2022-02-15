/*
** EPITECH PROJECT, 2021
** my_find_prime_sup
** File description:
** Donne le nombre premier superieur le plus proche
** de nb, si nb n'est pas premier.
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1)
        return nb;
    while (my_is_prime(nb) == 0)
        nb += 1;
    return nb;
}
