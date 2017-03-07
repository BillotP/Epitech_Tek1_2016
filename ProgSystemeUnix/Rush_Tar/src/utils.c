/*
** utils.c for  in /home/simon_f/prog_elem/CPE_2016_b2rush1
** 
** Made by François Simon
** Login   <simon_f@epitech.net>
** 
** Started on  Sun Mar  5 20:49:53 2017 François Simon
** Last update Sun Mar  5 20:49:54 2017 François Simon
*/

#include <unistd.h>

#include "my_archive.h"

size_t	my_len(const char *str)
{
  size_t	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int				err_handler(const char *err_str, int rt)
{
  write(2, ERRMSG, my_len(ERRMSG));
  write(2, err_str, my_len(err_str));
  write(2, "\n", 1);
  return (rt);
}

void			*void_err(const char *err_str, void *rt)
{
  write(2, ERRMSG, my_len(ERRMSG));
  write(2, err_str, my_len(err_str));
  return (rt);
}
