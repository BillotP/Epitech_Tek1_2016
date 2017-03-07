/*
** main1.c for CPE_2016_b2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 22:29:01 2017 Bender_Rodriguez
** Last update Mon Mar  6 02:59:21 2017 Bender_Rodriguez
*/

#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "printf.h"
#include "tar.h"
#include "my_archive.h"

int		check_file(int argc, char **argv)
{
  int	i;

  i = 2;
  while (i != argc)
    {
      if (access(argv[i], F_OK) == -1)
	return (p_printf(2, "%s: %s\n", argv[i], strerror(errno)), -1);
      i++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  int		rt;

  rt = 0;
  if (ac == 1)
    return (p_printf(1, "%s\n", USAGE), 0);
  else if (ac == 2)
    return (p_printf(1, "%s: %s\n", av[0], COWARD), 0);
  else
    {
      if ((check_file(ac, av)) == -1)
	return (84);
      rt = create_file(ac, av);
    }
  return (rt);
}
