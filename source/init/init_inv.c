/*
** EPITECH PROJECT, 2021
** init
** File description:
** .c
*/

#include "my_rpg.h"

void init_inv_sprite(inventory_t *inv)
{
    sfSprite_setPosition(inv->bg.spr, (sfVector2f) {-150, -150});
    sfSprite_setPosition(inv->bg_empty.spr, (sfVector2f) {-150, -150});
    sfSprite_setPosition(inv->select.spr, (sfVector2f) {-30, -130});
    sfSprite_setScale(inv->bg.spr, (sfVector2f) {2.5, 3.75});
    sfSprite_setScale(inv->bg_empty.spr, (sfVector2f) {2.5, 3.75});
    sfSprite_setScale(inv->select.spr, (sfVector2f) {3, 3});
    inv->select.pos = (sfVector2f) {-30, -130};
}

inventory_t init_inventory_suite(game_t *game, inventory_t *inv)
{
    sfText_setScale(inv->equip, (sfVector2f) {.23f, .23f});
    sfText_setString(inv->equip, HISTORY);
    sfText_setCharacterSize(inv->equip, 40);
    inv->param = sfText_create();
    sfText_setPosition(inv->param, (sfVector2f) {-140, -140});
    sfText_setFont(inv->param, game->font);
    sfText_setColor(inv->param, sfWhite);
    sfText_setScale(inv->param, (sfVector2f) {.5f, .5f});
    sfText_setString(inv->param, "How to play:\nKeypad to move\nE to interact\
                    \nI for inventory\nEsc to quit the game");
}

inventory_t init_inventory(game_t *game)
{
    inventory_t inv;

    inv.bg = create_image(INV);
    inv.bg_empty = create_image(BG_EMPTY);
    inv.select = create_image(SELECT);
    inv.is_item = false;
    inv.is_param = false;
    inv.is_equip = false;
    inv.items = sfText_create();
    sfText_setPosition(inv.items, (sfVector2f) {-140, -140});
    sfText_setFont(inv.items, game->font);
    sfText_setColor(inv.items, sfWhite);
    sfText_setScale(inv.items, (sfVector2f) {.5f, .5f});
    sfText_setString(inv.items, "Gigot de Sanji");
    inv.equip = sfText_create();
    sfText_setPosition(inv.equip, (sfVector2f) {-140, -140});
    sfText_setFont(inv.equip, game->font);
    sfText_setColor(inv.equip, sfWhite);
    init_inventory_suite(game, &inv);
    return inv;
}
