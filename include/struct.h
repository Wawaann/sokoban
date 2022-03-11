/*
** EPITECH PROJECT, 2022
** B-PSU-200-NCE-2-1-mysokoban-ewan.bigotte
** File description:
** struct
*/

#include <ncurses.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <unistd.h>

#ifndef STRUCT_H_
    #define STRUCT_H_

typedef struct player_s {
    int move;
    int x;
    int y;
    int begx;
    int begy;
} player_t;

typedef struct node_s {
    int x;
    int y;
    int begx;
    int begy;
    struct node_s *next;
} node_t;

typedef struct box_s {
    int len;
    node_t *begin;
    node_t *end;
} box_t;

typedef struct game_s {
    char *buffer;
    char **map;
    char **map_cpy;
    bool running;
    int nb_cols;
    int nb_rows;
    int exit;
    char *exit_mes;
    player_t *player;
    box_t *box;
} game_t;

#endif /* !STRUCT_H_ */
