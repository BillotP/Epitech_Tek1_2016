/*
** get_header.c for Rush in /home/simon_f/simon_f/prog_elem/Rush
**
** Made by François Simon
** Login   <simon_f@epitech.net>
**
** Started on  Sat Mar 04 12:40:23 2017 François Simon
** Last update Mon Mar  6 13:43:44 2017 Bender_Rodriguez
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "tar.h"

t_tar	*get_filename(const char *filename, t_tar  *ptr)
{
  sprintf(ptr->name, "%s", filename);
  return (ptr);
}

t_tar		*get_mode(struct stat *buf, t_tar *ptr)
{
  mode_t	cpy;

  cpy = buf->st_mode;
  sprintf(ptr->mode, "%07o", cpy &= ~(S_IFREG));
  return (ptr);
}

t_tar		*get_ids(struct stat *buf, t_tar *ptr)
{
  sprintf(ptr->uid, "%07o", buf->st_uid);
  sprintf(ptr->gid, "%07o", buf->st_gid);
  return (ptr);
}

t_tar		*get_size(struct stat *buf, t_tar *ptr)
{
  sprintf(ptr->size, "%011lo", buf->st_size);
  return (ptr);
}

t_tar		*get_time(struct stat *buf, t_tar *ptr)
{
  sprintf(ptr->mtime, "%011lo", buf->st_mtime);
  return (ptr);
}
