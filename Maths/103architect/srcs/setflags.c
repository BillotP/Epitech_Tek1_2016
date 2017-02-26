/*
** setflags.c for 103Architect in /home/bender/Repo/103architect/clement
**
** Made by Junior Bender
** Login   <bender@epitech.net>
**
** Started on  Tue Dec  6 18:45:43 2016 Junior Bender
** Last update Tue Dec 13 12:44:11 2016 clement cazaubon
*/

#include "../include/my.h"

void	set_flags(int ac, char **av)
{
  if (av[3][1] == 't')
    translation(ac, av);
  if (av[3][1] == 'h')
    homothety(ac, av);
  if (av[3][1] == 'r')
    rotation(ac, av);
  if (av[3][1] == 's')
    symetry(ac, av);
}

t_list	*set_multy_flags(int ac, char **av, int i, int *bol, t_list *list)
{
  if (av[i][1] == 't')
    {
      if (*bol == 0)
	{
	  list = LCfirst();
	  *bol = 1;
	}
      else
	list = LCadd(list);
      translationM(ac, av, i, list);
    }
  if (av[i][1] == 'h')
    {
      if (*bol == 0)
	{
	  list = LCfirst();
	  *bol = 1;
	}
      else
	list = LCadd(list);
      homothetyM(ac, av, i, list);
    }
  if (av[i][1] == 'r')
    {
      if (*bol == 0)
	{
	  list = LCfirst();
	  *bol = 1;
	}
      else
	list = LCadd(list);
      rotationM(ac, av, i, list);
    }
  if (av[i][1] == 's')
    {
      if (*bol == 0)
	{
	  list = LCfirst();
	  *bol = 1;
	}
      else
	list = LCadd(list);
      symetryM(ac, av, i, list);
    }
  return (list);
}
