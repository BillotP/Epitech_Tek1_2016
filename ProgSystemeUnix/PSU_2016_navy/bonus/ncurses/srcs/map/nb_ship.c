/*
** nb_ship.c for  in /home/CAZAUB_C/projet_de_lanée/PSU_2016_navy
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Wed Feb  1 22:24:25 2017 clement cazaubon
** Last update Fri Feb 10 16:08:30 2017 clement cazaubon
*/

#include "navy.h"

int	nb_check(t_map *map)
{
  int	i;

  i = 0;
  while (i <= 3)
    {
      if (map->tab[i] >= 2)
	return (-1);
      i++;
    }
  return (0);
}

int	add_tomap(t_map *map, char *str)
{
  static int	nb = 0;
  int	x;
  int	y;

  if (nb >= 4)
    return (-1);
  nb++;
  map->tab[str[0] - '0' - 2] = map->tab[str[0] - '0' - 2] + 1;
  if (nb_check(map) == -1)
    return (-1);
  x = str[2] - 'A';
  y = str[3] - '0';
  if ((x + 'A' != str[5] && y + '0' != str[6]) || (x + 'A' == str[5] && y + '0' == str[6]))
    return (-1);
  if (x + 'A' != str[5])
    {
      if (x_place(map, str) == -1)
	return (-1);
     }
  if (y + '0' != str[6])
    {
      if (y_place(map, str) == -1)
	return (-1);
    }
  return (0);
}

int	x_place(t_map *map, char *str)
{
  int	x;
  int	y;

  x = str[2] - 'A';
  y = str[3] - '0';
  while (x + 'A' != str[5])
    {
      if (map->map[y - 1][x] == '.')
	map->map[y - 1][x] = str[0];
      else
	return (-1);
      if (x + 'A' <= str[5])
	x++;
      else
	x--;
    }
  if (map->map[y - 1][x] == '.')
    map->map[y - 1][x] = str[0];
  else
    return (-1);
  return (0);
}

int	y_place(t_map *map, char *str)
{
  int	x;
  int	y;

  x = str[2] - 'A';
  y = str[3] - '0';
  while (y + '0' != str[6])
    {
      if (map->map[y - 1][x] == '.')
	map->map[y - 1][x] = str[0];
      else
	return (-1);
      if (y + '0' <= str[6])
	y++;
      else
	y--;
    }
  if (map->map[y - 1][x] == '.')
    map->map[y - 1][x] = str[0];
  else
    return (-1);
  return (0);
}
