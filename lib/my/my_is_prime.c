/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** Renvoie 1 si nb est premier, 0 sinon.
*/

int my_is_prime(int nb)
{
    for (int i = 2; i < nb; i += 1) {
        if (nb % i == 0)
            return 0;
    }
    return 1;
}