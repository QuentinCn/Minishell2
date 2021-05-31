/*
** EPITECH PROJECT, 2021
** tests_minishell2.c
** File description:
** tests for minishell2 project
*/

#include "minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(do_exit, test_exit_error, .init=cr_redirect_stdout)
{
    char *command[] = {"exit", "a", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_exit(command, env);
    cr_assert_stdout_eq_str("exit: Expression Syntax.\n");
}

Test(add_command_prefix, test_add_command_prefix)
{
    char *env[] = {"a=b", "PATH=/usr/condabin:/usr/local/bin:/usr/bin:/bin:/home/Quentin/bin:/usr/local/sbin:/usr/sbin", "d=e", NULL};
    char *command[] = {"ls", "-l", NULL};
    char *result = add_command_prefix(command, env);
    char expected[] = "/usr/bin/ls";

    cr_assert_str_eq(expected, result);
}

Test(add_command_prefix, test_add_command_prefix_path_null)
{
    char *env[] = {"a=b", "d=e", NULL};
    char *command[] = {"ls", "-l", NULL};
    char *result = add_command_prefix(command, env);

    cr_assert_null(result);
}

Test(add_command_prefix, test_add_command_prefix_error, .init=cr_redirect_stdout)
{
    char *env[] = {"a=b", "PATH=a", "d=e", NULL};
    char *command[] = {"ls", "-l", NULL};
    char *result = add_command_prefix(command, env);

    cr_assert_null(result);
}

Test(add_command_prefix, test_without_adding_prefix, .init=cr_redirect_stdout)
{
    char *env[] = {"a=b", "PATH=a", "d=e", NULL};
    char *command[] = {"./unit_tests", NULL};
    char *result = add_command_prefix(command, env);
    char expected[] = "./unit_tests";

    cr_assert_str_eq(expected, result);
}

Test(command, execute_command_1, .init=cr_redirect_stdout)
{
    char *env[] = {"a=b", "PATH=/usr/condabin:/usr/local/bin:/usr/bin:/bin:/home/Quentin/bin:/usr/local/sbin:/usr/sbin", "d=e", NULL};
    command_list_t *command_list = create_command_list("echo a");
    char expected[] = "a\n";

    execute_command(command_list, env);
    cr_assert_stdout_eq_str(expected);
    free_list(command_list);
}

Test(find_act_dir, find_act_dir)
{
    char *pathname = NULL;
    char expected[] = "B-PSU-210-PAR-2-1-minishell2-quentin.caniou";
    char *result = find_act_dir(pathname);

    cr_assert_str_eq(expected, result);
}

Test(find_old_pathname, find_old_pathname)
{
    char *pathname = NULL;
    char *env[] = {"a=b", "d=e", NULL};
    char *result = find_old_pathname(env, pathname);

    cr_assert_null(result);
}
