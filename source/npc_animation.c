/*
** EPITECH PROJECT, 2021
** npc_animation
** File description:
** .c
*/

#include "my_rpg.h"

void anime_npc(game_t *game)
{
    game->npc.time = sfClock_getElapsedTime(game->npc.clock);
    game->npc.dt = game->npc.time.microseconds / 1000000.0;
    if (game->npc.idle.left >= 100)
        game->npc.idle.left = 0;
    if (game->npc.dt > 0.3) {
        game->npc.idle.left += 54;
        if (game->npc.idle.left >= 100)
            game->npc.idle.left = 0;
        sfSprite_setTextureRect(game->npc.img.spr, game->npc.idle);
        sfClock_restart(game->npc.clock);
    }
}