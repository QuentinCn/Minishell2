/*
** EPITECH PROJECT, 2021
** lib.h
** File description:
** .h of the lib
*/

#ifndef LIB
#define LIB

#include "structure.h"

char **my_str_to_word_array(char *str, char separation);
char *my_strdup(char const *str);
char *concat_str(char *str1, char *str2, char concat);
void free_array(char **array);
int my_strcmp(char *str1, char *str2);
int array_len(char **array);
char *cut_env_line(char *env_line);
char **concat_array(char **array1, char **array2);
char **delete_line_in_array(char **array, int pos);
command_list_t *create_cell(char **data, char *delimiter);
void free_list(command_list_t *list);
command_list_t *add_inlist(command_list_t *list, char **data,
    char *delimiter, int pos);
int len_list(command_list_t *list);

#endif /* !LIB */
