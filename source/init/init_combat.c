/*
** EPITECH PROJECT, 2021
** init_combat
** File description:
** .c
*/

#include "my_rpg.h"

void init_combat_suite_suite(game_t *game, combat_t *ftg)
{
    ftg->arlong = sfText_create();
    sfText_setPosition(ftg->arlong, (sfVector2f) {290, 385});
    sfText_setFont(ftg->arlong, game->font);
    sfText_setColor(ftg->arlong, sfWhite);
    sfText_setScale(ftg->arlong, (sfVector2f) {.5f, .5f});
    sfText_setString(ftg->arlong, "Arlong attack !");
    ftg->boss.is_bazooka = false;
    ftg->boss.is_idle = true;
}

void init_combat_suite(game_t *game, combat_t *ftg)
{
    ftg->item = sfText_create();
    sfText_setPosition(ftg->item, (sfVector2f) {290, 385});
    sfText_setFont(ftg->item, game->font);
    sfText_setColor(ftg->item, sfWhite);
    sfText_setScale(ftg->item, (sfVector2f) {.5f, .5f});
    sfText_setString(ftg->item, "item");
    ftg->is_item = false;
    ftg->fuite = sfText_create();
    sfText_setFont(ftg->fuite, game->font);
    sfText_setColor(ftg->fuite, sfWhite);
    sfText_setScale(ftg->fuite, (sfVector2f) {.5f, .5f});
    sfText_setString(ftg->fuite, "escape");
    sfText_setPosition(ftg->fuite, (sfVector2f) {290, 415});
    ftg->luffy = init_luffy_combat();
    ftg->boss = init_boss();
    ftg->boss_life = 200;
    ftg->luffy.img.pos = (sfVector2f) {300, 250};
    sfSprite_setPosition(ftg->luffy.img.spr, ftg->luffy.img.pos);
    init_combat_suite_suite(game, ftg);
}

combat_t init_combat(game_t *game)
{
    combat_t ftg;

    ftg.bg = create_image(BG_ARLONG);
    ftg.select = create_image(SELECT);
    ftg.txt_area = init_txt_area();
    ftg.fight = sfText_create();
    sfText_setPosition(ftg.fight, (sfVector2f) {290, 355});
    sfText_setFont(ftg.fight, game->font);
    sfText_setColor(ftg.fight, sfWhite);
    sfText_setScale(ftg.fight, (sfVector2f) {.5f, .5f});
    sfText_setString(ftg.fight, "fight");
    ftg.is_fight = false;
    ftg.attack = sfText_create();
    sfText_setPosition(ftg.attack, (sfVector2f) {290, 355});
    sfText_setFont(ftg.attack, game->font);
    sfText_setColor(ftg.attack, sfWhite);
    sfText_setScale(ftg.attack, (sfVector2f) {.5f, .5f});
    sfText_setString(ftg.attack, "Bazooka\nGatling\nNothing\nReturn");
    init_combat_suite(game, &ftg);
    return ftg;
}
