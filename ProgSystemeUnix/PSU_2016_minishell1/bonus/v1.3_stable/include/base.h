/*
** base.h for minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:38:38 2017 John Doe
** Last update	Sat Jan 21 22:08:47 2017 Full Name
*/

#ifndef BASE_H_
# define BASE_H_

#include "errors.h"
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define EXITFAIL (1)
#define EXITGOOD (0)
/*
** string.c aka string.h
*/
ssize_t	len(const char *str);
int			strn_cmp(const char *s1, const char *s2, size_t n);
char		*my_strcat(char *dest, const char *src);
char		*my_strdup(const char *src);
char		*my_strcpy(const char *src, char *dest);


/*
** stdlib adapted
*/
int			findgoodpath(const char *name, char **paths);
int			check_thatbinary(const char *name);
int			my_atoi(const char *str);
int			pprint(const char *str, int fd);

char			*my_malloc(char *str, size_t len);
char  		*clean_args(const char *str);
char			*clean_free(char *str);
char			**clean_freetab(char **ptr);

#endif
