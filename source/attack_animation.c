/*
** EPITECH PROJECT, 2021
** B-MUL-200-LYN-2-1-myrpg-fabien.giraudier
** File description:
** attack_animation
*/

#include "my_rpg.h"

void anim_arlong_attcak(game_t *game, combat_t *ftg)
{
    ftg->boss.time = sfClock_getElapsedTime(ftg->boss.clock);
    ftg->boss.dt = ftg->boss.time.microseconds / 1000000.0;
    if (ftg->boss.bazooka.left <= 150 || ftg->boss.bazooka.left >= 990) {
        ftg->boss.bazooka.left = 150;
    } if (ftg->boss.bazooka.left == 270) {
        sfSprite_move(ftg->boss.img.spr, (sfVector2f) {-33, 0});
    } if (ftg->boss.dt > 0.1) {
        ftg->boss.bazooka.left += 120;
        if (ftg->boss.bazooka.left >= 990) {
            ftg->boss.bazooka.left = 150;
            ftg->boss.is_bazooka = false;
        }
        sfSprite_setTextureRect(ftg->boss.img.spr, ftg->boss.bazooka);
        sfClock_restart(ftg->boss.clock);
    }
    draw_combat(game, ftg);
}

void anim_arlong_idle(combat_t *ftg)
{
    ftg->boss.time = sfClock_getElapsedTime(ftg->boss.clock);
    ftg->boss.dt = ftg->boss.time.microseconds / 1000000.0;
    if (ftg->boss.idle.left >= 150)
        ftg->boss.idle.left = 50;
    if (ftg->boss.dt > .4f) {
        ftg->boss.idle.left += 50;
        if (ftg->boss.idle.left >= 150)
            ftg->boss.idle.left = 50;
        sfSprite_setTextureRect(ftg->boss.img.spr, ftg->boss.idle);
        sfClock_restart(ftg->boss.clock);
    }
}

void anim_combat_idle(combat_t *ftg)
{
    ftg->luffy.time = sfClock_getElapsedTime(ftg->luffy.clock);
    ftg->luffy.dt = ftg->luffy.time.microseconds / 1000000.0;
    if (ftg->luffy.idle.left >= 200)
        ftg->luffy.idle.left = 0;
    if (ftg->luffy.dt > .1f) {
        ftg->luffy.idle.left += 50;
        if (ftg->luffy.idle.left >= 200)
            ftg->luffy.idle.left = 0;
        sfSprite_setTextureRect(ftg->luffy.img.spr, ftg->luffy.idle);
        sfClock_restart(ftg->luffy.clock);
    }
}

void anim_gatling(game_t *game, combat_t *ftg)
{
    ftg->luffy.time = sfClock_getElapsedTime(ftg->luffy.clock);
    ftg->luffy.dt = ftg->luffy.time.microseconds / 1000000.0;
    if (ftg->luffy.gatling.left <= 300 || ftg->luffy.gatling.left >= 1152) {
        ftg->luffy.gatling.left = 300;
    } if (ftg->luffy.gatling.left == 380) {
        sfSprite_move(ftg->luffy.img.spr, (sfVector2f) {33, 0});
    } if (ftg->luffy.dt > 0.1) {
        ftg->luffy.gatling.left += 80;
        if (ftg->luffy.gatling.left >= 1152 - 80) {
            ftg->luffy.gatling.left = 300;
            ftg->luffy.is_gatling = false;
        }
        sfSprite_setTextureRect(ftg->luffy.img.spr, ftg->luffy.gatling);
        sfClock_restart(ftg->luffy.clock);
    }
    draw_combat(game, ftg);
}

void anim_bazooka(game_t *game, combat_t *ftg)
{
    ftg->luffy.time = sfClock_getElapsedTime(ftg->luffy.clock);
    ftg->luffy.dt = ftg->luffy.time.microseconds / 1000000.0;
    if (ftg->luffy.bazooka.left <= 1252 || ftg->luffy.bazooka.left >= 2252)
        ftg->luffy.bazooka.left = 1252;
    if (ftg->luffy.bazooka.left >= 1252 + (110 * 7)) {
        sfSprite_move(ftg->luffy.img.spr, (sfVector2f)
        {50, 0});
    } if (ftg->luffy.dt > 0.1) {
        ftg->luffy.bazooka.left += 110;
        if (ftg->luffy.bazooka.left >= 2252 - 110) {
            ftg->luffy.bazooka.left = 1262;
            ftg->luffy.is_bazooka = false;
        }
        sfSprite_setTextureRect(ftg->luffy.img.spr, ftg->luffy.bazooka);
        sfClock_restart(ftg->luffy.clock);
    }
    draw_combat(game, ftg);
}