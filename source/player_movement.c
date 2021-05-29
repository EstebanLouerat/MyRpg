/*
** EPITECH PROJECT, 2021
** player_movement
** File description:
** .c
*/

#include "my_rpg.h"

void all_false_2(game_t *game)
{
    game->luffy.is_idle = false;
    game->luffy.is_dw = false;
    game->luffy.is_lf = false;
    game->luffy.is_rg = false;
    game->luffy.is_up = false;
}

void player_movement_suite(game_t *game)
{
    if (game->key_down) {
        if (game->perso_pos.y < game->map_size.y - 50 && collision(game)) {
            game->perso_pos.y += 7;
            all_false_2(game);
            game->luffy.is_dw = true;
        }
    } if (game->key_up) {
        if (game->perso_pos.y > 10 && collision(game)) {
            game->perso_pos.y -= 7;
            all_false_2(game);
            game->luffy.is_up = true;
        }
    }
}

void player_movement(game_t *game)
{
    if (game->key_right) {
        if (game->perso_pos.x < game->map_size.x - 50 && collision(game)) {
            game->perso_pos.x += 7;
            all_false_2(game);
            game->luffy.is_rg = true;
        }
    } if (game->key_left) {
        if (game->perso_pos.x > 135 && collision(game)){
            game->perso_pos.x -= 7;
            all_false_2(game);
            game->luffy.is_lf = true;
        }
    }
    player_movement_suite(game);
    sfSprite_setPosition(game->luffy.img.spr, game->perso_pos);
    sfRectangleShape_setPosition(game->perso, game->perso_pos);
}