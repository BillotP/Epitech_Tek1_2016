/*
** main.c for Minishell1 in /home/bender/REpO/TEk1/PSU_2016_minishell1/v1.3_stable/srcs/
**
** Made by John Doe
** Login   <Bender@epitech.eu>
**
** Started on  Sat Jan 21 16:08:24 2017 John Doe
** Last update	Sun Jan 22 09:52:29 2017 Full Name
*/

#include "shell1.h"
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>

int					execshell(char **environ, t_env *list)
{
  char			*clean_input;
  char			**turn_intoargs;
  int				status;
  pid_t			child;

  while ((clean_input = clean_args(get_next_line(STDIN_FILENO))))
    {
      if ((isatty(0)))
	p_printf(1, "42sh>> ");
      if (clean_input[0] == '\f')
	p_printf(1, "\x1b[2J\x1b[1;1H");
      turn_intoargs = strto_wordtab(clean_input, " ");
      child = fork();
      while ((waitpid(child, &status, 0)) == -1)
	execve(turn_intoargs[0], turn_intoargs, environ);
      clean_free(clean_input);
    }
  free_list(list);
  clean_free(clean_input);
  return (0);
}
int					main(int ac, char **av, char **environ)
{
  t_env			*env;

  ac = ac + 42;
  av = av + 42;
  env = env_inlist(environ);
  if ((isatty(0)))
    pprint("42sh>> ", 1);
  if ((execshell(environ, env)) == 1)
    return (1);
  return (0);
}
