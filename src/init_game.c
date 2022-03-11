/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-mysokoban-ewan.bigotte
** File description:
** init_game
*/

#include "../include/my.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->player = malloc(sizeof(player_t));
    game->map_cpy = malloc(1);
    game->box = init_box();
    game->running = true;
    game->exit = 0;
    game->nb_cols = 0;
    game->nb_rows = 0;
    return game;
}
