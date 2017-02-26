/*
** check_fight.c for  in /home/CAZAUB_C/projet_de_lanée/PSU_2016_navy/paul/PSU_2016_navy/srcs/check_map
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Thu Feb  9 21:10:32 2017 clement cazaubon
** Last update Sat Feb 18 23:17:56 2017 clement cazaubon
*/

#include "navy.h"

/*
** Parse sent coords to check validity
** return 0 if ok and -1 if not.
*/
int	check_valid_pos(char *str)
{
  if (len(str) != 2 || is_alpha(str[0]) == -1 || is_number(str[1]) == -1)
    return (-1);
  return (0);
}
/*
** Parse entire map to check for win/loose
** (ie, all the boat sinked)
** return 0 if unsinked boats left and 1 if not.
*/
int	check_win_loose(char str[8][8])
{
  int	i;
  int	j;
  int	compt;

  i = 0;
  j = 0;
  compt = 0;
  while (i < 8)
    {
      while (j < 8)
	{
	  if (str[i][j] >= '2' && str[i][j] <= '5')
	    compt++;
	  j++;
	}
      j = 0;
      i++;
    }
  if (compt == 0)
    return (1);
  return (0);
}

/*
** Print both maps
** ennemy's and current player one's.
*/
void	affich_map(t_map *map)
{
  clear();
  win = initscr();
  move(0,0);
  printw("my_positions:\n");
  printw("%s", FIRSTROWS);
  liner(map->map);
  printw("\nenemy's positions:\n%s",FIRSTROWS);
  liner(map->enemy_map);
  printw("\n");
  refresh();
}

/*
** check for hit boats
** return a string containing
** the result.
*/
const char	*check_hit(t_map *map, char *str)
{
  if (map->map[str[1] - '1'][str[0] - 'A'] == '.' ||
      map->map[str[1] - '1'][str[0] - 'A'] == 'o')
    return ("MISS");
  return ("HIT");
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
