/*
** base.h for minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:38:38 2017 John Doe
** Last update Fri Jan 20 23:09:54 2017 John Doe
*/

#ifndef BASE_H_
# define BASE_H_

#include "errors.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>
/*
** string.c aka string.h
*/
ssize_t	len(const char *str);
int			strn_cmp(const char *s1, const char *s2, size_t n);
char		*my_strcat(char *dest, const char *src);
char		*my_strdup(const char *src);

/*
** stdlib adapted
*/
int			findgoodpath(const char *name, char **paths);
int			check_thatbinary(const char *name);
int			my_atoi(const char *str);
int			pprint(const char *str, int fd);

char  		*clean_args(char *str);

#endif
