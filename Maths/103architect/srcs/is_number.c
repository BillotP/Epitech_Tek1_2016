/*
** is_number.c for 103Architect in /home/bender/Repo/103architect/clement
**
** Made by Junior Bender
** Login   <bender@epitech.net>
**
** Started on  Tue Dec  6 17:06:14 2016 Junior Bender
** Last update Tue Dec  6 18:50:33 2016 Junior Bender
*/

#include "../include/my.h"

int	is_number(char *str)
{
  int	i, ok = 0;

  while (str[i++])
    {
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
	ok = 0;
      else
	ok = 1;
    }
  if (ok == 0)
    return (0);
  else
    return (-1);
}
