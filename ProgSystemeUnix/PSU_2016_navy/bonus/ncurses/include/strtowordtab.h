/*
** strtowordtab.h for Libfunk in /home/bender/Snippets/libfunk/include/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sun Jan 29 10:14:11 2017 John Doe
** Last update Wed Feb  1 21:00:42 2017 John Doe
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
