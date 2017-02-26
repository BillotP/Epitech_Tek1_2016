/*
** main.c for  in /home/CAZAUB_C/projet_de_lanée/103architect/clement
**
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
**
** Started on  Mon Dec  5 17:26:07 2016 clement cazaubon
** Last update Tue Dec 13 09:30:41 2016 John Doe
*/

#include "../include/my.h"

int		main(int ac, char **av)
{
  int	matrix[3][3];

  if (ac <= 3)
    {
      printerr(ERRARG);
      return (84);
    }
  if (ac >=5 && ac <= 6)
    set_flags(ac, av);
  if (ac >= 7)
    multi_calc(ac, av);
  return (0);
}
