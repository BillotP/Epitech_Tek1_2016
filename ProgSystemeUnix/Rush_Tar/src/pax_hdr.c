/*
** pax_hdr.c for CPE_2016_b2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Mon Mar  6 02:15:04 2017 Bender_Rodriguez
** Last update Mon Mar  6 02:33:33 2017 Bender_Rodriguez
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <pwd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "tar.h"
#include "my_archive.h"
#include "printf.h"

t_pax		*get_pax(const char *filename, struct stat buf)
{
  t_pax	*ptr;

  if ((ptr = malloc(512)) == NULL)
    return (void_err(strerror(errno), NULL));
  memset(ptr, '\0', sizeof(*ptr));
  ptr = get_name(filename, ptr);
  ptr = get_md(&buf, ptr);
  sprintf(ptr->uid, "0000000");
  sprintf(ptr->gid, "0000000");
  ptr = get_len(&buf, ptr);
  ptr =	get_tme(&buf, ptr);
  sprintf(ptr->chksum, "       ");
  sprintf(ptr->typeflag, " x");
  sprintf(ptr->magic, "ustar");
  sprintf(ptr->version , "00");
  sprintf(ptr->chksum, "%06o", get_summ(ptr));
  return (ptr);
}
