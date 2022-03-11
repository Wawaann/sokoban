/*
** EPITECH PROJECT, 2021
** swap
** File description:
** Inverse les valeurs de a et b.
*/

void my_swap(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;
}
