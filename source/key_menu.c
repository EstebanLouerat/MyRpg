/*
** EPITECH PROJECT, 2021
** key_menu
** File description:
** .c
*/

#include "my_rpg.h"

void key_menu_option(game_t *game, menu_t *menu)
{
    if (game->e.key.code == sfKeyDown) {
        if (menu->select.pos.y == 440)
            menu->select.pos.y = 310;
        else
            menu->select.pos.y += 65;
    } if (game->e.key.code == sfKeyUp){
        if (menu->select.pos.y == 310)
            menu->select.pos.y = 440;
        else
            menu->select.pos.y -= 65;
    }
    if (game->e.key.code == sfKeyEnter) {
        if (menu->select.pos.y == 310)
            menu->is_play = true;
        if (menu->select.pos.y == 375) {
            menu->select.pos = (sfVector2f) {310, 310};
            menu->is_music = true;
        } if (menu->select.pos.y == 440)
            menu->is_option = false;
    }
    sfSprite_setPosition(menu->select.spr, menu->select.pos);
}

void key_menu_play(game_t *game, menu_t *menu)
{

}

void key_menu(game_t *game, menu_t *menu)
{
    if (game->e.key.code == sfKeyDown) {
        if (menu->select.pos.y == 440)
            menu->select.pos.y = 310;
        else
            menu->select.pos.y += 65;
    } if (game->e.key.code == sfKeyUp){
        if (menu->select.pos.y == 310)
            menu->select.pos.y = 440;
        else
            menu->select.pos.y -= 65;
    }
    if (game->e.key.code == sfKeyEnter) {
        if (menu->select.pos.y == 310)
            game->game_lvl = OVERWORLD;
        if (menu->select.pos.y == 375) {
            menu->select.pos = (sfVector2f) {310, 310};
            menu->is_option = true;
        } if (menu->select.pos.y == 440)
            sfRenderWindow_close(game->w);
    }
    sfSprite_setPosition(menu->select.spr, menu->select.pos);
}