/*
** EPITECH PROJECT, 2021
** init_image
** File description:
** .c
*/

#include "my_rpg.h"

anime_t init_npc(void)
{
    anime_t npc;

    npc.img = create_image(NPC);
    npc.clock = sfClock_create();
    npc.idle = (sfIntRect) {0, 0, 50, 60};
    sfSprite_setTextureRect(npc.img.spr, npc.idle);
    return npc;
}

anime_t init_boss(void)
{
    anime_t exp;

    exp.img = create_image(A_ARLONG);
    exp.clock = sfClock_create();
    exp.idle = (sfIntRect) {0, 0, 50, 90};
    exp.is_idle = true;
    sfSprite_setTextureRect(exp.img.spr, exp.idle);
    exp.img.pos = (sfVector2f) {470, 220};
    sfSprite_setPosition(exp.img.spr, exp.img.pos);
    return exp;
}

anime_t init_luffy_combat(void)
{
    anime_t luffy;

    luffy.img = create_image(A_LUFFY);
    luffy.clock = sfClock_create();
    luffy.idle = (sfIntRect) {0, 0, 50, 60};
    luffy.gatling = (sfIntRect) {200, 0, 80, 60};
    luffy.bazooka = (sfIntRect) {1262, 0, 110, 60};
    luffy.is_idle = true;
    sfSprite_setTextureRect(luffy.img.spr, luffy.idle);
    return luffy;
}

anime_t init_luffy(void)
{
    anime_t exp;

    exp.img = create_image(M_LUFFY);
    exp.clock = sfClock_create();
    exp.idle = (sfIntRect) {960, 0, 40, 60};
    exp.is_idle = true;
    exp.run_dw = (sfIntRect) {0, 0, 40, 60};
    exp.is_dw = false;
    exp.run_rg = (sfIntRect) {0, 0, 40, 60};
    exp.is_rg = false;
    exp.run_lf = (sfIntRect) {0, 0, 40, 60};
    exp.is_lf = false;
    exp.run_up = (sfIntRect) {0, 0, 40, 60};
    exp.is_up = false;
    sfSprite_setTextureRect(exp.img.spr, exp.idle);
    exp.song = sfMusic_createFromFile(MUSIC);
    sfMusic_setVolume(exp.song, 20);
    sfMusic_setLoop(exp.song, sfFalse);
    sfMusic_play(exp.song);
    return exp;
}