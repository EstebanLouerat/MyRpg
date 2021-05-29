/*
** EPITECH PROJECT, 2021
** intersect.c
** File description:
** .c
*/

#include "my_rpg.h"

bool is_npc_intersect(game_t *game)
{
    sfFloatRect npc_frect = sfRectangleShape_getGlobalBounds(game->npc_rect);
    sfFloatRect player_frect = sfRectangleShape_getGlobalBounds(game->perso);

    return sfFloatRect_intersects(&npc_frect, &player_frect, NULL);
}

void key_inventory2(game_t *game, inventory_t *ivt)
{
    if (ivt->is_param) {
        ivt->is_param = true;
    } if (ivt->select.pos.y == -130)
        ivt->is_item = true;
    if (ivt->select.pos.y == -75)
        ivt->is_param = true;
    if (ivt->select.pos.y == -20)
        ivt->is_equip = true;
    if (ivt->select.pos.y == 35) {
        game->game_lvl = OVERWORLD;
    }
}