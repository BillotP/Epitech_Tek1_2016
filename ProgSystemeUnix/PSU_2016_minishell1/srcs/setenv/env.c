/*
** env.c for Minishell1 in /home/bender/Repo/PSU_2016_minishell1/v1.2/srcs/minishell1/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Jan 18 10:02:30 2017 John Doe
** Last update Wed Jan 18 10:32:00 2017 John Doe
*/

#include "../../include/errors.h"
#include "../../include/base.h"
#include <stdlib.h>

char			**dup_env(char **env)
{
  char		**env_copy;
  static	int i = 0;

  while (env[i] != NULL)
    i = i + 1;
  if ((env_copy = malloc(sizeof(*env_copy) * i + 1)) == NULL)
    errors("malloc error", 84);
  i = 0;
  while (env[i] != NULL)
    {
      env_copy[i] = my_strdup(env[i]);
      i++;
    }
  env_copy[i - 1] = NULL;
  return (env_copy);
}
int				find_inenv(char **env, const char *str)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if ((strn_cmp(env[i], str, len(str))))
	return (i);
      i++;
    }
  return (0);
}
