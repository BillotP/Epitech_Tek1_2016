/*
** get_pax.c for RUSH in /home/simon_f/prog_elem/CPE_2016_b2rush1
** 
** Made by François Simon
** Login   <simon_f@epitech.net>
** 
** Started on  Sun Mar  5 17:44:04 2017 François Simon
** Last update Sun Mar  5 21:44:00 2017 François Simon
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include "tar.h"

t_pax	*get_name(const char *filename, t_pax  *ptr)
{
  sprintf(ptr->name, "./%s%c%d/%s", "PaxHeaders", '.', getpid(), filename);
  return (ptr);
}

t_pax	*get_md(struct stat *buf, t_pax *ptr)
{
  mode_t   cpy;

  cpy = buf->st_mode;
  sprintf(ptr->mode, "%07o", cpy &= ~(S_IFREG));
  return (ptr);
}

t_pax	*get_id(struct stat *buf, t_pax *ptr)
{
  sprintf(ptr->uid, "%07o", buf->st_uid);
  sprintf(ptr->gid, "%07o", buf->st_gid);
  return (ptr);
}

t_pax	*get_len(struct stat *buf, t_pax *ptr)
{
  sprintf(ptr->size, "%011lo", buf->st_size);
  return (ptr);
}

t_pax	*get_tme(struct stat *buf, t_pax *ptr)
{
  sprintf(ptr->mtime, "%011lo", buf->st_mtime);
  return (ptr);
}
