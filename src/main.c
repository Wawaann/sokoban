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
    game->error = 0;
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
    for (int i = 0; game->map[i]; i++)
        printw("%s\n", game->map[i]);
}

int main(int ac, char **av)
{
    game_t *game = init_game();
    read_map(av[1], game);
    initscr();
    cbreak();
    noecho();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    noecho();
    while (game->running) {
        refresh();
        display_map(game);
        game_loop(game);
    }
    endwin();
    return 0;
}

