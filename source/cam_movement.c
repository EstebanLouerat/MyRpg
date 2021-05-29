/*
** EPITECH PROJECT, 2021
** cam movement
** File description:
** test
*/

#include "my_rpg.h"

void cam_movement_suite_suite(game_t *game, sfVector2f size)
{
    if (game->perso_pos.y - 150 <= 0) {
        if (game->perso_pos.x + 150 >= size.x)
            sfView_setCenter(game->cam, (sfVector2f)
            {size.x - 150, 150});
        else if (game->perso_pos.x - 150 <= 0)
            sfView_setCenter(game->cam, (sfVector2f) {150, 150});
        else
            sfView_setCenter(game->cam, (sfVector2f)
            {game->perso_pos.x, 150});
    }
}

void cam_movement_suite(game_t *game, sfVector2f size)
{
    if (game->perso_pos.x - 150 <= 0) {
        if (game->perso_pos.y + 150 >= size.y)
            sfView_setCenter(game->cam, (sfVector2f)
            {150, size.y - 150});
        else if (game->perso_pos.y - 150 <= 0)
            sfView_setCenter(game->cam, (sfVector2f) {150, 150});
        else
            sfView_setCenter(game->cam, (sfVector2f)
            {150, game->perso_pos.y});
    } if (game->perso_pos.y + 150 >= size.y) {
        if (game->perso_pos.x + 150 >= size.x)
            sfView_setCenter(game->cam, (sfVector2f)
            {size.x - 150, size.y - 150});
        else if (game->perso_pos.x - 150 <= 0)
            sfView_setCenter(game->cam, (sfVector2f)
            {150, size.y - 150});
        else
            sfView_setCenter(game->cam, (sfVector2f)
            {game->perso_pos.x, size.y - 150});
    }
}

void cam_movement(game_t *game, sfVector2f size)
{
    if (game->perso_pos.x + 150 >= size.x) {
        if (game->perso_pos.y + 150 >= size.y)
            sfView_setCenter(game->cam, (sfVector2f)
            {size.x - 150, size.y - 150});
        else if (game->perso_pos.y - 150 <= 0)
            sfView_setCenter(game->cam, (sfVector2f)
            {size.x - 150, 150});
        else
            sfView_setCenter(game->cam, (sfVector2f)
            {size.x - 150, game->perso_pos.y});
    }
    cam_movement_suite(game, size);
    cam_movement_suite_suite(game, size);
    if (game->perso_pos.x + 150 < size.x &&
    game->perso_pos.x - 150 > 0 && game->perso_pos.y + 150 < size.y &&
    game->perso_pos.y - 150 > 0)
        sfView_setCenter(game->cam, game->perso_pos);
}