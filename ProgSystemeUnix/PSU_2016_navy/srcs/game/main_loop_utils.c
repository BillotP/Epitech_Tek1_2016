/*
** M_loop_utils.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/game/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sun Feb 19 18:30:12 2017 John Doe
** Last update Sun Feb 19 18:30:52 2017 John Doe
*/

#include "navy.h"

int			endgame(void)
{
  if (check_win_loose(proto.ptr.map->map) == 1)
    {
      write(1, "Enemy won\n", 10);
      return (1);
    }
  else
    {
      write(1, "I won\n", 6);
      return (0);
    }
  return (2);
}

void 		endcom(int *i)
{
  if (proto.turn == 1)
    attack(i);
  else if (proto.turn == 0)
    recept(i);
}
