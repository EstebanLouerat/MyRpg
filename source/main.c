/*
** EPITECH PROJECT, 2021
** main
** File description:
** .c
*/

#include "my_rpg.h"

void game_setup_suite(game_t *game)
{
    game->game_lvl = MENU;
    game->total_obj = 0;
    game->p_time = sfClock_create();
}

void game_setup(game_t *game)
{
    game->zone_txt = sfRectangleShape_create();
    game->perso = init_hitbox(game->perso_pos, (sfVector2f) {50, 60}, sfFalse);
    game->npc_rect = init_hitbox((sfVector2f) {430, 430},
    (sfVector2f) {50, 60}, sfFalse);
    game->bg = create_image(MAP);
    sfIntRect bg_rect = {1, 1, 240, 224};
    game->bg.size.x -= 100;
    game->bg.size.y -= 100;
    sfSprite_setTextureRect(game->bg.spr, bg_rect);
    game->bg = resize_image((sfVector2f) {0, 0},
                            game->bg, game->w, game->w_size);
    sfRenderWindow_setFramerateLimit(game->w, 30);
    sfRectangleShape_setSize(game->zone_txt, (sfVector2f) {290, 100});
    sfRectangleShape_setFillColor(game->zone_txt, sfBlack);
    sfSprite_setPosition(game->luffy.img.spr, game->perso_pos);
    sfSprite_setPosition(game->npc.img.spr, (sfVector2f) {425, 420});
    sfRectangleShape_setOrigin(game->zone_txt, (sfVector2f) {145, 50});
    sfRenderWindow_setMouseCursorVisible(game->w, sfFalse);
    game_setup_suite(game);
}

int main(void)
{
    game_t game = init_struct();
    game.luffy = init_luffy();
    game.npc = init_npc();

    game_setup(&game);
    if (game.game_lvl == MENU)
        menu_manage(&game);
    if (game.game_lvl == OVERWORLD)
        gameplay(&game);
    if (game.game_lvl == BASTON)
        combat(&game);
    destroy_game(&game);
    return 0;
}