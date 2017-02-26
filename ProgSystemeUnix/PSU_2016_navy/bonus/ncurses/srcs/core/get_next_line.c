/*
** get_next_line.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/core/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 10 09:21:28 2017 John Doe
** Last update Fri Feb 10 09:21:36 2017 John Doe
*/

#include <stdlib.h>
#include <unistd.h>

#include "base.h"
#include "get_next_line.h"

static char	*malloc_i_cat(char *dest, char src[READ_SIZE + 1], \
			   int count, int *pos)
{
  char		*buffer;
  int		k;
  int		i;
  int		j;

  k = 0;
  i = -1;
  j = -1;
  if (dest != NULL)
    while (dest[k] != 0)
      k++;
  if ((buffer = malloc(k + count + 1)) == NULL)
    return (NULL);
      while ((i = i + 1) < k)
	buffer[i] = dest[i];
      while ((j = j + 1) < count)
	buffer[i + j] = src[*pos + j];
      buffer[i + j] = 0;
      if (dest != NULL)
	free(dest);
      *pos = *pos + count + 1;
      return (buffer);
}

char							*get_next_line(const int fd)
{
  static char			buff[READ_SIZE + 1];
	char						*line;
  static ssize_t	rd;
  static int			j;
  int							i;

  line = NULL;
  i = 0;
  while (1)
    {
      if (j >= rd)
	    {
	      j = 0;
	      if ((rd = read(fd, buff, READ_SIZE)) <= 0)
		return (line);
	      i = 0;
	    }
	  if (buff[j + i] == '\n')
	    return (malloc_i_cat(line, buff, i, &j));
	  if (j + i == rd - 1)
	    line = malloc_i_cat(line, buff, i + 1, &j);
	  i++;
	}
      free(line);
      return (NULL);
}
