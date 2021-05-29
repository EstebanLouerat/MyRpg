/*
** EPITECH PROJECT, 2021
** diag
** File description:
** .c
*/

#include "my_rpg.h"

diag_t init_diag(void)
{
    diag_t log;

    log.diag = my_arrmemset(3, STR_MAX);
    log.diag[0] = DIALOGNE_1;
    log.diag[1] = DIALOGNE_2;
    log.diag[2] = DIALOGNE_3;
    log.txt = sfText_create();
    sfText_setLineSpacing(log.txt, .9f);
    log.ep = 0;
    return log;
}

void evt_txt(game_t *game, int *nb)
{
    if (game->e.type == sfEvtClosed) {
        my_putstr(RED);
        my_putstr("Programme fini.\n");
        my_putstr(WHITE);
        sfRenderWindow_close(game->w);
    } if (game->e.type == sfEvtKeyPressed) {
        if (game->e.key.code == sfKeyEscape) {
            my_putstr(RED);
            my_putstr("Programme fini.\n");
            my_putstr(WHITE);
            sfRenderWindow_close(game->w);
        } if (game->e.key.code == sfKeyE)
            game->is_txt = false;
        if (game->e.key.code == sfKeyEnter)
            *nb += 1;
            if (*nb == 3)
                game->is_txt = false;
    }
}

void draw_dialogue(game_t *game, diag_t *log)
{
    sfRectangleShape_setPosition(game->zone_txt, (sfVector2f)
    {game->cam_pos.x, game->cam_pos.y - 95});
    sfRenderWindow_drawRectangleShape(game->w, game->zone_txt, NULL);
    sfText_setString(log->txt, log->diag[log->ep]);
    sfRenderWindow_drawText(game->w, log->txt, NULL);
    sfRenderWindow_display(game->w);
}

void dialogue(game_t *game)
{
    diag_t log = init_diag();

    game->cam_pos = sfView_getCenter(game->cam);
    sfText_setPosition(log.txt, (sfVector2f)
    {game->cam_pos.x - 140, game->cam_pos.y - 140});
    sfText_setFont(log.txt, game->font);
    sfText_setColor(log.txt, sfWhite);
    sfText_setScale(log.txt, (sfVector2f) {.5f, .5f});
    while (sfRenderWindow_isOpen(game->w) && game->is_txt) {
        while (sfRenderWindow_pollEvent(game->w, &game->e)) {
            evt_txt(game, &log.ep);
        }
        if (!game->is_txt)
            break;
        draw_dialogue(game, &log);
    }
    sfText_destroy(log.txt);
    free(log.diag);
    game->game_lvl = BASTON;
    combat(game);
}