/*
** base.c for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/core/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:55:02 2017 Bender_Rodriguez
** Last update Sun Mar  5 05:55:15 2017 Bender_Rodriguez
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
