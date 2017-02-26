/*
** base.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/core/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:19:59 2017 John Doe
** Last update Sun Feb 19 08:40:21 2017 John Doe
*/

#include <unistd.h>
#include <stdlib.h>

#include "base.h"

int					pprint(const char *str, int fd)
{
  ssize_t		wr;

  wr = 0;
  if ((wr = write(fd, str, len(str))) == -1)
    return (84);
  return (0);
}

char			*my_malloc(char *str, size_t len)
{
  if ((str = malloc(sizeof(*str) * len)) == NULL)
    return (NULL);
  return (str);
}
char			**freetab(char **ptr)
{
  int			i;
  int			j;

  i = 0;
  j = 0;
  while (ptr[i])
    i++;
  while (j < i)
    {
      free(ptr[j]);
      ptr[j] = NULL;
      j++;
    }
  free(ptr);
  return (NULL);
}
char			*clean_free(char *ptr)
{
  if (ptr)
    {
      free(ptr);
      ptr = NULL;
    }
  return (NULL);
}
int			my_atoi(const char *str)
{
  int		nb;

  nb = 0;
  while (*str)
    {
      if (*str >= '0' && *str <= '9')
	{
	  nb *= 10;
	  nb += *str - 48;
	}
      else
	return (nb);
      str++;
    }
  return (nb);
}
