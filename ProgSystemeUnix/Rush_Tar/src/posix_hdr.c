/*
** posix_hdr.c for CPE_2016_b2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/src/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Mon Mar  6 02:16:45 2017 Bender_Rodriguez
** Last update Mon Mar  6 14:47:57 2017 Bender_Rodriguez
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

void			*get_header(const char *filename, struct stat *buf, t_tar *header)
{
  memset(header, '\0', sizeof(*header));
  header = get_filename(filename, header);
  header = get_mode(buf, header);
  header = get_ids(buf, header);
  header = get_size(buf, header);
  header = get_time(buf, header);
  my_strcpy("        ", header->chksum);
  my_strcpy(get_typeflag(*buf), header->typeflag);
  header = get_linkname(buf, header, filename);
  my_strcpy("ustar  ", header->magic);
  my_strcpy(" ", header->version);
  header = get_usrname(header, buf->st_uid);
  header = get_grname(header, buf->st_gid);
  sprintf(header->chksum, "%06o", get_sum(header));
  return (header);
}
