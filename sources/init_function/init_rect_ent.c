/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** init_rect_ent
*/

#include "rpg.h"

rpg_t rect_scn_fight(rpg_t rpg)
{
    sfIntRect fight_back = {0, 0, 1095, 730};
    sfIntRect boss_final = {0, 0, 507, 431};
    sfIntRect fairy = {0, 0, 236, 222};
    sfIntRect glue = {0, 0, 129, 108};
    sfIntRect little_boss = {0, 0, 425, 674};

    rpg.scn[1].ent[0].rect = fight_back;
    rpg.scn[1].ent[1].rect = fight_back;
    rpg.scn[1].ent[2].rect = fight_back;
    rpg.scn[1].ent[3].rect = fight_back;
    rpg.scn[1].ent[4].rect = boss_final;
    rpg.scn[1].ent[5].rect = fairy;
    rpg.scn[1].ent[6].rect = glue;
    rpg.scn[1].ent[7].rect = little_boss;
    return (rpg);
}

rpg_t rect_scn_map(rpg_t rpg)
{
    sfIntRect background = {0, 0, 1800, 1800};
    sfIntRect player = {0, 0, 48, 48};
    sfIntRect win_or_loose = {0, 0, 195, 259};

    rpg.scn[3].ent[0].rect = background;
    rpg.scn[3].ent[1].rect = player;
    rpg.scn[3].ent[2].rect = win_or_loose;
    return (rpg);
}

rpg_t init_rect_ent(rpg_t rpg)
{
    sfIntRect menu = {0, 0, 1080, 720};
    sfIntRect how_to_play = {0, 0, 2600, 800};

    rpg.scn[0].ent[0].rect = menu;
    rpg.scn[2].ent[0].rect = how_to_play;
    rpg = rect_scn_fight(rpg);
    rpg = rect_scn_map(rpg);
    return (rpg);
}