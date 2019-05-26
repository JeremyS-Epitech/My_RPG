/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** init_pos_ent
*/

#include "rpg.h"

rpg_t pos_scn_map(rpg_t rpg)
{
    sfVector2f pos_background = {-1840, -1740};
    sfVector2f win_or_loose = {550, 200};
    sfVector2f pos_player = {650, 400};

    rpg.scn[3].ent[0].pos = pos_background;
    rpg.scn[3].ent[1].pos = pos_player;
    rpg.scn[3].ent[2].pos = win_or_loose;
    return (rpg);
}

rpg_t pos_entity(rpg_t rpg)
{
    sfVector2f pos = {400, 160};
    sfVector2f pos_little_boss = {460, 193};
    sfVector2f pos_fairy = {600, 250};
    sfVector2f pos_glue = {600, 450};

    rpg.scn[1].ent[4].pos = pos;
    rpg.scn[1].ent[7].pos = pos_little_boss;
    rpg.scn[1].ent[5].pos = pos_fairy;
    rpg.scn[1].ent[6].pos = pos_glue;
    return (rpg);
}

rpg_t init_pos_ent(rpg_t rpg)
{
    sfVector2f pos_fight = {0, 0};
    sfVector2f pos = {400, 130};
    sfVector2f pos_how_to_play = {0, 0};

    rpg.scn[0].ent[0].pos = pos;
    rpg.scn[1].ent[0].pos = pos_fight;
    rpg.scn[1].ent[1].pos = pos_fight;
    rpg.scn[1].ent[2].pos = pos_fight;
    rpg.scn[1].ent[3].pos = pos_fight;
    rpg.scn[2].ent[0].pos = pos_how_to_play;
    rpg = pos_scn_map(rpg);
    rpg = pos_entity(rpg);
    return (rpg);
}