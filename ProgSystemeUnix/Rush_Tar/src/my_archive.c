/*
** my_archive.c for in /home/simon_f/simon_f/prog_elem/Rush
**
** Made by François Simon
** Login   <simon_f@epitech.net>
**
** Started on  Fri Mar 03 20:45:01 2017 François Simon
** Last update Sun Mar  5 22:43:07 2017 François Simon
*/

/*
** libC include's
*/
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/*
** project headers
*/
#include "tar.h"
#include "my_archive.h"
#include "printf.h"

/*
** 8bits checksum of header
*/
unsigned int	get_sum(t_tar *header)
{
  unsigned int	sum;
  int		len;
  char		*ptr;

  sum = 0;
  ptr = (char *)header;
  len = sizeof(char *);
  while (len < 500)
    {
      sum += *(++ptr);
      len += 1;
    }
  return (sum);
}
/*
** open/create archive file
*/
int		init_data(t_data *ptr, const char *filename)
{
  ptr->i = 2;
  if ((ptr->new_archv = open(filename, FLAG, MODE)) == -1)
    return (err_handler(strerror(errno), -1));
  memset(ptr->buff, '\0', sizeof(ptr->buff));
  memset(ptr->end_footr, '\0', sizeof(ptr->end_footr));
  return (0);
}
/*
** Write down header and
** raw data, padding if necessary
*/
int			write_down(t_data *data, t_tar *header, struct stat *ptr)
{
  char		*datas;

  data->bytes_read = 0;
  if ((datas = malloc(sizeof(*datas) * (ptr->st_size + 1))) == NULL)
    return (err_handler(strerror(errno), -1));
  if ((write(data->new_archv, header, TBLOCK)) == -1)
    return (err_handler(strerror(errno), -1));
  if ((data->bytes_read = read(data->toarch, datas, ptr->st_size)) == -1)
    return (err_handler(strerror(errno), -1));
  if ((write(data->new_archv, datas, ptr->st_size)) == -1)
    return (err_handler(strerror(errno), -1));
  while (data->bytes_read % 512 != 0)
    data->bytes_read += write(data->new_archv, "\0", 1);
  free(datas);
  return (0);
}
/*
** Write header and raw file
** data.
*/
int	create_file(int ac, char **av)
{
  struct stat   buf;
  t_data	data;
  t_tar	  hdr;
  char		footer[TBLOCK];

  memset(footer, '\0', sizeof(footer));
  if (init_data(&data, av[1]) == -1)
    return (84);
  while (data.i < ac)
    {
      if ((data.toarch = open(av[data.i], O_RDONLY)) == -1)
	return (err_handler(strerror(errno), 84));
      else if (stat(av[data.i], &buf) == -1)
	return (err_handler(strerror(errno), 84));
      get_header(av[data.i], &buf, &hdr);
      if ((write_down(&data, &hdr, &buf)) == -1)
	return (84);
      close(data.toarch);
      data.i++;
    }
  write(data.new_archv, data.end_footr, sizeof(data.end_footr));
  close(data.new_archv);
  return (0);
}
