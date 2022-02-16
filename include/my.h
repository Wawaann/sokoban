/*
** EPITECH PROJECT, 2021
** my_header
** File description:
** Biblihotèque contenant tous les prototypes des fonctions
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

#ifndef MY
    #define MY

//:::::::::: Structure :::::::::::

typedef struct player_s {
    int x;
    int y;
} player_t;

typedef struct game_s {
    char *buffer;
    char **map;
    bool running;
    int exit;
    int nb_cols;
    int nb_rows;
    char *exit_mes;
    player_t *player;
} game_t;

//:::::::::: Fonction lib ::::::::::
char my_putchar(char c);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char *src, int n);
char *my_strstr(char *str, char *to_find);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
int my_compute_power_rec(int nb, int p);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_getnbr(char const *str);
int my_is_prime(int nb);
int my_put_nbr(int nb);
int my_showmen(char const *str, int size);
int my_showstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_str_isupper(char const *str);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
int testc(char const *str, int i);
int testn(char const *str, int i);
void my_putstr(char const *str);
void my_isneg(int n);
void my_sort_int_array(int *array, int size);
void my_swap(int *a, int *b);

//:::::::::: Fonction lib my_printf ::::::::::
void my_printf(char *s, ...);

//:::::::::: Utils ::::::::::
int fs_open_file(char const *filepath, game_t *game);
char *load_file_in_mem(char const *filepath, game_t *game);
int get_row(char const *map);
int get_col(char const *map);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
char **load_2d_arr_from_file(char *map, int nb_rows, int nb_cols);
void read_map(char *path, game_t *game);
void check_map(game_t *game);
void check_box(game_t *game, char *buffer);
void check_line(game_t *game, int x);
void check_rest(game_t *game);
bool check_char(char ch);

#endif
