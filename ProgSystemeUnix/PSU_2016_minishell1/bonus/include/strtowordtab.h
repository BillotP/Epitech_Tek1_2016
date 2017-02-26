/*
** strtowordtab.h for strtowordtab in /home/bender/Snippets/strtowordtab/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Dec 24 23:57:31 2016 John Doe
** Last update	Tue Dec 27 21:37:03 2016 John Doe
*/

#ifndef STRTOWORDTAB_H_
# define STRTOWORDTAB_H_

#include <unistd.h>
#include <stdlib.h>

typedef struct s_count {
  int		i;
  int		j;
  int		wrd;
}							t_count;


void		init_that(t_count *count);
void		errors(char *errmsg);
int			argumentcount(char *str, char delim);

char		**strtowordtab(char *str, char delim);

#endif
