/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** .h
*/
#ifndef RPG_H_
#define RPG_H_
#include "my.h"
#define STR_MAX   200
#define OVERWORLD   1
#define BASTON      2
#define INVENTORY   3
#define MENU        4
#define RED         "\e[1;31m"
#define WHITE       "\e[0m"
#define HISTORY     "    Luffy est quelqu'un de tres puissant de par sa\
                    \nvolonte a toute epreuve. Il est pret a tout risquer\
                    \npour ses amis ainsi que ses reves. Il est quelqu'un\
                    \nd'honnete, il ne connait pas la perversion ni l'arnaque.\
                    \nC'est quelqu'un de bon qui n'hesite pas a venir en\
                    \naide aux gens quand il sent que l'ennemi est mauvais.\
                    \nLuffy est tres fort due a son pouvoir, mais son arme\
                    \nla plus puissante est le lien de l'amitie avec les\
                    \nson equipage. Ce lien si fort que jusqu'a present aucun\
                    \nennemis quel qu'il soit n'a reussit a le defaire.\
                    \nEncore une fois, on peut facilement place que Luffy\
                    \nest quelqu'un de tres idiot. Dans sa tete il ne pense\
                    \nqu'a une chose... La nourriture..."

#define A_ARLONG    "./ressource/image/arlong_attacks.png"
#define BG_ARLONG   "./ressource/image/bg_arlong.png"
#define BG_EMPTY    "./ressource/image/bg_empty.png"
#define CHEST       "./ressource/image/chest.png"
#define INV         "./ressource/image/inventaire.png"
#define A_LUFFY     "./ressource/image/luffy_attacks.png"
#define M_LUFFY     "./ressource/image/luffy_moves.png"
#define MAP         "./ressource/image/map.png"
#define BG_MENU        "./ressource/image/menu.png"
#define NPC         "./ressource/image/npc.png"
#define SELECT      "./ressource/image/select.png"

#define MUSIC       "./ressource/music/we_are.ogg"

#define FONT        "./ressource/font/retron.ttf"

#define DIALOGNE_1  "Marine soldier : Hey! I find\nMugiwara!\n\n\
                    \n                                         press enter"
#define DIALOGNE_2  "??? :  Oh... Bring him to me!\n\n\n\
                    \n                                         press enter"
#define DIALOGNE_3  "Marine soldier : Yes sir!\n\n\n\
                    \n                                         press enter"

#define QUIT    "\e[1;31mProgramme fini.\e[0m\n"

// image.c

image_t resize_image(sfVector2f new_size,
                    image_t img,
                    sfRenderWindow *window_ajustement,
                    sfVector2u off);
image_t create_image(char *file_path);
void destroy_image(image_t *img);
image_t copy_image(image_t img);

// cam_movement.cc

void cam_movement(game_t *game, sfVector2f size);

// evt.c

void evt(game_t *game);

//animator.c

void animator(game_t *game);
void anime_npc(game_t *game);

// combat.c

void combat(game_t *game);

//inventory

void inventory(game_t *game);
void key_inventory(game_t *game, inventory_t *ivt);
void key_inventory_item(game_t *game, inventory_t *ivt);
void key_inventory_param(game_t *game, inventory_t *ivt);
void key_inventory_equip(game_t *game, inventory_t *ivt);
void key_inventory2(game_t *game, inventory_t *ivt);
void game_to_interface(game_t *game, inventory_t *inv);

// init.c

anime_t init_luffy(void);
game_t init_struct(void);
combat_t init_combat(game_t *game);
inventory_t init_inventory(game_t *game);

// init_suite.c

sfRectangleShape *init_txt_area(void);
sfRectangleShape *init_hitbox(sfVector2f pos,
                            sfVector2f size,
                            sfBool is_visible);
anime_t init_npc(void);
anime_t init_luffy_combat(void);
inventory_t init_inventory_suite(game_t *game, inventory_t *inv);
anime_t init_boss(void);
void init_inv_sprite(inventory_t *inv);
game_t init_struct_suite(game_t *prm);
menu_t init_menu(sfFont *font);

// scene.c

void draw_overworld(game_t *game);
void draw_combat(game_t *game, combat_t *fight);
void draw_inventaire(game_t *game, inventory_t *ivt);
void draw_menu(game_t *game, menu_t *menu);

// dialogue.c

void dialogue(game_t *game);

// my_arrmemset.c

char **my_arrmemset(int y, int x);

// intersect.c

bool is_npc_intersect(game_t *game);

// attack.c

void gomu_gomu_no_bazooka(game_t *game, combat_t *fight);
void gomu_gomu_no_gatling(game_t *game, combat_t *fight);
void gomu_gomu_nothing(game_t *game, combat_t *fight);
void arlong_attack(game_t *game, combat_t *fight);

// attack_animation.c

void anim_combat_idle(combat_t *ftg);
void anim_bazooka(game_t *game, combat_t *ftg);
void anim_gatling(game_t *game, combat_t *ftg);
void anim_arlong_idle(combat_t *ftg);
void anim_arlong_attcak(game_t *game, combat_t *ftg);

void key_inventory_param(game_t *game, inventory_t *ivt);
void player_movement(game_t *game);

// destroy.c

void destroy_game(game_t *game);
void destroy_fight(combat_t *fight);
void destroy_inventory(inventory_t *inv);
void destroy_menu(menu_t *menu);

// menu.c

void menu_manage(game_t *game);
void draw_volume(game_t *game, menu_t *menu);

// key_menu.c

void key_menu_option(game_t *game, menu_t *menu);
void key_menu_play(game_t *game, menu_t *menu);
void key_menu(game_t *game, menu_t *menu);

#endif