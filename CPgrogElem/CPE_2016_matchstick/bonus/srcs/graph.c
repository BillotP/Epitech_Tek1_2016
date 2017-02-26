/*
** graph.c for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/bonus/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 24 00:30:48 2017 John Doe
** Last update Fri Feb 24 01:12:41 2017 John Doe
*/

#include "stick.h"
#include <ncurses.h>

void	init_graph(void)
{
  initscr();
  // term.x = (LINES);
  // term.y = (COLS);
  // term.screen = newwin(0, 0, term.x, term.y);
  // cbreak();
  printw("\n\t%s\n\n%s", INTRO, ENTER);
  refresh();
  getch();
}
