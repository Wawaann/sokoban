/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** check_map
*/

#include "../include/my.h"

void verify_map(game_t *game)
{
    for (int i = 0; game->buffer[i]; i++){
        if (!check_char(game->buffer[i])) {
            game->exit = 84;
            game->exit_mes = "Wrong charactere in the map";
        }
    }
}

void check_border(game_t *game)
{
    check_line(game, 0);
    check_line(game, game->nb_rows - 1);
    check_rest(game);
}

void check_map(game_t *game)
{
    verify_map(game);
    check_box(game, game->buffer);
    check_border(game);
}
