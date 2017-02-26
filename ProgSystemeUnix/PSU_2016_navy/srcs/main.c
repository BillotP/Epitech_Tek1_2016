/*
** main.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb  1 09:47:09 2017 John Doe
** Last update Sun Feb 19 18:53:41 2017 John Doe
*/

#include "navy.h"

int			main(int ac, char **av)
{
  int		rt;

  rt = 2;
  if (ac == 2 && (strn_cmp(av[1], "-h", 2)))
    {
      p_printf(1, "%s", USAGE);
      return (0);
    }
  if (ac == 2)
    {
      rt = P1_game(av[1]);
      if (rt == -1)
	return (84);
      return (rt == 0) ? (0) : (1);
    }
  if ((ac == 3) && (my_stringisnum(av[1])))
    {
      if (kill(my_atoi(av[1]), 0) == -1)
	return (84);
      rt = P2_game(av[2], my_atoi(av[1]));
      if (rt == -1)
	return (84);
      return (rt == 0) ? (0) : (1);
    }
  return (84);
}
