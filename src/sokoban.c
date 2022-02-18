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
    move_player(game->player, ch);
}

void update_map(game_t *game)
{
    int x = get_x(game);
    int y = get_y(game);
    game->map[y][x] = ' ';
    game->map[game->player->y][game->player->x] = 'P';
}

void display_map(game_t *game)
{
    refresh();
    printw("x : %d; y : %d\n", game->player->x, game->player->y);
    update_map(game);
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
    get_player_coord(game);
    display_map(game);
    if (game->exit == 84) {
        my_printf("%s\n", game->exit_mes);
        return game->exit;
    }
    launch_game(game);
    return game->exit;
}
