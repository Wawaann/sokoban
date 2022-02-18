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
    game->player->x = get_x(game);
    game->player->y = get_y(game);
}

bool can_move()

void move_player(player_t *player, int ch)
{
    if (ch == KEY_UP)
        player->y--;
    if (ch == KEY_DOWN)
        player->y++;
    if (ch == KEY_RIGHT)
        player->x++;
    if (ch == KEY_LEFT)
        player->x--;
}