/*
** EPITECH PROJECT, 2022
** handle_lem_in
** File description:
** ants_move_all
*/
/**
 * @file ants_move_all.c
 *
 * @brief Has function that handle all ant's move
 *
 * @date 04/04/2023
*/
#include "src.h"

static void print_space(bool has_print)
{
    if (has_print)
        z_printf(" ");
}

static void handle_move(graph_element_t *graph, u_int i, u_int way,
    bool *has_print)
{
    if (graph->ants[i] == 0)
        graph->nb_ants_start--;
    if (graph->ants[i] == graph->nb_vertices -1)
        return;
    if (way == graph->nb_vertices -1)
        graph->nb_ants_end++;
    ant_move(graph, i, way);
    (*has_print) = true;
}

void ants_move_all(graph_element_t *graph, info_t *info)
{
    u_int way = 0;
    bool has_print = false;

    for (u_int i = 0; i < graph->ants_max; i++) {
        way = find_way(graph, graph->ants[i]);
        if (graph->rooms[way] == false || way == graph->nb_vertices - 1) {
            print_space(has_print);
            handle_move(graph, i, way, &has_print);
        }
    }
}
