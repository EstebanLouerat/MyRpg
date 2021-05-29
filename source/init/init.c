/*
** EPITECH PROJECT, 2021
** init
** File description:
** .c
*/

#include "my_rpg.h"

sfRectangleShape *init_hitbox(sfVector2f pos,
                            sfVector2f size,
                            sfBool is_visible)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setSize(rect, size);
    sfRectangleShape_setOrigin(rect, (sfVector2f) {size.x / 7, size.y / 7});
    if (is_visible)
        sfRectangleShape_setFillColor(rect, (sfColor) {0, 255, 0, 150});
    else
        sfRectangleShape_setFillColor(rect, (sfColor) {0, 0, 0, 0});
    sfRectangleShape_setPosition(rect, pos);
}

sfRectangleShape *init_txt_area(void)
{
    sfRectangleShape *area = sfRectangleShape_create();

    sfRectangleShape_setFillColor(area, sfBlack);
    sfRectangleShape_setPosition(area, (sfVector2f) {260, 345});
    sfRectangleShape_setSize(area, (sfVector2f) {280, 100});
    return area;
}

game_t init_struct_suite_suite(game_t *prm)
{
    prm->is_collision = false;
    prm->time_txt = sfText_create();
    sfText_setPosition(prm->time_txt, (sfVector2f) {80, 110});
    sfText_setFont(prm->time_txt, prm->font);
    sfText_setColor(prm->time_txt, sfWhite);
    sfText_setScale(prm->time_txt, (sfVector2f) {.5f, .5f});
    sfText_setLetterSpacing(prm->time_txt, .5f);
    sfText_setCharacterSize(prm->time_txt, 30);
    sfText_setString(prm->time_txt, "0 m 0 s");
    prm->is_indoor = false;
}

game_t init_struct_suite(game_t *prm)
{
    prm->key_down = false;
    prm->key_left = false;
    prm->key_up = false;
    prm->key_right = false;
    prm->life_txt = sfText_create();
    sfText_setPosition(prm->life_txt, (sfVector2f) {-100, 100});
    sfText_setFont(prm->life_txt, prm->font);
    sfText_setColor(prm->life_txt, sfWhite);
    sfText_setScale(prm->life_txt, (sfVector2f) {.5f, .5f});
    sfText_setLetterSpacing(prm->life_txt, .5f);
    sfText_setCharacterSize(prm->life_txt, 30);
    sfText_setString(prm->life_txt, "100\n/ 100");
    prm->nv_txt = sfText_create();
    sfText_setPosition(prm->nv_txt, (sfVector2f) {-90, 75});
    sfText_setFont(prm->nv_txt, prm->font);
    sfText_setColor(prm->nv_txt, sfWhite);
    sfText_setScale(prm->nv_txt, (sfVector2f) {.5f, .5f});
    sfText_setCharacterSize(prm->nv_txt, 30);
    sfText_setString(prm->nv_txt, "1");
    init_struct_suite_suite(prm);
}

game_t init_struct(void)
{
    game_t prm;

    prm.w = create_my_window(800, 600, 32, "Test");
    prm.w_size = sfRenderWindow_getSize(prm.w);
    prm.perso_pos = (sfVector2f) {200, 300};
    prm.cam_rect = (sfFloatRect) {0, 0, 300, 300};
    prm.cam = sfView_createFromRect(prm.cam_rect);
    prm.offset_cam = 1;
    prm.on_off = false;
    prm.is_txt = false;
    prm.is_object = false;
    prm.life = 100;
    prm.life_txt = sfText_create();
    prm.nv = 1;
    prm.nv_txt = sfText_create();
    prm.map_size = (sfVector2f) {500, 500};
    prm.font = sfFont_createFromFile(FONT);
    init_struct_suite(&prm);
    return prm;
}