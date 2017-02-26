/*
** shell1.h for minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:49:04 2017 John Doe
** Last update	Sat Jan 21 22:04:18 2017 Full Name
*/

#ifndef SHELL1_H_
# define SHELL1_H_

#include <unistd.h>
#include <sys/types.h>

/*
** My stdfunky base :
*/
#include "base.h"
#include "errors.h"
#include "p_printf.h"
/*
** THe MostFamous GNL in town
*/
#include "get_next_line.h"
/*
** Char **env ? NO!!
** better a chained list!
*/
#include "setenv.h"
/*
** strtowordtab here we are !
*/
#include "strtowordtab.h"

/*
** Classic bold shitty prompt
*/
#define PROMPT "\x1b[1mMysh>>\x1b[0m "
/*
** Better prompt :
*/
char		*foo;
#define FKNYPRMPT my_strcat(getcwd(foo, 1000) + len("/home/"), "> ")

/*
**************************
** Now real stuff began :
**************************
*/
typedef struct  s_shell {
  char	**paths;
  char	**args;
  char	*tmpenv;
  char	*clean_input;
  t_env	*env;
}								t_shell;

typedef struct s_pid {
  int		wstatus;
  int		sonpid;
  pid_t ctrl;
}							t_pid;

/*
** Core shell functions
*/
char	**dup_env(char **env);
// char	**init_shell(t_shell *list, char **environ);
int		find_inenv(char **env, const char *str);
int		exec_that(char **environ);
int		forkandrun(t_shell *ptr, char **env);

/*
** Built_in start here !
*/
int			built_in(char *user_input, char **environ);
int			change_path(char *user_input, char **environ);
char		**unset_environ(char *user_input, char **environ);
char		**set_environ(char *user_input, char **environ);

/*
** Tmp env in case of env -i ;)
*/
#define TENV	"PATH=/bin:/sbin:/usr/bin:/usr/sbin PWD=x OLDPWD=x TERM=xterm \
SHELL=mysh HOME=/home"

#endif
