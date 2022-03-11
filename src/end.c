/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-mysokoban-ewan.bigotte
** File description:
** end
*/

#include "../include/my.h"

bool box_border(char **map, node_t *tmp)
{
    if (map[tmp->y - 1][tmp->x] == '#' && map[tmp->y][tmp->x - 1] == '#')
        return true;
    if (map[tmp->y - 1][tmp->x] == '#' && map[tmp->y][tmp->x + 1] == '#')
        return true;
    if (map[tmp->y + 1][tmp->x] == '#' && map[tmp->y][tmp->x - 1] == '#')
        return true;
    if (map[tmp->y + 1][tmp->x] == '#' && map[tmp->y][tmp->x + 1] == '#')
        return true;
    return false;
}

bool lose(game_t *game)
{
    int c = 0;
    node_t *tmp = game->box->begin;

    for (; tmp; tmp = tmp->next) {
        if (box_border(game->map, tmp))
            c++;
    }
    if (c == game->box->len)
        return true;
    return false;
}

bool win(game_t *game)
{
    int c = 0;
    node_t *tmp = game->box->begin;

    for (int i = 0; tmp; tmp = tmp->next) {
        if (game->map[tmp->y][tmp->x] == 'O')
            c++;
    }
    if (c == game->box->len)
        return true;
    return false;
}

bool end(game_t *game)
{
    if (win(game)) {
        game->running = false;
        game->exit = 0;
    } else if (lose(game)) {
        game->running = false;
        game->exit = 1;
    }
}
