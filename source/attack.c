/*
** EPITECH PROJECT, 2021
** attack
** File description:
** .c
*/

#include "my_rpg.h"

void all_false_attack(combat_t *fight)
{
    fight->luffy.is_idle = false;
    fight->luffy.is_bazooka = false;
    fight->luffy.is_gatling = false;
    fight->boss.is_idle = false;
    fight->boss.is_bazooka = false;
    fight->boss.is_gatling = false;
}

void arlong_attack(game_t *game, combat_t *fight)
{
    if (fight->boss.is_idle)
        anim_arlong_idle(fight);
    while (fight->boss.is_bazooka)
        anim_gatling(game, fight);
    fight->boss.is_idle = true;
}

void gomu_gomu_no_bazooka(game_t *game, combat_t *fight)
{
    my_putstr("Gomu Gomu no bazooka !\n");
    fight->is_fight = false;
    all_false_attack(fight);
    fight->luffy.is_bazooka = true;
    sfSprite_setPosition(fight->luffy.img.spr,
    (sfVector2f) {220, fight->luffy.img.pos.y});
    sfClock_restart(fight->luffy.clock);
    while (fight->luffy.is_bazooka)
        anim_bazooka(game, fight);
    fight->luffy.is_idle = true;
    fight->select.pos = (sfVector2f) {280, 358};
    fight->boss_life -= 100;
    sfSprite_setPosition(fight->select.spr, fight->select.pos);
    sfSprite_setPosition(fight->luffy.img.spr, fight->luffy.img.pos);
}

void gomu_gomu_no_gatling(game_t *game, combat_t *fight)
{
    my_putstr("Gomu Gomu no Gatling !\n");
    fight->is_fight = false;
    all_false_attack(fight);
    fight->luffy.is_gatling = true;
    while (fight->luffy.is_gatling)
        anim_gatling(game, fight);
    fight->luffy.is_idle = true;
    fight->select.pos = (sfVector2f) {280, 358};
    fight->boss_life -= 70;
    sfSprite_setPosition(fight->select.spr, fight->select.pos);
    sfSprite_setPosition(fight->luffy.img.spr, fight->luffy.img.pos);
}

void gomu_gomu_nothing(game_t *game, combat_t *fight)
{
    my_putstr("Gomu Gomu nothing !\n");
    fight->is_fight = false;
    fight->select.pos = (sfVector2f) {280, 358};
    sfSprite_setPosition(fight->select.spr, fight->select.pos);
}