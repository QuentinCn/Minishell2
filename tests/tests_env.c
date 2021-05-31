/*
** EPITECH PROJECT, 2021
** tests_minishell2.c
** File description:
** tests for minishell2 project
*/

#include "minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(do_env, test_do_env, .init=cr_redirect_stdout)
{
    char *command[] = {"env", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_env(command, env);
    cr_assert_stdout_eq_str("a=b\nb=c\nd=e\n");
}

Test(do_env, test_do_env_error, .init=cr_redirect_stdout)
{
    char *command[] = {"env", "a", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_env(command, env);
    cr_assert_stdout_eq_str("env: 'a': No such file or directory\n");
}

Test(do_setenv, test_do_setenv_0arg, .init=cr_redirect_stdout)
{
    char *command[] = {"setenv", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_setenv(command, env);
    cr_assert_stdout_eq_str("a=b\nb=c\nd=e\n");
}

Test(execute_command, test_setenv_1arg)
{
    command_list_t *command_list = create_command_list("setenv f");
    char *env[] = {"a=b", "b=c", "d=e", NULL};
    char *expected[] = {"a=b", "b=c", "d=e", "f=", NULL};
    char **result = NULL;

    result = execute_command(command_list, env);
    for (int i = 0; result[i] && expected[i]; ++i)
        cr_assert_str_eq(result[i], expected[i]);
}

Test(execute_command, test_setenv_2arg)
{
    command_list_t *command_list = create_command_list("setenv f b");
    char *env[] = {"a=b", "b=c", "d=e", NULL};
    char *expected[] = {"a=b", "b=c", "d=e", "f=b", NULL};
    char **result = NULL;

    result = execute_command(command_list, env);
    for (int i = 0; result[i] && expected[i]; ++i)
        cr_assert_str_eq(result[i], expected[i]);
}

Test(execute_command, test_setenv_2arg_match)
{
    command_list_t *command_list = create_command_list("setenv a f");
    char *env[] = {"a=b", "b=c", "d=e", NULL};
    char *expected[] = {"a=f", "b=c", "d=e", NULL};
    char **result = NULL;

    result = execute_command(command_list, env);
    for (int i = 0; result[i] && expected[i]; ++i)
        cr_assert_str_eq(result[i], expected[i]);
}

Test(execute_command, test_setenv_1arg_match)
{
    command_list_t *command_list = create_command_list("setenv a");
    char *env[] = {"a=b", "b=c", "d=e", NULL};
    char *expected[] = {"a=", "b=c", "d=e", NULL};
    char **result = NULL;

    result = execute_command(command_list, env);
    for (int i = 0; result[i] && expected[i]; ++i)
        cr_assert_str_eq(result[i], expected[i]);
}

Test(do_setenv, test_do_setenv_error, .init=cr_redirect_stdout)
{
    char *command[] = {"setenv", "a", "b", "c", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_setenv(command, env);
    cr_assert_stdout_eq_str("setenv: Too many arguments.\n");
}

Test(execute_command, test_unsetenv_multiple_arg)
{
    command_list_t *command_list = create_command_list("unsetenv f a");
    char *env[] = {"a=b", "b=c", "d=e", NULL};
    char *expected[] = {"b=c", "d=e", NULL};
    char **result = NULL;

    result = execute_command(command_list, env);
    for (int i = 0; result[i] && expected[i]; ++i)
        cr_assert_str_eq(result[i], expected[i]);
}

Test(do_setenv, test_do_unsetenv_error, .init=cr_redirect_stdout)
{
    command_list_t *command_list = create_command_list("unsetenv");
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_unsetenv(command_list->command, env);
    cr_assert_stdout_eq_str("unsetenv: Too few arguments.\n");
}
