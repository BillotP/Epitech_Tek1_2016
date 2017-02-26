/*
** check_dir.c for Minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 23:30:21 2017 John Doe
** Last update	Thu Jan 19 15:20:28 2017 Full Name
*/

#include "base.h"
#include "errors.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int					findgoodpath(const char *name, char **paths)
{
  int				pos;
  static int i = 0;

  pos = 0;
  if ((!(name)) || (!(paths)))
    return (-1);
  if ((check_thatbinary(name)) == 0)
    return (1);
  if (i == 0)
    while (paths[pos] != NULL)
	{
	  paths[pos] = my_strcat(paths[pos], "/");
	  pos++;
	}
  i++;
  pos = 0;
  while (paths[pos] != NULL)
    {
      if ((check_thatbinary(my_strcat(paths[pos], name))) == 0)
	return (pos);
      pos++;
    }
  return (-1);
}

int		check_thatbinary(const char *name)
{
  if (access(name, F_OK) == -1 || access(name, X_OK) == -1)
    return (1);
  return (0);
}
