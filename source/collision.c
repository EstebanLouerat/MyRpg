/*
** EPITECH PROJECT, 2021
** collision
** File description:
** .c
*/

#include "my_rpg.h"

bool collision(game_t *game)
{
    if (game->key_right && game->perso_pos.x >= 235 &&
    game->perso_pos.y <= 390)
        return false;
    if (game->key_up && game->perso_pos.x >= 235 &&
    game->perso_pos.y <= 390)
        return false;
    if (game->key_up && game->perso_pos.y <= 275 &&
    !(game->perso_pos.x >= 186 && game->perso_pos.x <= 207))
        return false;
    if (!game->is_indoor && !(game->perso_pos.x >= 186 &&
    game->perso_pos.x <= 207) && game->perso_pos.y <= 230)
        game->is_indoor = true;
    return true;
}