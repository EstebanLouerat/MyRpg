/*
** EPITECH PROJECT, 2021
** inventory
** File description:
** .c
*/

#include "my_rpg.h"

void game_to_interface(game_t *game, inventory_t *inv)
{
    char *life = my_strcat_f1(my_itoa(game->life), " \n/ 100");
    sfText_setString(game->life_txt, life);
    if (game->life <= 0) {
        game->life = 100;
    }
}

void key_inventory_param(game_t *game, inventory_t *ivt)
{
    if (game->e.key.code == sfKeyEnter) {
        ivt->is_param = false;
    }
}