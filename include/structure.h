/*
** EPITECH PROJECT, 2021
** minishell2.h
** File description:
** .h of the minishell2 project structure
*/

#ifndef STRUCTURE
#define STRUCTURE

typedef struct tab_on_fct_s {
    char *arg;
    char **(*function) (char **command, char **env);
} tab_on_fct_t;

typedef struct command_list_s {
    char **command;
    char *delimiter;
    struct command_list_s *next;
}command_list_t;

#endif /* !STRUCTURE */
