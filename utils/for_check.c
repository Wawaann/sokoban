/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** for_check
*/

#include "../include/my.h"

void check_box(game_t *game, char *buffer)
{
    int box = 0;
    int target = 0;
    int player = 0;

    for (int i = 0; buffer[i]; i++) {
        if (buffer[i] == 'X')
            box++;
        if (buffer[i] == 'O')
            target++;
        if (buffer[i] == 'P')
            player++;
    } if (player != 1) {
        game->exit = 84;
        game->exit_mes = "Ereeror with the player";
    } if (box != target) {
        game->exit = 84;
        game->exit_mes = "Wrong map";
    }
}

void check_line(game_t *game, int x)
{
    for (int i = 0; game->map[x][i]; i++) {
        if (game->map[x][i] != '#') {
            game->exit = 84;
            game->exit_mes = "Wrong map";
        }
    }
}

void check_rest(game_t *game)
{
    for (int i = 1; i < game->nb_rows; i++) {
        if (game->map[i][0] != '#' || game->map[i][game->nb_cols - 1] != '#') {
            game->exit = 84;
            game->exit_mes = "Wrong map";
        }
    }
}

bool check_char(char ch)
{
    char *good = " #XOP\n";
    for (int i = 0; good[i]; i++) {
        if (ch == good[i])
            return true;
    }
    return false;
}
