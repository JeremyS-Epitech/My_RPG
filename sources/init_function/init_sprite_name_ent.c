/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** init_sprite_name_ent
*/

#include "rpg.h"

rpg_t name_sprite_scn_fight(rpg_t rpg)
{
    rpg.scn[1].ent[0].name_spr = "ressources/sprites/enemies_turn.png";
    rpg.scn[1].ent[1].name_spr = "ressources/sprites/enemies_with_shield.png";
    rpg.scn[1].ent[2].name_spr = "ressources/sprites/your_turn.png";
    rpg.scn[1].ent[3].name_spr = "ressources/sprites/your_turn_shield.png";
    rpg.scn[1].ent[4].name_spr = "ressources/entity/final_boss.png";
    rpg.scn[1].ent[5].name_spr = "ressources/entity/Fairy.png";
    rpg.scn[1].ent[6].name_spr = "ressources/entity/Glue.png";
    rpg.scn[1].ent[7].name_spr = "ressources/entity/little_boss.png";
    return (rpg);
}

rpg_t name_sprite_scn_map(rpg_t rpg)
{
    rpg.scn[3].ent[2].name_spr = "ressources/sprites/win_or_loose.png";
    rpg.scn[3].ent[0].name_spr = "ressources/sprites/map2.png";
    rpg.scn[3].ent[1].name_spr = "ressources/sprites/player_move.png";
    return (rpg);
}

rpg_t init_sprite_name_ent(rpg_t rpg)
{
    rpg.scn[0].ent[0].name_spr = "ressources/sprites/menu.png";
    rpg.scn[2].ent[0].name_spr = "ressources/sprites/how_to_play_spr.jpg";
    rpg = name_sprite_scn_fight(rpg);
    rpg = name_sprite_scn_map(rpg);
    return (rpg);
}