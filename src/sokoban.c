/*
** EPITECH PROJECT, 2021
** sources [WSL: Arch]
** File description:
** main
*/

#include "../include/my.h"

void update_map(game_t *game)
{
    node_t *tmp = game->box->begin;
    for (; tmp; tmp = tmp->next)
        game->map_cpy[tmp->y][tmp->x] = 'X';
    game->map_cpy[game->player->y][game->player->x] = 'P';
}

void display_map(game_t *game)
{
    int ymax, xmax, ybeg, xbeg;
    int x, y;
    getmaxyx(stdscr, ymax, xmax);
    getbegyx(stdscr, ybeg, xbeg);
    refresh();
    update_map(game);
    if (xmax < my_strlen(game->map[0]) || ymax < my_arrlen(game->map))
            printw("Elarge the terminale pls\n");
    else {
        for (int i = 0; game->map[i]; i++, ybeg++) {
                x = (xbeg + xmax / 2) - game->nb_cols / 2;
                y = (ybeg + ymax / 2) - game->nb_rows / 2;
                mvprintw(y, x, "%s\n", game->map_cpy[i]);
        }
    }
}

void launch_game(game_t *game)
{
    initscr();
    cbreak();
    intrflush(stdscr, FALSE);
    keypad(stdscr, TRUE);
    noecho();
    while (game->running) {
        cp_map(game);
        display_map(game);
        game_loop(game);
        end(game);
    }
    endwin();
}

int main(int ac, char **av)
{
    game_t *game = init_game();
    if (ac != 2) {
        my_printf("Wrong arguments\n");
        return 84;
    } else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        usage();
        return 0;
    } else {
        read_map(av[1], game);
        check_map(game);
        get_player_coord(game);
        get_box_coord(game);
        if (game->exit == 84)
            my_printf("%s\n", game->exit_mes);
        else
            launch_game(game);
    }
    free_mem(game);
    return game->exit;
}
