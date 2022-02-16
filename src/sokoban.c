/*
** EPITECH PROJECT, 2021
** sources [WSL: Arch]
** File description:
** main
*/

#include "../include/my.h"

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    game->player = malloc(sizeof(player_t));
    game->running = true;
    game->exit = 0;
    game->nb_cols = 0;
    game->nb_rows = 0;
    return game;
}

void game_loop(game_t *game)
{
    int ch = getch();
    erase();
    if (ch == 'q')
        game->running = false;
    if (ch == KEY_UP)
        printw("UP\n");
    if (ch == KEY_DOWN)
        printw("DOWN\n");
    if (ch == KEY_RIGHT)
        printw("RIGHT\n");
    if (ch == KEY_LEFT)
        printw("LEFT\n");
}

void display_map(game_t *game)
{
    refresh();
    for (int i = 0; game->map[i]; i++)
        printw("%s\n", game->map[i]);
}

void launch_game(game_t *game)
{
    initscr();
    cbreak();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    noecho();
    while (game->running) {
        display_map(game);
        game_loop(game);
    }
    endwin();
}

int main(int ac, char **av)
{
    game_t *game = init_game();
    read_map(av[1], game);
    check_map(game);
    if (game->exit == 84) {
        my_printf("%s\n", game->exit_mes);
        return game->exit;
    }
    launch_game(game);
    return game->exit;
}
