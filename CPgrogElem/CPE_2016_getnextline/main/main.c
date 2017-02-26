/*
** main.c for GNL in /home/bender/Repo/CPE_2016_getnextline
**
** Made by Junior Bender
** Login   <bender@epitech.net>
**
** Started on  Sat Jan 14 12:35:45 2017 Junior Bender
** Last update Sat Jan 14 14:29:15 2017 John Doe
*/

#include "../get_next_line.h"
#include <stdio.h>

int		main(void)
{
  char		*s;

  while ((s = get_next_line(0)))
    printf("%s\n", s);
  return (0);
}
