/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** player
*/

#include "../include/my.h"

int get_x(game_t *game)
{
    int i = 0, j = 0;

    for (; game->map[i][j]; j++) {
        if (game->map[i][j] == 'P')
            break;
        if (j == game->nb_cols - 1) {
            i++;
            j = 0;
        }
    }
    return j;
}

int get_y(game_t *game)
{
    int i = 0, j = 0;

    for (; game->map[i][j]; j++) {
        if (game->map[i][j] == 'P')
            break;
        if (j == game->nb_cols - 1) {
            i++;
            j = 0;
        }
    }
    return i;
}

void get_player_coord(game_t *game)
{
    int x = get_x(game);
    int y = get_y(game);
    game->player->x = x;
    game->player->y = y;
    game->player->begx = x;
    game->player->begy = y;
    game->map[y][x] = ' ';
}

bool can_move(game_t *game, int x, int y, int move)
{
    node_t *tmp = game->box->begin;

    for (; tmp; tmp = tmp->next) {
        if (x == tmp->x && y == tmp->y) {
            if (box_can_move(game, x, y, move)) {
                move_box(tmp, x, y, move);
                return true;
            }
        return false;
        }
    } if (game->map[y][x] != '#') {
        return true;
    }
    return false;
}

void move_player(game_t *game, int ch)
{
    int move;
    if (ch == KEY_UP) {
        move = 1;
        if (can_move(game, game->player->x, game->player->y - 1, move))
            game->player->y--;
    } if (ch == KEY_DOWN) {
        move = 2;
        if (can_move(game, game->player->x, game->player->y + 1, move))
            game->player->y++;
    } if (ch == KEY_RIGHT) {
        move = 3;
        if (can_move(game, game->player->x + 1, game->player->y, move))
            game->player->x++;
    } if (ch == KEY_LEFT) {
        move = 4;
        if (can_move(game, game->player->x - 1, game->player->y, move))
            game->player->x--;
    }
}
