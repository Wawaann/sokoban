/*
** EPITECH PROJECT, 2021
** my_header
** File description:
** Biblihotèque contenant tous les prototypes des fonctions
*/

#include "struct.h"

#ifndef MY
    #define MY

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

// :::::::::: SRC ::::::::::
game_t *init_game(void);
char *load_file_in_mem(char const *filepath, game_t *game);
char **load_2d_arr_from_file(char *map, int nb_rows, int nb_cols);
void read_map(char *path, game_t *game);
void check_map(game_t *game);
void get_player_coord(game_t *game);
void move_player(game_t *game, int ch);
int get_x(game_t *game);
int get_y(game_t *game);
box_t *init_box(void);
void get_box_coord(game_t *game);

//:::::::::: Utils ::::::::::
int fs_open_file(char const *filepath, game_t *game);
int get_row(char const *map);
int get_col(char const *map);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
void check_box(game_t *game, char *buffer);
void check_line(game_t *game, int x);
void check_rest(game_t *game);
bool check_char(char ch);
void display_box(game_t *game);
void usage(void);
int my_arrlen(char **arr);
void free_mem(game_t *game);
void cp_map(game_t *game);
bool box_can_move(game_t *game, int x, int y, int move);
void move_box(node_t *tmp, int x, int y, int move);
bool end(game_t *game);
void reset_game(game_t *game);
void game_loop(game_t *game);

#endif
