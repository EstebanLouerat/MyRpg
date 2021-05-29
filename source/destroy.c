/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** .h
*/

#include "my_rpg.h"

void destroy_menu(menu_t *menu)
{
    sfSprite_destroy(menu->bg.spr);
    sfTexture_destroy(menu->bg.tx);
    sfText_destroy(menu->command);
    sfText_destroy(menu->htp);
    sfText_destroy(menu->option);
    sfText_destroy(menu->play);
    sfSprite_destroy(menu->select.spr);
    sfTexture_destroy(menu->select.tx);
    sfSprite_destroy(menu->select_2.spr);
    sfTexture_destroy(menu->select_2.tx);
}

void destroy_inventory(inventory_t *inv)
{
    sfSprite_destroy(inv->bg.spr);
    sfTexture_destroy(inv->bg.tx);
    sfSprite_destroy(inv->bg_empty.spr);
    sfTexture_destroy(inv->bg_empty.tx);
    sfText_destroy(inv->equip);
    sfText_destroy(inv->items);
    sfText_destroy(inv->param);
    sfSprite_destroy(inv->select.spr);
    sfTexture_destroy(inv->select.tx);
}

void destroy_fight(combat_t *fight)
{
    sfText_destroy(fight->arlong);
    sfText_destroy(fight->attack);
    sfSprite_destroy(fight->bg.spr);
    sfTexture_destroy(fight->bg.tx);
    sfClock_destroy(fight->boss.clock);
    sfTexture_destroy(fight->boss.img.tx);
    sfSprite_destroy(fight->boss.img.spr);
    sfText_destroy(fight->fight);
    sfText_destroy(fight->fuite);
    sfText_destroy(fight->item);
    sfClock_destroy(fight->luffy.clock);
    sfTexture_destroy(fight->luffy.img.tx);
    sfSprite_destroy(fight->luffy.img.spr);
    sfSprite_destroy(fight->select.spr);
    sfTexture_destroy(fight->select.tx);
    sfRectangleShape_destroy(fight->txt_area);
}

void destroy_game(game_t *game)
{
    sfView_destroy(game->cam);
    sfSprite_destroy(game->bg.spr);
    sfSprite_destroy(game->luffy.img.spr);
    sfTexture_destroy(game->bg.tx);
    sfTexture_destroy(game->luffy.img.tx);
    sfFont_destroy(game->font);
    sfClock_destroy(game->luffy.clock);
    sfRenderWindow_destroy(game->w);
    sfMusic_destroy(game->luffy.song);
    sfText_destroy(game->life_txt);
    sfRectangleShape_destroy(game->zone_txt);
    sfText_destroy(game->time_txt);
    sfRectangleShape_destroy(game->perso);
    sfClock_destroy(game->p_time);
    sfText_destroy(game->nv_txt);
    sfRectangleShape_destroy(game->npc_rect);
    sfClock_destroy(game->npc.clock);
    sfSprite_destroy(game->npc.img.spr);
    sfTexture_destroy(game->npc.img.tx);
}