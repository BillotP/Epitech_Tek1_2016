/*
** base2.c for CPE_2016_B2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/core/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:55:42 2017 Bender_Rodriguez
** Last update Tue Mar  7 12:59:05 2017 bender
*/

#include "base.h"

int	is_lwcse(const char c)
{
  if (c >= 'a' && c <= 'z')
    return (1);
  return (0);
}
int	is_num(const char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}
int	my_stringisnum(const char *str)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if ((str[i] >= '0') && (str[i] <= '9'))
	j = j + 1;
      i++;
    }
  if (j == i)
    return (j);
  else
    return (0);
}

char	*my_strcatvs(char *dest, const char *src)
{
  int	i;
  int	j;

  i = 0;
  j = len(dest);
  while (src[i])
    {
      dest[j + i] = src[i];
      i++;
    }
  dest[j + i] = '\0';
  return (dest);
}
