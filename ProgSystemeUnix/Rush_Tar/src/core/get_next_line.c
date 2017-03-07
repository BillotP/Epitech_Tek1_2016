/*
** get_next_line.c for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/core/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:56:08 2017 Bender_Rodriguez
** Last update Tue Mar  7 13:05:58 2017 bender
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

char			*get_next_line(const int fd)
{
  static char		buff[READ_SIZE + 1];
  char			*line;
  static ssize_t	rd;
  static int		j;
  int			i;

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
