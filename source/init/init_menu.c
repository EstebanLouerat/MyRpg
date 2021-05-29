/*
** EPITECH PROJECT, 2021
** init
** File description:
** .c
*/

#include "my_rpg.h"

void init_menu_suite(menu_t *menu, sfFont *font)
{
    menu->is_music = false;
    menu->is_play = false;
    menu->is_command = false;
    menu->is_option = false;
    menu->menu_cam = (sfFloatRect) {0, 0, 800, 600};
    menu->htp = sfText_create();
    sfText_setFont(menu->htp, font);
    sfText_setColor(menu->htp, sfWhite);
    sfText_setCharacterSize(menu->htp, 90);
    sfText_setPosition(menu->htp, (sfVector2f) {20, 20});
    sfText_setScale(menu->htp, (sfVector2f) {.5f, .5f});
    sfText_setString(menu->htp, "Command:\n\nUse 'E' to interact\
    \nUse your Keypad to move\nUse 'I' to open the inventory\
    \nUse 'Esc' anytime to return \nto the menu or quit the game\
    \n\n\t\t\t\t\t\t\t\tPress 'Enter'");
}

menu_t init_menu(sfFont *font)
{
    menu_t menu;

    menu.bg = create_image(BG_MENU);
    menu.select = create_image(SELECT);
    menu.select_2 = create_image(SELECT);
    menu.option = sfText_create();
    menu.play = sfText_create();
    menu.command = sfText_create();
    menu.select.pos = (sfVector2f) {310, 310};
    sfSprite_setPosition(menu.select.spr, menu.select.pos);
    sfText_setFont(menu.play, font);
    sfText_setColor(menu.play, sfWhite);
    sfText_setCharacterSize(menu.play, 100);
    sfText_setPosition(menu.play, (sfVector2f) {350, 300});
    sfText_setOutlineThickness(menu.play, 7);
    sfText_setOutlineColor(menu.play, sfBlack);
    sfText_setScale(menu.play, (sfVector2f) {.5f, .5f});
    sfText_setString(menu.play, "Play\nOption\nQuit");
    init_menu_suite(&menu, font);
    return menu;
}