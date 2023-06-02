/*
** EPITECH PROJECT, 2022
** parser
** File description:
** parser
*/

#ifndef PARSER
    #define PARSER

    #include <stdlib.h>
    #define UNUSED __attribute__((unused))
    #define NB_COLS 3
    #define START "##start"
    #define END "##end"
    #define LINKS 2

typedef struct rooms_s {
    char *name;
    size_t x;
    size_t y;
    list_int_t *list;
} rooms_t;


/**
 * @brief this struct contains all the info about the file
 *
 */
typedef struct info_s {
    size_t idx_to_print;
    rooms_t *room;
    size_t idx_to_start;
    size_t nb_ants;
    char **rooms;
    char **start;
    char **end;
    char **file;
    char **file_to_parse;
    char **cells;
    int nb_start;
    size_t nb_cells;
    size_t count;
    size_t j;
} info_t;

typedef struct parser_s {
    size_t nb_start;
    size_t nb_end;
    size_t nb_rooms;
    char **pars;
    link_t *link;
} parser_t;

/**
 * @brief puts the content in the file in a the structure info
 *
 * @param info
 * @return false
 * @return true
 */
bool file_to_info(info_t *info);

/**
 * @brief Get the info from file and set them in the structure
 *
 * @param info
 * @return true
 * @return false
 */
bool get_info_from_files(info_t *info);


/**
 * @brief Get the all the rooms object
 *
 * @param info
 * @return char**
 */
char **get_all_the_rooms(info_t *info);

/**
 * @brief Get the room object this function returns the rooms choised
 *
 * @param info
 * @param to_find
 * @param room
 * @return char**
 */
char **get_room(info_t *info, char *const to_find, char **room);

/**
 * @brief Get the the linkers from the file
 *
 * @param info
 */
bool get_all_info_to_struc_tab(info_t *info);

/**
 * @brief Check all the links and if there is a start and end
 *
 * @param info
 */
bool check_links(info_t *info);


/**
 * @brief check if there is a char in a string
 *
 * @param str
 * @param to_find
 * @return true
 * @return false
 */
bool str_contains_char(char const *str, char to_find);


/**
 * @brief Get the alls the rooms linked from cells
 *
 * @param info
 */
bool get_alls_the_rooms_linked(info_t *info);


/**
 * @brief this functions check if the file has postions and if they exist
 *
 * @param pars
 * @param info
 * @param j
 * @return true
 * @return false
 */
bool check_if_pos_exist(char **pars, info_t *info, size_t *j);

/**
 * @brief Get the position start end rooms
 *
 * @param info
 * @param to_find
 * @param j
 * @return true
 * @return false
 */
bool get_position_start_end(info_t *info, char const *to_find, size_t j);

/**
 * @brief check if rooms has the same positions
 *
 * @param info
 * @param i
 * @return true
 * @return false
 */
bool check_same_pos(info_t *info, size_t i);

/**
 * @brief display file and check line by line
 *
 * @param pars
 * @param info
 * @param i
 * @return true
 * @return false
 */
bool display_error_parsed(parser_t *pars, info_t *info, size_t i);

/**
 * @brief display the errors in the parsing
 *
 * @param info
 * @param pars
 */
void display_error(info_t *info, parser_t *pars);

bool add_to_link(char **pars, link_t *link);
bool check_rooms(char **pars, size_t *nb_start, size_t *nb_end);
void diplay_error_tunnels(info_t *info, char **pars, int i, link_t *link);
bool check_same_coordinates(char **pars, info_t *info, size_t i);
bool check_if_name_alredy_exists(char *name, link_t *link, bool room);
int get_idx_rooms(info_t *info, char const *room);
#endif /* PARSER */
