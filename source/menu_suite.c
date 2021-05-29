/*
** EPITECH PROJECT, 2021
** menu_suite
** File description:
** .c
*/

#include "my_rpg.h"

void evt_volume(game_t *game, menu_t *menu, bool *is_enter)
{
    if (game->e.type == sfEvtClosed) {
        my_putstr(QUIT);
        sfRenderWindow_close(game->w);
    } if (game->e.type == sfEvtKeyPressed) {
        if (game->e.key.code == sfKeyEscape) {
            my_putstr(QUIT);
            sfRenderWindow_close(game->w);
        } if (game->e.key.code == sfKeyEnter) {
            *is_enter = true;
            menu->is_music = false;
        }
    }
}

void draw_volume(game_t *game, menu_t *menu)
{
    sfRectangleShape *area = sfRectangleShape_create();
    bool is_enter = false;

    sfRectangleShape_setFillColor(area, sfBlack);
    sfRectangleShape_setSize(area,
    (sfVector2f) {game->w_size.x / 1.5f, game->w_size.y / 1.5f});
    sfRectangleShape_setPosition(area,
    (sfVector2f) {100, 100});
    while (sfRenderWindow_isOpen(game->w) && !is_enter) {
        while (sfRenderWindow_pollEvent(game->w, &game->e)) {
            evt_volume(game, menu, &is_enter);
        }
        sfRenderWindow_drawRectangleShape(game->w, area, NULL);
        sfRenderWindow_display(game->w);
    }
    sfRectangleShape_destroy(area);
}