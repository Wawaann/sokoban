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
        game->error = 84;
    }
    return fd;
}

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
    return result;
}
