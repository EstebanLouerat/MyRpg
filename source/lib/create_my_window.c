/*
** EPITECH PROJECT, 2021
** create window
** File description:
** .c
*/

#include "my_rpg.h"

sfRenderWindow *create_my_window(unsigned int width,
                                unsigned height,
                                unsigned int bpp,
                                char *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = bpp;
    window = sfRenderWindow_create(video_mode, name,
                                sfDefaultStyle , NULL);
    return (window);
}