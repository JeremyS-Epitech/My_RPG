/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** init_button
*/

#include "rpg.h"

rpg_t init_other_button_menu(rpg_t rpg)
{
    rpg.scn[0].butt[3].size_y = 78;
    rpg.scn[0].butt[3].size_x = 339;
    rpg.scn[0].butt[3].pos_button_y = 636;
    rpg.scn[0].butt[3].pos_button_x = 71;
    return (rpg);
}

rpg_t init_button_menu(rpg_t rpg)
{
    rpg.scn[0].butt = malloc(sizeof(rpg.scn->butt) * 9);
    if (rpg.scn[0].butt == NULL) {
        rpg.is_error++;
        return (rpg);
    }
    rpg.scn[0].butt[0].size_y = 78;
    rpg.scn[0].butt[0].size_x = 339;
    rpg.scn[0].butt[0].pos_button_y = 534;
    rpg.scn[0].butt[0].pos_button_x = 71;
    rpg.scn[0].butt[1].size_y = 78;
    rpg.scn[0].butt[1].size_x = 339;
    rpg.scn[0].butt[1].pos_button_y = 330;
    rpg.scn[0].butt[1].pos_button_x = 71;
    rpg.scn[0].butt[2].size_y = 78;
    rpg.scn[0].butt[2].size_x = 339;
    rpg.scn[0].butt[2].pos_button_y = 432;
    rpg.scn[0].butt[2].pos_button_x = 71;
    rpg = init_other_button_menu(rpg);
    return (rpg);
}

rpg_t init_button_scn_two(rpg_t rpg)
{
    rpg.scn[1].butt = malloc(sizeof(rpg.scn->butt) * 9);
    if (rpg.scn[1].butt == NULL) {
        rpg.is_error++;
        return (rpg);
    }
    rpg.scn[1].butt[0].size_y = 73;
    rpg.scn[1].butt[0].size_x = 175;
    rpg.scn[1].butt[0].pos_button_y = 641;
    rpg.scn[1].butt[0].pos_button_x = 501;
    rpg.scn[1].butt[1].size_y = 71;
    rpg.scn[1].butt[1].size_x = 172;
    rpg.scn[1].butt[1].pos_button_y = 642;
    rpg.scn[1].butt[1].pos_button_x = 681;
    rpg.scn[1].butt[2].size_y = 58;
    rpg.scn[1].butt[2].size_x = 149;
    rpg.scn[1].butt[2].pos_button_y = 735;
    rpg.scn[1].butt[2].pos_button_x = 675;
    return (rpg);
}

rpg_t init_button(rpg_t rpg)
{
    rpg = init_button_menu(rpg);
    rpg = init_button_scn_two(rpg);
    if (rpg.is_error != 0)
        return (rpg);
    return (rpg);
}