/*
** base.c for Minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:10:35 2017 John Doe
** Last update	Sat Jan 21 10:45:48 2017 Full Name
*/

#include "../../include/errors.h"
#include "../../include/base.h"
#include <stdlib.h>

int					pprint(const char *str, int fd)
{
  ssize_t		wr;

  wr = 0;
  if ((wr = write(fd, str, len(str))) == -1)
    errors(FDERR, 84);
  return (0);
}
void				*removetrailingspace(char *str)
{
  if (str[0] == ' ' || str[0] == '\t')
    {
      while (*str == ' ' || *str == '\t')
	str++;
      return (str);
    }
  return (str);
}
char			*my_malloc(char *str, size_t len)
{
  if ((str = malloc(sizeof(*str) * len)) == NULL)
    errors(strerror(errno), 84);
  return (str);
}
char  		*clean_args(char *str)
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
