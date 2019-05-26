/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** init_game_object_value
*/

#include "rpg.h"

rpg_t init_malloc(rpg_t rpg)
{
    rpg.scn = malloc(sizeof(rpg.scn) * 100);
    if (rpg.scn == NULL) {
        rpg.is_error = -1;
        return (rpg);
    }
    rpg.scn[0].ent = malloc(sizeof(rpg.scn->ent) * 100);
    rpg.scn[0].butt = malloc(sizeof(rpg.scn->butt) * 100);
    rpg.scn[1].ent = malloc(sizeof(rpg.scn->ent) * 100);
    rpg.scn[1].butt = malloc(sizeof(rpg.scn->butt) * 100);
    rpg.scn[2].ent = malloc(sizeof(rpg.scn->ent) * 100);
    rpg.scn[2].butt = malloc(sizeof(rpg.scn->butt) * 10);
    rpg.scn[3].ent = malloc(sizeof(rpg.scn->ent) * 100);
    rpg.scn[3].butt = malloc(sizeof(rpg.scn->butt) * 100);
    if (rpg.scn[0].ent == NULL || rpg.scn[0].butt == NULL
    || rpg.scn[1].ent == NULL || rpg.scn[1].butt == NULL
    || rpg.scn[3].ent == NULL || rpg.scn[3].butt == NULL) {
        rpg.is_error = -1;
        return (rpg);
    }
    return (rpg);
}

rpg_t init_game_object_value(rpg_t rpg)
{
    rpg = init_malloc(rpg);
    if (rpg.is_error != 0)
        return (rpg);
    rpg.scn[1].turn = 2;
    rpg = init_music(rpg);
    rpg = init_button(rpg);
    rpg = init_sprite_name_ent(rpg);
    rpg = init_rect_ent(rpg);
    rpg = init_pos_ent(rpg);
    rpg = init_sprite(rpg);
    rpg = init_caract_ent(rpg);
    rpg = init_player(rpg);
    rpg = init_battle_area(rpg);
    rpg = init_text(rpg);
    return (rpg);
}