/*
** EPITECH PROJECT, 2022
** is_impair
** File description:
** is_x_impair
*/
#include "src.h"

int is_x_impair(int set, int get)
{
    static int impair = FALSE;
    if (get == TRUE)
        return (impair);
    if (set == TRUE)
        impair = TRUE;
    return (impair);
}
