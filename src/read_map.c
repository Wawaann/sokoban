/*
** EPITECH PROJECT, 2021
** utils
** File description:
** utils
*/

#include "../include/my.h"

char *load_file_in_mem(char const *filepath, game_t *game)
{
    int fd = fs_open_file(filepath, game);
    struct stat st;
    stat(filepath, &st);
    int size = st.st_size + 1;
    char *buf = malloc(size);
    read(fd, buf, size);
    buf[size - 1] = '\0';
    return buf;
}

char **load_2d_arr_from_file(char *map, int nb_rows, int nb_cols)
{
    int c = 0;
    char **arr = mem_alloc_2d_array(nb_rows, nb_cols);

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
    game->buffer = load_file_in_mem(path, game);
    game->nb_cols = get_col(game->buffer);
    game->nb_rows = get_row(game->buffer);
    game->map = load_2d_arr_from_file(game->buffer, game->nb_rows, game->nb_cols);
}
