/*
** get_headerbis.c for Rush in /home/simon_f/simon_f/prog_elem/Rush
**
** Made by François Simon
** Login   <simon_f@epitech.net>
**
** Started on  Sat Mar 04 13:42:06 2017 François Simon
** Last update Mon Mar  6 13:49:49 2017 Bender_Rodriguez
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
#include "base.h"
#include "printf.h"
#include "tar.h"
#include "my_archive.h"

t_tar	*get_linkname(struct stat *buf, t_tar *ptr, const char *filename)
{
  if (S_ISLNK(buf->st_mode))
      my_strcpy(filename, ptr->linkname);
  return (ptr);
}

t_tar			*get_usrname(t_tar *ptr, gid_t uid)
{
  struct passwd	*tmp;

  tmp = getpwuid(uid);
  my_strcpy(tmp->pw_name, ptr->uname);
  ptr->uname[len(tmp->pw_name) + 1] = '\0';
  return (ptr);
}

t_tar			*get_grname(t_tar *ptr, gid_t gid)
{
  struct group *tmp;

  tmp = getgrgid(gid);
  sprintf(ptr->gname, "%s", tmp->gr_name);
  return (ptr);
}

char	*get_typeflag(struct stat buf)
{
  if (S_ISREG(buf.st_mode))
    return ("0");
  if (S_ISLNK(buf.st_mode))
    return ("2");
  if (S_ISDIR(buf.st_mode))
    return ("5");
  else if (S_ISBLK(buf.st_mode))
    return ("4");
  else if (S_ISFIFO(buf.st_mode))
    return ("6");
  else
    return (void_err(strerror(errno), NULL));
}
