/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "../include/my.h"

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr = malloc(sizeof(char *) * nb_rows);

    for (int i = 0; i < nb_rows; i++) {
        arr[i] = malloc(nb_cols + 1);
    }
    return arr;
}

char **load_2d_arr_from_file(char *map, int nb_rows, int nb_cols)
{
    int c = 0;
    char **arr = mem_alloc_2d_array(nb_rows, nb_cols);

    for (; map[c] != '\n'; c++);
    c++;
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j <= nb_cols; j++) {
            if (map[c] == '\n')
                arr[i][j] = '\0';
            else
                arr[i][j] = map[c];
            c++;
        }
    }
    return arr;
}

void read_map(char *path, game_t *game)
{
    char *buffer = load_file_in_mem(path, game);
    int cols = get_col(buffer);
    int rows = get_row(buffer);
    game->map = load_2d_arr_from_file(buffer, rows, cols);
}
