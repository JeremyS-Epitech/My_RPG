/*
** EPITECH PROJECT, 2019
** MUL_my_rpg
** File description:
** manage_music
*/

#include "rpg.h"

bool is_music_play(sfMusic *music)
{
    if (sfMusic_getStatus(music) == sfPlaying)
        return (true);
    return (false);
}

rpg_t launch_music_in_scene_three(rpg_t rpg)
{
    if (is_music_play(rpg.music[0]) == true)
        sfMusic_stop(rpg.music[0]);
    if (is_music_play(rpg.music[1]) == true)
        sfMusic_stop(rpg.music[1]);
    sfMusic_play(rpg.music[2]);
    return (rpg);
}

rpg_t launch_music_in_scene_one(rpg_t rpg)
{
    if (is_music_play(rpg.music[0]) == true)
        sfMusic_stop(rpg.music[0]);
    if (is_music_play(rpg.music[2]) == true)
        sfMusic_stop(rpg.music[2]);
    sfMusic_play(rpg.music[1]);
    return (rpg);
}

rpg_t launch_music_in_scene_zero(rpg_t rpg)
{
    if (is_music_play(rpg.music[1]) == true)
        sfMusic_stop(rpg.music[1]);
    if (is_music_play(rpg.music[2]) == true)
        sfMusic_stop(rpg.music[2]);
    sfMusic_play(rpg.music[0]);
    return (rpg);
}

rpg_t manage_music(rpg_t rpg)
{
    if (rpg.nb == 0 && is_music_play(rpg.music[0]) != true)
        rpg = launch_music_in_scene_zero(rpg);
    if (rpg.nb == 1 && is_music_play(rpg.music[1]) != true)
        rpg = launch_music_in_scene_one(rpg);
    if (rpg.nb == 3 && is_music_play(rpg.music[2]) != true)
        rpg = launch_music_in_scene_three(rpg);
    return (rpg);
}