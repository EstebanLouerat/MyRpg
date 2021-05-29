/*
** EPITECH PROJECT, 2021
** animator.c
** File description:
** .c
*/

#include "my_rpg.h"

void anim_luffy_down(game_t *game)
{
    game->luffy.time = sfClock_getElapsedTime(game->luffy.clock);
    game->luffy.dt = game->luffy.time.microseconds / 1000000.0;
    if (game->luffy.run_dw.left >= 240)
        game->luffy.run_dw.left = 0;
    if (game->luffy.dt > 0.1) {
        game->luffy.run_dw.left += 40;
        if (game->luffy.run_dw.left >= 240)
            game->luffy.run_dw.left = 0;
        sfSprite_setTextureRect(game->luffy.img.spr, game->luffy.run_dw);
        sfClock_restart(game->luffy.clock);
    }
}

void anim_luffy_up(game_t *game)
{
    game->luffy.time = sfClock_getElapsedTime(game->luffy.clock);
    game->luffy.dt = game->luffy.time.microseconds / 1000000.0;
    if (game->luffy.run_up.left <= 240 || game->luffy.run_up.left >= 480)
        game->luffy.run_up.left = 240;
    if (game->luffy.dt > 0.1) {
        game->luffy.run_up.left += 40;
        if (game->luffy.run_up.left >= 480)
            game->luffy.run_up.left = 240;
        sfSprite_setTextureRect(game->luffy.img.spr, game->luffy.run_up);
        sfClock_restart(game->luffy.clock);
    }
}

void anim_luffy_right(game_t *game)
{
    game->luffy.time = sfClock_getElapsedTime(game->luffy.clock);
    game->luffy.dt = game->luffy.time.microseconds / 1000000.0;
    if (game->luffy.run_rg.left <= 480 || game->luffy.run_rg.left >= 720)
        game->luffy.run_rg.left = 480;
    if (game->luffy.dt > 0.1) {
        game->luffy.run_rg.left += 40;
        if (game->luffy.run_rg.left >= 720)
            game->luffy.run_rg.left = 480;
        sfSprite_setTextureRect(game->luffy.img.spr, game->luffy.run_rg);
        sfClock_restart(game->luffy.clock);
    }
}

void anim_luffy_left(game_t *game)
{
    game->luffy.time = sfClock_getElapsedTime(game->luffy.clock);
    game->luffy.dt = game->luffy.time.microseconds / 1000000.0;
    if (game->luffy.run_lf.left <= 720)
        game->luffy.run_lf.left = 720;
    if (game->luffy.dt > 0.1) {
        game->luffy.run_lf.left += 40;
        if (game->luffy.run_lf.left >= 960)
            game->luffy.run_lf.left = 720;
        sfSprite_setTextureRect(game->luffy.img.spr, game->luffy.run_lf);
        sfClock_restart(game->luffy.clock);
    }
}

void animator(game_t *game)
{
    if (game->luffy.is_idle)
        sfSprite_setTextureRect(game->luffy.img.spr, game->luffy.idle);
    if (game->luffy.is_dw)
        anim_luffy_down(game);
    if (game->luffy.is_up)
        anim_luffy_up(game);
    if (game->luffy.is_rg)
        anim_luffy_right(game);
    if (game->luffy.is_lf)
        anim_luffy_left(game);
    anime_npc(game);
}