/*
** get_paxbis.c for RUSH in /home/simon_f/prog_elem/CPE_2016_b2rush1
**
** Made by François Simon
** Login   <simon_f@epitech.net>
**
** Started on  Sun Mar  5 17:48:43 2017 François Simon
** Last update Sun Mar  5 22:26:31 2017 Bender_Rodriguez
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include "tar.h"
#include "my_archive.h"

t_pax		*get_link(struct stat *buf, t_pax *ptr, const char *filename)
{
  sprintf(ptr->linkname, "%s", (S_ISLNK(buf->st_mode)) ? (filename) \
          : ptr->linkname);
  return (ptr);
}

t_pax		*get_usr(t_pax *ptr, gid_t uid)
{
  struct passwd *tmp;

  tmp = getpwuid(uid);
  sprintf(ptr->uname, "%s", tmp->pw_name);
  return (ptr);
}

t_pax		*get_gr(t_pax *ptr, gid_t gid)
{
  struct group *tmp;

  tmp = getgrgid(gid);
  sprintf(ptr->gname, "%s", tmp->gr_name);
  return (ptr);
}

unsigned int	get_summ(t_pax *pax)
{
  unsigned int  sum;
  int           len;
  char          *ptr;

  sum = 0;
  ptr = (char *)pax;
  len = 0;
  while (len++ < 512)
    sum += *(ptr++);
  return (sum);
}
