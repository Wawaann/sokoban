/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-mysokoban-ewan.bigotte
** File description:
** free_mem
*/

#include "../include/my.h"

void free_box(game_t *game)
{
    node_t *tmp = game->box->begin;
    node_t *next;

    while (tmp) {
        next = tmp->next;
        free(tmp);
        tmp = next;
    }
}

void free_mem(game_t *game)
{
    free(game->buffer);
    free(game->player);
    for (int i = 0; i < game->nb_rows - 1; i++) {
        free(game->map[i]);
        free(game->map_cpy[i]);
    }
    free(game->map);
    free(game->map_cpy);
    free_box(game);
    free(game->box);
}
