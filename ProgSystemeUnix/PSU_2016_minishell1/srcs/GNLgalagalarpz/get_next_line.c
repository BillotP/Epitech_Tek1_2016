/*
** get_next_line.c for GNL in /home/bender/Repo/CPE_2016_getnextline
**
** Made by Junior Bender
** Login   <bender@epitech.net>
**
** posed on  Sat Jan 14 12:34:31 2017 Junior Bender
** Last update Sat Jan 14 14:23:01 2017 John Doe
*/

#include "get_next_line.h"

static char	*my_strcat(char *dest, char src[READ_SIZE + 1], int count, int *pos)
{
  char	*buffer;
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
	    return (my_strcat(line, buff, i, &j));
	  if (j + i == rd - 1)
	    line = my_strcat(line, buff, i + 1, &j);
	  i++;
	}
      free(line);
      return (NULL);
}
