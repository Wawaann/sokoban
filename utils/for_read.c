/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** for_read
*/

#include "../include/my.h"

int fs_open_file(char const *filepath, game_t *game)
{
    int fd = open(filepath, O_RDONLY);
    if (fd == -1) {
        my_putstr("Fail to open the file.\n");
        game->exit = 84;
    }
    return fd;
}

char **mem_alloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr = malloc(sizeof(char *) * (nb_rows + 1));

    for (int i = 0; i < nb_rows; i++) {
        arr[i] = malloc(nb_cols + 1);
    }
    arr[nb_rows] = NULL;
    return arr;
}

int get_row(char const *map)
{
    int res = 0;

    for (int i = 0; map[i]; i++) {
        if (map[i] == '\n')
            res++;
    }
    return res;
}

int get_col(char const *map)
{
    int n = 0, c = 0;
    int result = 0;
    char *buf = malloc(my_strlen(map));

    for (; map[n] != '\n'; n++);
    n++;
    for (; map[n] != '\n'; n++) {
        buf[c] = map[n];
        c++;
    }
    buf[c] = '\0';
    result = my_strlen(buf);
    free(buf);
    return result;
}
