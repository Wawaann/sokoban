/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-mysokoban-ewan.bigotte
** File description:
** event
*/

#include "../include/my.h"

void reset_game(game_t *game)
{
    node_t *tmp = game->box->begin;

    for (; tmp; tmp = tmp->next) {
        tmp->x = tmp->begx;
        tmp->y = tmp->begy;
    }
    game->player->x = game->player->begx;
    game->player->y = game->player->begy;
}

void game_loop(game_t *game)
{
    int ch = getch();
    erase();
    if (ch == 'q')
        game->running = false;
    if (ch == ' ')
        reset_game(game);
    move_player(game, ch);
}
