/*
** strtowordtab.h for strtowordtab in /home/bender/Snippets/strtowordtab/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Dec 24 23:57:31 2016 John Doe
** Last update	Sat Jan 21 10:49:56 2017 Full Name
*/

#ifndef STRTOWORDTAB_H_
# define STRTOWORDTAB_H_

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct s_count {
  int		i;
  int		j;
  int		wrd;
}							t_count;


/*
** The mother function here :
** strtowordtab !
*/
int			init_buffer(char *str, const char *delim, char ***tab);
int			check_words(char c, const char *delim);
void		move_str(int *i, int *linesize, char *str, const char *delim);
char		**strto_wordtab(char *str, const char *delim);

#endif
