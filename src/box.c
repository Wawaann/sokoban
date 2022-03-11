/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-mysokoban-ewan.bigotte
** File description:
** box
*/

#include "../include/my.h"

box_t *init_box(void)
{
    box_t *list = malloc(sizeof(box_t));
    list->len = 0;
    list->begin = NULL;
    list->end = NULL;
    return list;
}

void push_back(box_t *box, int x, int y)
{
    node_t *node = malloc(sizeof(node_t));

    node->x = x;
    node->y = y;
    node->begx = x;
    node->begy = y;
    node->next = NULL;
    if (box->begin == NULL) {
        box->begin = node;
        box->end = node;
    } else {
        box->end->next = node;
        box->end = box->end->next;
    }
    box->len++;
}

void get_box_coord(game_t *game)
{
    int i = 0;
    int j = 0;

    for (; game->map[i][j]; j++) {
        if (game->map[i][j] == 'X') {
            push_back(game->box, j, i);
            game->map[i][j] = ' ';
        }
        if (j == game->nb_cols - 1) {
            i++;
            j = 0;
        } if (i == game->nb_rows)
            break;
    }
}

bool box_can_move(game_t *game, int x, int y, int move)
{
    if (move == 1 && game->map[y - 1][x] != '#' && game->map[y - 1][x] != 'X')
        return true;
    if (move == 2 && game->map[y + 1][x] != '#' && game->map[y - 1][x] != 'X')
        return true;
    if (move == 3 && game->map[y][x + 1] != '#' && game->map[y - 1][x] != 'X')
        return true;
    if (move == 4 && game->map[y][x - 1] != '#' && game->map[y - 1][x] != 'X')
        return true;
    return false;
}

void move_box(node_t *tmp, int x, int y, int move)
{
    if (move == 1)
        tmp->y--;
    if (move == 2)
        tmp->y++;
    if (move == 3)
        tmp->x++;
    if (move == 4)
        tmp->x--;
}
