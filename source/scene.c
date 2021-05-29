/*
** EPITECH PROJECT, 2021
** scene.c
** File description:
** .c
*/

#include "my_rpg.h"

void draw_menu(game_t *game, menu_t *menu)
{
    if (menu->is_option) {
        sfText_setString(menu->play, "Command\nVolume\nReturn");
    } else {
        sfText_setString(menu->play, "Play\nOption\nQuit");
    }
    sfSprite_setPosition(menu->bg.spr, (sfVector2f) {0, 0});
    sfRenderWindow_drawSprite(game->w, menu->bg.spr, NULL);
    sfRenderWindow_drawSprite(game->w, menu->select.spr, NULL);
    sfRenderWindow_drawText(game->w, menu->play, NULL);
    sfRenderWindow_display(game->w);
}

void draw_inventaire(game_t *game, inventory_t *ivt)
{
    sfRenderWindow_clear(game->w, sfBlack);
    sfRenderWindow_setView(game->w, game->cam);
    sfRenderWindow_drawSprite(game->w, ivt->bg.spr, NULL);
    sfRenderWindow_drawSprite(game->w, ivt->select.spr, NULL);
    if (ivt->is_param) {
        sfRenderWindow_drawSprite(game->w, ivt->bg_empty.spr, NULL);
        sfRenderWindow_drawText(game->w, ivt->param, NULL);
    } if (ivt->is_item) {
        sfRenderWindow_drawSprite(game->w, ivt->bg_empty.spr, NULL);
    } if (ivt->is_equip) {
        sfRenderWindow_drawSprite(game->w, ivt->bg_empty.spr, NULL);
        sfRenderWindow_drawText(game->w, ivt->equip, NULL);
    } if (!ivt->is_equip && !ivt->is_item && !ivt->is_param) {
        game_to_interface(game, ivt);
        sfRenderWindow_drawText(game->w, game->life_txt, NULL);
        sfRenderWindow_drawText(game->w, game->nv_txt, NULL);
        sfRenderWindow_drawText(game->w, game->time_txt, NULL);
    }
    sfRenderWindow_display(game->w);
}

void draw_combat(game_t *game, combat_t *fight)
{
    if (fight->luffy.is_idle)
        anim_combat_idle(fight);
    arlong_attack(game, fight);
    sfRenderWindow_clear(game->w, sfBlack);
    sfRenderWindow_setView(game->w, game->cam);
    sfRenderWindow_drawSprite(game->w, fight->bg.spr, NULL);
    sfRenderWindow_drawSprite(game->w, fight->luffy.img.spr, NULL);
    sfRenderWindow_drawSprite(game->w, fight->boss.img.spr, NULL);
    sfRenderWindow_drawRectangleShape(game->w, fight->txt_area, NULL);
    if (fight->is_fight) {
        sfRenderWindow_drawText(game->w, fight->attack, NULL);
    } else if (fight->boss.is_bazooka) {
        sfRenderWindow_drawText(game->w, fight->arlong, NULL);
    } else {
        sfRenderWindow_drawText(game->w, fight->fight, NULL);
        sfRenderWindow_drawText(game->w, fight->item, NULL);
        sfRenderWindow_drawText(game->w, fight->fuite, NULL);
    }
    sfRenderWindow_drawSprite(game->w, fight->select.spr, NULL);
    sfRenderWindow_display(game->w);
}

void draw_overworld(game_t *game)
{
    animator(game);
    sfRenderWindow_drawSprite(game->w, game->bg.spr, NULL);
    sfRenderWindow_drawSprite(game->w, game->npc.img.spr, NULL);
    sfRenderWindow_drawSprite(game->w, game->luffy.img.spr, NULL);
    sfRenderWindow_drawRectangleShape(game->w, game->perso, NULL);
    sfRenderWindow_drawRectangleShape(game->w, game->npc_rect, NULL);
}