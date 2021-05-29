/*
** EPITECH PROJECT, 2021
** evt gameplay
** File description:
** test
*/

#include "my_rpg.h"

void all_false(game_t *game)
{
    game->luffy.is_idle = false;
    game->luffy.is_dw = false;
    game->luffy.is_lf = false;
    game->luffy.is_rg = false;
    game->luffy.is_up = false;
}

void key_manage_release(game_t *game)
{
    if (game->e.key.code == sfKeyDown)
        game->key_down = false;
    if (game->e.key.code == sfKeyUp)
        game->key_up = false;
    if (game->e.key.code == sfKeyRight)
        game->key_right = false;
    if (game->e.key.code == sfKeyLeft)
        game->key_left = false;
}

void key_manage(game_t *game)
{
    if (game->e.key.code == sfKeyE && is_npc_intersect(game)) {
        if (game->is_txt)
            game->is_txt = false;
        else {
            game->is_txt = true;
            dialogue(game);
        }
    } if (game->e.key.code == sfKeyC) {
        game->game_lvl = BASTON;
        combat(game);
    } if (game->e.key.code == sfKeyI) {
        game->game_lvl = INVENTORY;
        inventory(game);
    } if (game->e.key.code == sfKeyDown)
        game->key_down = true;
    if (game->e.key.code == sfKeyUp)
        game->key_up = true;
    if (game->e.key.code == sfKeyRight)
        game->key_right = true;
    if (game->e.key.code == sfKeyLeft)
        game->key_left = true;
}

void evt(game_t *game)
{
    if (game->e.type == sfEvtClosed) {
        my_putstr(QUIT);
        sfRenderWindow_close(game->w);
    } if (game->e.type == sfEvtKeyPressed) {
        if (game->e.key.code == sfKeyEscape) {
            game->game_lvl = MENU;
            menu_manage(game);
        }
        key_manage(game);
    } if (game->e.type == sfEvtKeyReleased) {
            key_manage_release(game);
            all_false(game);
            game->luffy.is_idle = true;
    }
}