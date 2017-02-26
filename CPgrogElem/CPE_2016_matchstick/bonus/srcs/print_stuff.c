/*
** print_stuff.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Wed Feb 22 09:36:20 2017 John Doe
** Last update Fri Feb 24 01:19:37 2017 John Doe
*/

#include "stick.h"
#include <ncurses.h>

void	topandbottom(int width)
{
  int	j;

  j = 1;
  while (j != width)
    {
      p_printf("*");
      j++;
    }
  p_printf("\n");
}

int		print_begspaces(int line, int sticks, int *pos)
{
  int i;

  i = 1;
  while (i <= ((line - 1) - *pos))
    {
      p_printf(" ");
      i++;
    }
  return (i);
}

void	print_stick(int sticknbr, int pos)
{
  int	j;

  j = 0;
  while (j != sticknbr)
    {
      p_printf("|");
      j++;
    }
}

int		print_endspaces(int width, int sticks, int *printedchar)
{
  int	i;

  i = 1;
  while (i <= (width - 2) - *printedchar)
    {
      p_printf(" ");
      i++;
    }
  return (i);
}

void	print_board(int line, int *sticksnbr)
{
  int	i;
  int	width;
  int	pos;
  int	printedchar;

  i = 0;
  pos = 0;
  width = get_width(line);
  topandbottom(width);
  while (i != line)
    {
      p_printf("*");
      printedchar = print_begspaces(line, sticksnbr[i], &pos) + sticksnbr[i];
      print_stick(sticksnbr[i], 0);
      pos++;
      print_endspaces(width, sticksnbr[i], &printedchar);
      i++;
      p_printf("*\n");
    }
  topandbottom(width);
}
