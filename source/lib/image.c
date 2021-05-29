/*
** EPITECH PROJECT, 2021
** imge
** File description:
** test
*/

#include "my_rpg.h"

image_t resize_image(sfVector2f new_size, image_t img,
                    sfRenderWindow *window_ajustement, sfVector2u off)
{
    sfVector2f scale;
    sfVector2f win_size;

    if (window_ajustement != NULL) {
        win_size.x = off.x;
        win_size.y = off.y;
        scale.x = win_size.x / img.size.x;
        scale.y = win_size.y / img.size.y;
        sfSprite_setScale(img.spr, scale);
        img.size = win_size;
    } else {
        scale.x = new_size.x / img.size.x;
        scale.y = new_size.y / img.size.y;
        sfSprite_setScale(img.spr, scale);
        img.size = new_size;
    }
    return img;
}

image_t create_image(char *file_path)
{
    image_t img;
    sfVector2u off;

    img.tx = sfTexture_createFromFile(file_path, NULL);
    img.spr = sfSprite_create();

    sfSprite_setTexture(img.spr, img.tx, sfTrue);
    img.pos.x = img.pos.y = 0;
    off = sfTexture_getSize(img.tx);
    img.size.x = off.x;
    img.size.y = off.y;
    return img;
}

void destroy_image(image_t *img)
{
    sfSprite_destroy(img->spr);
    sfTexture_destroy(img->tx);
}

image_t copy_image(image_t img)
{
    image_t dest;

    dest.pos = img.pos;
    dest.size = img.size;
    dest.spr = sfSprite_copy(img.spr);
    dest.tx = sfTexture_copy(img.tx);
    return dest;
}