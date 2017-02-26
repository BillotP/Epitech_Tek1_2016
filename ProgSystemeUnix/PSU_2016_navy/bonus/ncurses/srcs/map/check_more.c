/*
** check_more.c for  in /home/CAZAUB_C/projet_de_lanée/PSU_2016_navy
** 
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
** 
** Started on  Sat Feb  4 18:59:32 2017 clement cazaubon
** Last update Fri Feb 10 15:58:49 2017 clement cazaubon
*/

#include "map.h"

int	check_2_point(char *str)
{
  if (str[1] != ':' || str[4] != ':')
    return (-1);
  return (0);
}

int	str_cap(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 'a' && str[i] <= 'z')
	str[i] = str[i] - 32;
      i++;
    }
  return (0);
}

int	good_direction(char *str)
{
  char	tmp;
  
  if (is_number(str[2]) == 0 && is_alpha(str[3]) == 0)
    {
      tmp = str[2];
      str[2] = str[3];
      str[3] = tmp;
    }
  if (is_number(str[5]) == 0 && is_alpha(str[6]) == 0)
    {
      tmp = str[5];
      str[5] = str[6];
      str[6] = tmp;
    }
  return (0);
}
