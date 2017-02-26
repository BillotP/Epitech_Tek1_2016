/*
** base.c for strtowordtab in /home/bender/Blinux/bender/Snippets/strtowordtab/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec 27 21:32:38 2016 John Doe
** Last update	Wed Dec 28 10:06:48 2016 John Doe
*/

#include "pshell.h"

void		pprint(char *str, int fd)
{
  int		i;

  i = 0;
  while (str[i])
    write(fd, &str[i++], 1);
}
ssize_t			len(char *str)
{
  ssize_t		len;

  len = 0;
  while (str[len])
    len++;
  return (len);
}
char		*my_strcat(char *dest, char *src)
{
  int		i;
  int		j;
  char	*buffer;

  i = 0;
  if ((buffer = malloc(sizeof(*buffer) * len(dest) + len(src) + 1)) == NULL)
    return (NULL);
  while (dest[i])
    {
      buffer[i] = dest[i];
      i++;
    }
  buffer[i] = '\0';
  i = 0;
  j = len(buffer);
  while (src[i])
    {
      buffer[j + i] = src[i];
      i++;
    }
  buffer[j + i] = '\0';
  return (buffer);
}
int			argumentcount(char *str, char delim)
{
  int		i;
  int		j;
  static int k = 0;

  j = 0;
  i = 0;
  k = k + 1;
  while (str[i])
    {
      if (str[i] == delim && str[i + 1])
	j++;
      i++;
    }
  return (j + k);
}
int			my_strncmp(char *s1, char *s2, int n)
{
  int		i;

  i = 0;
  while (i <= n && s1[i] == s2[i])
    i++;
  if (i == n)
    return (i);
  return (0);
}
