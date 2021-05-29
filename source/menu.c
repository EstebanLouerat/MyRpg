/*
** EPITECH PROJECT, 2021
** menu
** File description:
** .c
*/

#include "my_rpg.h"

void evt_menu_suite(game_t *game, menu_t *menu)
{
}

void evt_menu(game_t *game, menu_t *menu)
{
    if (game->e.type == sfEvtClosed) {
        my_putstr(QUIT);
        sfRenderWindow_close(game->w);
    } if (game->e.type == sfEvtKeyPressed) {
        if (game->e.key.code == sfKeyEscape) {
            my_putstr(QUIT);
            sfRenderWindow_close(game->w);
        }
        if (menu->is_option)
            key_menu_option(game, menu);
        else
            key_menu(game, menu);
    }
    evt_menu_suite(game, menu);
}

void evt_htp(game_t *game, menu_t *menu, bool *is_enter)
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
            menu->is_play = false;
        }
    }
}

void draw_htp(game_t *game, menu_t *menu)
{
    sfRectangleShape *filtre = sfRectangleShape_create();
    bool is_enter = false;

    sfRectangleShape_setFillColor(filtre, (sfColor) {0, 0, 0, 150});
    sfRectangleShape_setSize(filtre,
    (sfVector2f) {game->w_size.x, game->w_size.y});
    while (sfRenderWindow_isOpen(game->w) && !is_enter) {
        while (sfRenderWindow_pollEvent(game->w, &game->e)) {
            evt_htp(game, menu, &is_enter);
        }
        sfRenderWindow_clear(game->w, sfBlack);
        sfRenderWindow_drawSprite(game->w, menu->bg.spr, NULL);
        sfRenderWindow_drawRectangleShape(game->w, filtre, NULL);
        sfRenderWindow_drawText(game->w, menu->htp, NULL);
        sfRenderWindow_display(game->w);
    }
    sfRectangleShape_destroy(filtre);
}

void menu_manage(game_t *game)
{
    menu_t menu = init_menu(game->font);

    menu.bg = resize_image((sfVector2f) {0, 0},
                            menu.bg, game->w, game->w_size);
    sfSprite_setScale(menu.select.spr, (sfVector2f) {3, 3});
    while (sfRenderWindow_isOpen(game->w) && game->game_lvl == MENU) {
        while (sfRenderWindow_pollEvent(game->w, &game->e)) {
            evt_menu(game, &menu);
        }
        sfRenderWindow_setView(game->w, sfRenderWindow_getDefaultView(game->w));
        if (menu.is_play)
            draw_htp(game, &menu);
        else if (menu.is_music)
            draw_volume(game, &menu);
        else
            draw_menu(game, &menu);
    }
    destroy_menu(&menu);
}