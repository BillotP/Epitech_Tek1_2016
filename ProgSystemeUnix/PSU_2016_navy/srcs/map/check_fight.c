/*
** check_fight.c for  in /home/CAZAUB_C/projet_de_lanée/PSU_2016_navy/paul/PSU_2016_navy/srcs/check_map
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Thu Feb  9 21:10:32 2017 clement cazaubon
** Last update Sun Feb 19 19:13:18 2017 John Doe
*/

#include "navy.h"

/*
** Parse sent coords to check validity
** 0 if ok and -1 if not.
*/
int	check_valid_pos(char *str)
{
  if (len(str) != 2 || is_alpha(str[0]) == -1 || is_number(str[1]) == -1)
    return (-1);
  return (0);
}
/*
** Parse entire map to check for win/loose
** ie, all the boat sinked.
** 0 if unsinked boats left and 1 if not.
*/
int	check_win_loose(char str[8][8])
{
  int	i;
  int	j;
  int	compt;
  int	cx;

  i = 0;
  j = 0;
  cx = 0;
  compt = 0;
  while (i < 8)
    {
      while (j < 8)
	{
	  if (str[i][j] >= '2' && str[i][j] <= '5')
	    compt++;
	  if (str[i][j] == 'x')
	    cx++;
	  j++;
	}
      j = 0;
      i++;
    }
  if (compt == 0 || cx == 13)
    return (1);
  return (0);
}

/*
** Print both maps
** ennemy's and current player one's.
*/
void	affich_map(t_map *map)
{
  p_printf(1, "my_positions:\n");
  p_printf(1, "%s", FIRSTROWS);
  liner(map->map);
  p_printf(1, "\nenemy's positions:\n%s",FIRSTROWS);
  liner(map->enemy_map);
  p_printf(1, "\n");
}

/*
** check for hit boats
** displaying a string containing
** the result.
*/
const char	*check_hit(t_map *map, char *str)
{
  if (map->map[str[1] - '1'][str[0] - 'A'] == '.' ||
      map->map[str[1] - '1'][str[0] - 'A'] == 'o')
    return ("MISS\n\n");
  return ("HIT\n\n");
}
/*
** update map according
** to the below function result.
*/
void	update_map(const char *str, t_map *map, int player, char *st)
{
  if (player == 1)
    {
      if (str[0] == 'M')
	map->map[st[1] - '1'][st[0] - 'A'] = 'o';
      else if (str[0] == 'H')
	map->map[st[1] - '1'][st[0] - 'A'] = 'x';
    }
  if (player == 2)
    {
      if (str[0] == 'M')
	map->enemy_map[st[1] - '1'][st[0] - 'A'] = 'o';
      else if (str[0] == 'H')
	map->enemy_map[st[1] - '1'][st[0] - 'A'] = 'x';
    }
}
