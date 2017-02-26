/*
** curse.c for  in /home/CAZAUB_C/projet_de_lanée/PSU_2016_navy/paul/PSU_2016_navy/bonus/ncurses/srcs/map
** 
** Made by clement cazaubon
** Login   <CAZAUB_C@epitech.net>
** 
** Started on  Sat Feb 18 22:09:23 2017 clement cazaubon
** Last update Sun Feb 19 01:59:43 2017 clement cazaubon
*/

#include "navy.h"

void	colorfull(char c)
{
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_CYAN);
  init_pair(2, COLOR_MAGENTA, COLOR_CYAN);
  init_pair(3, COLOR_RED, COLOR_CYAN);
  init_pair(4, COLOR_WHITE, COLOR_BLACK);
  if (c == 'o' || c == '.' || c == ' ')
    wbkgdset(win, COLOR_PAIR(1));
  else if (c >= '2' && c <= '5')
    wbkgdset(win, COLOR_PAIR(2));
  else if (c == 'x')
    wbkgdset(win, COLOR_PAIR(3));
  printw("%c", c);
  wbkgdset(win, COLOR_PAIR(4));
}
