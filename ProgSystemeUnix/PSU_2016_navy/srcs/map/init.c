/*
** init.c for  in /home/CAZAUB_C/projet_de_lanée/PSU_2016_navy
** 
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
** 
** Started on  Wed Feb  1 12:14:06 2017 clement cazaubon
** Last update Fri Feb 10 14:06:36 2017 clement cazaubon
*/

#include "navy.h"

void	init_map (t_map *map)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i <= 7)
    {
      while (j <= 7)
	{
	  map->map[i][j] = '.';
	  map->enemy_map[i][j] = '.';
	  j++;
	}
      j = 0;
      i++;
    }
  map->tab[0] = 0;
  map->tab[1] = 0;
  map->tab[2] = 0;
  map->tab[3] = 0;
}
