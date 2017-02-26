/*
** graph.h for CPE_2016_matchstick in /home/bender/Repo/CPE/CPE_2016_matchstick/bonus/include/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Feb 24 00:29:56 2017 John Doe
** Last update Fri Feb 24 01:02:43 2017 John Doe
*/

#ifndef GRAPH_H_
# define GRAPH_H_

#include <ncurses.h>

// #define MOVE		move(0, 0);

typedef struct s_graph {
  WINDOW			*screen;
  int					x;
  int					y;
  int					width;
  int					height;
  int					movw;
  int					refresh;
}							t_graph;

t_graph				term;

/*
** init_graph.c
*/

void	init_graph(void);

#endif
