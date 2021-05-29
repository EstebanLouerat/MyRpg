/*
** EPITECH PROJECT, 2021
** gameplay
** File description:
** test
*/

#include "my_rpg.h"

void gameplay(game_t *game)
{
    game->sec = (int) sfTime_asSeconds(sfClock_getElapsedTime(game->p_time));
    game->min = game->sec / 60;
    sfView_setViewport(game->cam,
    sfView_getViewport(sfRenderWindow_getDefaultView(game->w)));
    sfView_setCenter(game->cam, (sfVector2f) {0, 0});
    while (sfRenderWindow_isOpen(game->w) && game->game_lvl == OVERWORLD) {
        while (sfRenderWindow_pollEvent(game->w, &game->e)) {
            evt(game);
        }
        player_movement(game);
        if (!game->luffy.is_idle && !game->luffy.is_dw && !game->luffy.is_lf &&
        !game->luffy.is_rg && !game->luffy.is_up)
            game->luffy.is_idle = true;
        sfRenderWindow_clear(game->w, sfBlack);
        cam_movement(game, game->map_size);
        sfRenderWindow_setView(game->w, game->cam);
        draw_overworld(game);
        sfRenderWindow_display(game->w);
    }
}