/*
** EPITECH PROJECT, 2021
** tests_minishell2.c
** File description:
** tests for minishell2 project
*/

#include "minishell2.h"
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(do_cd, test_do_cd_2_arg, .init=cr_redirect_stdout)
{
    char *command1[] = {"cd", "lib", NULL};
    char *command2[] = {"env", NULL};
    char *env[] = {"a=b", "b=c", "d=e", "PWD=/home/Quentin/delivery/minishell2/B-PSU-210-PAR-2-1-minishell2-quentin.caniou", "OLDPWD=/home/Quentin", NULL};

    do_env(command2, do_cd(command1, env));
    cr_assert_stdout_eq_str("a=b\nb=c\nd=e\nPWD=/home/Quentin/delivery/minishell2/B-PSU-210-PAR-2-1-minishell2-quentin.caniou/lib\nOLDPWD=/home/Quentin/delivery/minishell2/B-PSU-210-PAR-2-1-minishell2-quentin.caniou\n");
}

Test(do_cd, test_do_cd_minus, .init=cr_redirect_stdout)
{
    char *command1[] = {"cd", "lib", NULL};
    char *command2[] = {"env", NULL};
    char *command3[] = {"cd", "-", NULL};
    char *env[] = {"a=b", "b=c", "d=e", "PWD=/home/Quentin/delivery/minishell2/B-PSU-210-PAR-2-1-minishell2-quentin.caniou", "OLDPWD=/home/Quentin", NULL};

    do_env(command2, do_cd(command3, do_cd(command1, env)));
    cr_assert_stdout_eq_str("a=b\nb=c\nd=e\nPWD=/home/Quentin/delivery/minishell2/B-PSU-210-PAR-2-1-minishell2-quentin.caniou\nOLDPWD=/home/Quentin/delivery/minishell2/B-PSU-210-PAR-2-1-minishell2-quentin.caniou/lib\n");
}

Test(do_cd, test_do_cd_2_arg_error, .init=cr_redirect_stdout)
{
    char *command1[] = {"cd", "a", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_cd(command1, env);
    cr_assert_stdout_eq_str("a: No such file or directory.\n");
}

Test(do_cd, test_do_cd_not_a_directory, .init=cr_redirect_stdout)
{
    char *command1[] = {"cd", "/bin/ls", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_cd(command1, env);
    cr_assert_stdout_eq_str("/bin/ls: Not a directory.\n");
}

Test(do_cd, test_do_cd_1_arg/* , .init=cr_redirect_stdout */)
{
    char *command1[] = {"cd", NULL};
    char *command2[] = {"env", NULL};
    char *env[] = {"HOME=/home/Quentin", "PWD=/home/Quentin/delivery/minishell2/B-PSU-210-PAR-2-1-minishell2-quentin.caniou", "OLDPWD=/home/Quentin", NULL};

    do_env(command2, do_cd(command1, env));
    /* cr_assert_stdout_eq_str("HOME=/home/Quentin\nPWD=/home/Quentin\nOLDPWD=/home/Quentin/delivery/minishell2/B-PSU-210-PAR-2-1-minishell2-quentin.caniou\n"); */
}

Test(do_cd, test_do_cd_1_arg_error, .init=cr_redirect_stdout)
{
    char *command1[] = {"cd", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_cd(command1, env);
    cr_assert_stdout_eq_str("cd: No home directory.\n");
}

Test(do_cd, test_do_cd_too_many_arg, .init=cr_redirect_stdout)
{
    char *command1[] = {"cd", "lib", "include", NULL};
    char *env[] = {"a=b", "b=c", "d=e", NULL};

    do_cd(command1, env);
    cr_assert_stdout_eq_str("cd: Too many arguments.\n");
}
