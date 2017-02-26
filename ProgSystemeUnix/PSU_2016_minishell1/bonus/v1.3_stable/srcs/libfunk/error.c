/*
** error.c for Minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:40:27 2017 John Doe
** Last update	Sat Jan 21 18:12:04 2017 Full Name
*/

#include "errors.h"
#include "base.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int		p_exit(const char *str, int exitval)
{
  write(2, str, len(str));
  return (exitval);
}
int		errors(const char *errmsg, int exitval)
{
  write(2, errmsg, len(errmsg));
  exit (exitval);
}

const  char				*removetrailingspace(const char *str)
{
  if (str[0] == ' ' || str[0] == '\t')
    {
      while (*str == ' ' || *str == '\t')
	str++;
      return (str);
    }
  return (str);
}

char  		*clean_args(const char *str)
{
  char		*clean = NULL;
  int			i;

  i = 0;
  if (str == NULL)
    return (NULL);
  str = removetrailingspace(str);
  clean = my_malloc(clean, len(str) + 1);
  while (str[i] != '\0')
    if ((str[i] == ' ' || str[i] =='\t') && (str[i + 1] != ' ' && str[i + 1] \
	 != '\t'))
	{
	  clean[i] = str[i];
	  i = i + 1;
	}
  else  if (str[i] != ' ' && str[i] != '\t')
    {
      clean[i] = str[i];
      i = i + 1;
    }
  else if (str[i] == ' ' || str[i] == '\t')
    str++;
  clean[i] = '\0';
  return (clean);
}
