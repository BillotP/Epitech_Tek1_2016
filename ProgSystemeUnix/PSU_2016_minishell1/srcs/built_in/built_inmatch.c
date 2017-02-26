/*
** built_inmatch.c for builtinmatch in /home/bender/Repo/PSU_2016_minishell1/v1.2/srcs/built_in/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Jan 17 23:49:52 2017 John Doe
** Last update	Sun Jan 22 14:09:48 2017 Full Name
*/

#include "../../include/shell1.h"

void	get_out(int exitval)
{
  if ((isatty(0)))
    pprint("exit\n", 1);
  exit (exitval);
}
int			built_in(char *user_input, char **environ)
{
  char	**args;

  args = strto_wordtab(user_input, " ");
  if ((strn_cmp(args[0], "exit", len(args[0]))))
    get_out(my_atoi(args[1]));
  if ((strn_cmp(args[0], "setenv", len(args[0]))))
    {
      if ((environ = set_environ(user_input, environ)))
	return (0);
      return (1);
    }
  if ((strn_cmp(args[0], "unsetenv", len(args[0]))))
    {
      if ((environ = unset_environ(user_input, environ)))
	return (0);
      return (1);
    }
  if ((strn_cmp(args[0], "cd", len(args[0]))))
    {
      if ((change_path(user_input, environ)))
	return (1);
      return (0);
    }
  return (1);
}
