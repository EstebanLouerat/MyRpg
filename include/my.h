/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** .h
*/

#ifndef MY_H_
#define MY_H_
#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stddef.h>
#include <SFML/Window/Mouse.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#define bool    unsigned short int
#define true    1
#define false   0

typedef struct image_s
{
    sfSprite *spr;
    sfTexture *tx;
    sfVector2f pos;
    sfVector2f size;
}image_t;

typedef struct diag_s
{
    char **diag;
    sfText *txt;
    int ep;
}diag_t;

typedef struct anime_s
{
    image_t img;
    sfClock *clock;
    float dt;
    sfTime time;
    sfIntRect idle;
    bool is_idle;
    sfIntRect bazooka;
    bool is_bazooka;
    sfIntRect gatling;
    bool is_gatling;
    sfIntRect run_dw;
    bool is_dw;
    sfIntRect run_up;
    bool is_up;
    sfIntRect run_lf;
    bool is_lf;
    sfIntRect run_rg;
    bool is_rg;
    sfMusic *song;
}anime_t;

typedef struct combat_s
{
    image_t bg;
    image_t select;
    anime_t boss;
    float boss_life;
    anime_t luffy;
    sfRectangleShape *txt_area;
    bool is_fight;
    sfText *fight;
    sfText *attack;
    bool is_item;
    sfText *item;
    sfText *obj;
    sfText *fuite;
    sfText *stat;
    sfText *arlong;
}combat_t;

typedef struct menu_s
{
    image_t bg;
    image_t select;
    image_t select_2;
    sfText *play;
    sfText *option;
    sfText *command;
    sfText *htp;
    bool is_play;
    bool is_option;
    bool is_music;
    bool is_command;
    sfFloatRect menu_cam;
}menu_t;


typedef struct inventory_s
{
    bool is_item;
    bool is_param;
    bool is_equip;
    image_t bg;
    image_t bg_empty;
    image_t select;
    sfText *stats;
    sfText *items;
    sfText *param;
    sfText *equip;
    sfText *exit;
}inventory_t;

typedef struct game_s
{
    sfRenderWindow *w;
    sfVector2u w_size;
    sfVector2f map_size;
    sfClock *p_time;
    int sec;
    int min;
    int life;
    sfText *life_txt;
    sfText *time_txt;
    int nv;
    sfText *nv_txt;
    sfEvent e;
    sfView *cam;
    int game_lvl;
    sfFloatRect cam_rect;
    sfVector2f cam_pos;
    image_t bg;
    sfRectangleShape *perso;
    sfRectangleShape *npc_rect;
    sfRectangleShape *zone_txt;
    bool is_txt;
    sfVector2f perso_pos;
    float offset_cam;
    anime_t luffy;
    anime_t npc;
    bool on_off;
    bool is_object;
    bool is_collision;
    bool key_up;
    bool key_down;
    bool key_right;
    bool key_left;
    sfFont *font;
    int total_obj;
    bool is_indoor;
}game_t;

sfRenderWindow *create_my_window(unsigned int width,
                                unsigned height,
                                unsigned int bpp,
                                char *name);

void gameplay(game_t *game);
int my_putstr(char const *str);
char *my_itoa(int nb);
void my_putchar(char c);
bool collision(game_t *game);
char *my_strcat_f(char *s1, char *s2);
char *my_strcat_no_f(char *s1, char *s2);
char *my_strcat_f1(char *s1, char *s2);
char *my_strcat_f2(char *s1, char *s2);

#endif