/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** init_sprite
*/

#include "rpg.h"

rpg_t scale_sprite(rpg_t rpg, int nb, int nb_scene)
{
    sfVector2f scale_menu = {1.21, 1.2};
    sfVector2f scale_fight = {1.2, 1.1};

    if (nb == 0 && nb_scene == 0)
        sfSprite_setScale(rpg.scn[nb_scene].ent[nb].spr, scale_menu);
    if ((nb == 0 || nb == 1 || nb == 2 || nb == 3) && nb_scene == 1)
        sfSprite_setScale(rpg.scn[nb_scene].ent[nb].spr, scale_fight);
    return (rpg);
}

rpg_t attribute_map_sprite(rpg_t rpg, int nb, int nb_scene)
{
    sfVector2f scale_background = {3, 3};
    sfVector2f scale_player = {1.2, 1.2};
    sfVector2f scale_end_fight = {1.6, 1.6};

    rpg.scn[nb_scene].ent[nb].text =
    sfTexture_createFromFile(rpg.scn[nb_scene].ent[nb].name_spr, NULL);
    rpg.scn[nb_scene].ent[nb].spr = sfSprite_create();
    if (nb_scene == 3 && nb == 0)
        sfSprite_setScale(rpg.scn[nb_scene].ent[nb].spr, scale_background);
    if (nb_scene == 3 && nb == 1)
        sfSprite_setScale(rpg.scn[nb_scene].ent[nb].spr, scale_player);
    if (nb_scene == 3 && nb == 2)
        sfSprite_setScale(rpg.scn[nb_scene].ent[nb].spr, scale_end_fight);
    sfSprite_setTexture(rpg.scn[nb_scene].ent[nb].spr,
    rpg.scn[nb_scene].ent[nb].text, sfTrue);
    sfSprite_setTextureRect(rpg.scn[nb_scene].ent[nb].spr,
    rpg.scn[nb_scene].ent[nb].rect);
    return (rpg);
}

rpg_t attribute_sprite(rpg_t rpg, int nb, int nb_scene)
{
    rpg.scn[nb_scene].ent[nb].text =
    sfTexture_createFromFile(rpg.scn[nb_scene].ent[nb].name_spr, NULL);
    rpg.scn[nb_scene].ent[nb].spr = sfSprite_create();
    rpg = scale_sprite(rpg, nb, nb_scene);
    sfSprite_setTexture(rpg.scn[nb_scene].ent[nb].spr,
    rpg.scn[nb_scene].ent[nb].text, sfTrue);
    return (rpg);
}

rpg_t init_sprite(rpg_t rpg)
{
    int nb_scene = 0;

    rpg = attribute_sprite(rpg, 0, nb_scene);
    nb_scene++;
    for (int i = 0; i != 8; i++)
        rpg = attribute_sprite(rpg, i, nb_scene);
    nb_scene++;
    rpg = attribute_sprite(rpg, 0, 2);
    nb_scene++;
    for (int i = 0; i != 3; i++)
        rpg = attribute_map_sprite(rpg, i, nb_scene);
    return (rpg);
}