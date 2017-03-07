/*
** my_archive.h for CPE_2016_b2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/include/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 05:09:25 2017 Bender_Rodriguez
** Last update Tue Mar  7 12:06:50 2017 Bender_Rodriguez
*/

#ifndef _MY_ARCHIVE_H_
# define _MY_ARCHIVE_H_

/*
** For FILE and size_t
*/
#include <stdio.h>
#include <stddef.h>

/*
** Errmsg macro
*/
#ifndef ERRMSG
#define ERRMSG	"./my_archive error: "
#endif

#ifndef COWARD
#define COWARD "Cowardly refusing to create an empty archive\n\
Try 'tar --help' or 'tar --usage' for more information."
#endif

/*
** Usage
*/
#ifndef USAGE
#define USAGE "Usage: ./my_archive [archive_name] [files ...]"
#endif

typedef struct s_data {
  int			new_archv;
  int			toarch;
  int			i;
  ssize_t	bytes_read;
  char		end_footr[512 * 12];
  char		buff[512];
}	t_data;

/*
** utils.c
*/

void		*void_err(const char *err_str, void *rt);
int		err_handler(const char *err_str, int rt);

#endif
