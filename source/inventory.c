/*
** EPITECH PROJECT, 2021
** inventory
** File description:
** .c
*/

#include "my_rpg.h"

void key_inventory_item(game_t *game, inventory_t *ivt)
{
    game->is_object = true;
    if (game->e.key.code == sfKeyEnter) {
        ivt->is_item = false;
    }
}

void key_inventory_equip(game_t *game, inventory_t *ivt)
{
    if (game->e.key.code == sfKeyEnter) {
        ivt->is_equip = false;
    }
}

void key_inventory(game_t *game, inventory_t *ivt)
{
    if (game->e.key.code == sfKeyDown) {
        if (ivt->select.pos.y >= 35)
            ivt->select.pos.y = -130;
        else
            ivt->select.pos.y += 55;
        sfSprite_setPosition(ivt->select.spr, ivt->select.pos);
    } if (game->e.key.code == sfKeyUp) {
        if (ivt->select.pos.y <= -130)
            ivt->select.pos.y = 35;
        else
            ivt->select.pos.y -= 55;
        sfSprite_setPosition(ivt->select.spr, ivt->select.pos);
    } if (game->e.key.code == sfKeyEnter)
        key_inventory2(game, ivt);
    if (game->e.key.code == sfKeyE)
        game->life -= 5;
}

void evt_inventory(game_t *game, inventory_t *ivt)
{
    if (game->e.type == sfEvtClosed) {
        my_putstr(QUIT);
        sfRenderWindow_close(game->w);
    } if (game->e.type == sfEvtKeyPressed) {
        if (game->e.key.code == sfKeyEscape) {
            my_putstr(QUIT);
            sfRenderWindow_close(game->w);
        }
        if (ivt->is_param)
            key_inventory_param(game, ivt);
        if (ivt->is_item)
            key_inventory_item(game, ivt);
        else if (ivt->is_equip)
            key_inventory_equip(game, ivt);
        else
            key_inventory(game, ivt);
    }
}

void inventory(game_t *game)
{
    inventory_t ivt = init_inventory(game);

    ivt.bg = resize_image((sfVector2f) {500, 500},
                            ivt.bg, game->w, game->w_size);
    ivt.bg = resize_image((sfVector2f) {500, 500},
                            ivt.bg, game->w, game->w_size);
    sfView_setCenter(game->cam, (sfVector2f) {0, 0});
    init_inv_sprite(&ivt);
    while (sfRenderWindow_isOpen(game->w) && game->game_lvl == INVENTORY) {
        while (sfRenderWindow_pollEvent(game->w, &game->e)) {
            evt_inventory(game, &ivt);
        }
        draw_inventaire(game, &ivt);
    }
    destroy_inventory(&ivt);
}
