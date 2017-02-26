/*
** error.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/core/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:19:37 2017 John Doe
** Last update Fri Feb 10 09:19:46 2017 John Doe
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include "errors.h"
#include "base.h"

int		p_exit(const char *str, int exitval)
{
  write(2, str, len(str));
  _exit (exitval);
}
int		errors(const char *errmsg, int exitval)
{
  write(2, errmsg, len(errmsg));
  _exit (exitval);
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
