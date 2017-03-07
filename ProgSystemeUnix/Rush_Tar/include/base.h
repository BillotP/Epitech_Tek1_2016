/*
** base.h for  in /home/bender/Repo/rush/CPE_2016_b2rush1/include/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:57:43 2017 Bender_Rodriguez
** Last update Sun Mar  5 22:05:19 2017 Bender_Rodriguez
*/

#ifndef BASE_H_
# define BASE_H_

#include <unistd.h>

/*
** base.c
*/
int			pprint(const char *str, int fd);
char		*my_malloc(char *str, size_t len);
char		**freetab(char **ptr);
char		*clean_free(char *ptr);
int			my_atoi(const char *str);
/*
** base2.c
*/
int			is_lwcse(const char c);
int			is_num(const char c);
int			my_stringisnum(const char *str);
char		*my_strcatvs(char *dest, const char *src);

/*
** string.g
*/
char		*my_strcpy(const char *src, char *dest);
char		*my_strdup(const char *src);
char		*my_strcat(char *dest, const char *src);
int			strn_cmp(const char *s1, const char *s2, size_t n);
ssize_t	len(const char *str);

#endif
