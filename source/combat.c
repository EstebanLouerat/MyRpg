/*
** EPITECH PROJECT, 2021
** combat.c
** File description:
** .c
*/

#include "my_rpg.h"

void key_combat_fight(game_t *game, combat_t *fight)
{
    if (game->e.key.code == sfKeyDown) {
        fight->select.pos.y = (fight->select.pos.y >= 418) ?
        358 : fight->select.pos.y + 20;
        sfSprite_setPosition(fight->select.spr, fight->select.pos);
    } if (game->e.key.code == sfKeyUp) {
        fight->select.pos.y = (fight->select.pos.y <= 358) ?
        418 : fight->select.pos.y - 20;
        sfSprite_setPosition(fight->select.spr, fight->select.pos);
    } if (game->e.key.code == sfKeyEnter) {
        if (fight->select.pos.y == 358)
            gomu_gomu_no_bazooka(game, fight);
        if (fight->select.pos.y == 378)
            gomu_gomu_no_gatling(game, fight);
        if (fight->select.pos.y == 398) {
            gomu_gomu_nothing(game, fight);
        } if (fight->select.pos.y == 418) {
            fight->is_fight = false;
        }
    }
}

void key_combat_item(game_t *game, combat_t *fight)
{
    if (game->e.key.code == sfKeyDown) {
        if (fight->select.pos.y >= 420)
            fight->select.pos.y = 360;
        else
            fight->select.pos.y += 60;
    } if (game->e.key.code == sfKeyUp) {
        if (fight->select.pos.y <= 360)
            fight->select.pos.y = 420;
        else
            fight->select.pos.y -= 60;
    } if (game->e.key.code == sfKeyEnter) {
        if (fight->select.pos.y == 360)
            my_putstr("Fight !\n");
        if (fight->select.pos.y == 420) {
            fight->is_item = false;
        }
    }
    sfSprite_setPosition(fight->select.spr, fight->select.pos);
}

void key_combat_menu(game_t *game, combat_t *fight)
{
    if (game->e.key.code == sfKeyDown) {
        if (fight->select.pos.y >= 418)
            fight->select.pos.y = 358;
        else
            fight->select.pos.y += 30;
        sfSprite_setPosition(fight->select.spr, fight->select.pos);
    } if (game->e.key.code == sfKeyUp) {
        if (fight->select.pos.y <= 358)
            fight->select.pos.y = 418;
        else
            fight->select.pos.y -= 30;
        sfSprite_setPosition(fight->select.spr, fight->select.pos);
    } if (game->e.key.code == sfKeyEnter) {
        if (fight->select.pos.y == 358)
            fight->is_fight = true;
        if (fight->select.pos.y == 388)
            fight->is_item = true;
        if (fight->select.pos.y == 418) {
            game->game_lvl = OVERWORLD;
        }
    }
}

void evt_combat(game_t *game, combat_t *fight)
{
    if (game->e.type == sfEvtClosed) {
        my_putstr(QUIT);
        sfRenderWindow_close(game->w);
    } if (game->e.type == sfEvtKeyPressed && !fight->boss.is_bazooka) {
        if (game->e.key.code == sfKeyEscape) {
            my_putstr(QUIT);
            sfRenderWindow_close(game->w);
        }
        if (fight->is_fight)
            key_combat_fight(game, fight);
        else
            key_combat_menu(game, fight);
    }
}

void combat(game_t *game)
{
    combat_t fight = init_combat(game);

    game->sec = (int) sfTime_asSeconds(sfClock_getElapsedTime(game->p_time));
    game->min = game->sec / 60;
    fight.bg = resize_image((sfVector2f) {0, 0}, fight.bg,
                            game->w, game->w_size);
    fight.select.pos = (sfVector2f) {280, 358};
    sfSprite_setPosition(fight.select.spr, fight.select.pos);
    sfView_setCenter(game->cam, (sfVector2f) {400, 300});
    while (sfRenderWindow_isOpen(game->w) && game->game_lvl == BASTON) {
        while (sfRenderWindow_pollEvent(game->w, &game->e)) {
            evt_combat(game, &fight);
        }
        if (fight.boss_life <= 0)
            game->game_lvl = OVERWORLD;
        draw_combat(game, &fight);
    }
    destroy_fight(&fight);
}