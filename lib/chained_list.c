/*
** EPITECH PROJECT, 2021
** chained_list.c
** File description:
** manage chained list
*/

#include "lib.h"
#include <stddef.h>
#include <stdlib.h>

command_list_t *create_cell(char **data, char *delimiter)
{
    command_list_t *cell = malloc(sizeof(*cell));

    cell->command = data;
    cell->delimiter = delimiter;
    cell->next = NULL;
    return (cell);
}

void free_list(command_list_t *list)
{
    command_list_t *tmp = NULL;

    while (list) {
        tmp = list->next;
        if (list->command)
            free_array(list->command);
        if (list->delimiter)
            free(list->delimiter);
        free(list);
        list = tmp;
    }
}

command_list_t *add_inlist(command_list_t *list, char **data,
    char *delimiter, int pos)
{
    command_list_t *prev = list;
    command_list_t *curr = list;
    command_list_t *cell = create_cell(data, delimiter);

    if (!list)
        return (cell);
    if (pos == 0) {
        cell->next = list;
        return (cell);
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = cell;
    cell->next = curr;
    return (list);
}

int len_list(command_list_t *list)
{
    int i = 0;

    for (; list; i += 1)
        list = list->next;
    return (i);
}
