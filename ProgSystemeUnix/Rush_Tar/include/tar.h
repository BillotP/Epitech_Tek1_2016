/*
** tar.h for CPE_2016_b2rush1 in /home/bender/Repo/rush/CPE_2016_b2rush1/include/
**
** Made by Bender_Rodriguez
** Login   <paul1.billot@epitech.eu>
**
** Started on  Sun Mar  5 22:21:47 2017 Bender_Rodriguez
** Last update Tue Mar  7 12:35:12 2017 bender
*/

#ifndef TAR_H_
# define TAR_H_

#include <sys/stat.h>
#include <grp.h>

/*
** Posix tar header struct
** and define for total size
*/
#ifndef TBLOCK
#define	TBLOCK		512
#endif

typedef struct	s_tar {
  char	name[100];
  char	mode[8];
  char	uid[8];
  char	gid[8];
  char	size[12];
  char	mtime[12];
  char	chksum[8];
  char	typeflag[1];
  char	linkname[100];
  char	magic[6];
  char	version[2];
  char	uname[32];
  char	gname[32];
  char	devmajor[8];
  char	devminor[8];
  char	prefix[155];
}		t_tar;

/*
** PAX Header structure
*/
typedef struct	s_pax
{
  char	name[100];
  char	mode[8];
  char	uid[8];
  char	gid[8];
  char	size[12];
  char	mtime[12];
  char	chksum[8];
  char	typeflag[2];
  char	linkname[100];
  char	magic[6];
  char	version[2];
  char	uname[32];
  char	gname[32];
  char	devmajor[8];
  char	devminor[8];
  char	prefix[131];
  char	atime[12];
  char	ctime[12];
}		t_pax;

/*
** Mode and default
** flag for archive
*/
#ifndef FLAG
#define FLAG	O_RDWR | O_CREAT | O_APPEND
#endif
#ifndef MODE
#define MODE	S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
#endif
/*
** Posix Header filling functions
*/
t_tar		*get_filename(const char *, t_tar  *);
t_tar		*get_mode(struct stat *, t_tar *);
t_tar		*get_ids(struct stat *, t_tar *);
t_tar		*get_size(struct stat *, t_tar *);
t_tar		*get_time(struct stat *, t_tar *);
t_tar		*get_linkname(struct stat *, t_tar *, const char *);
t_tar		*get_usrname(t_tar *, gid_t);
t_tar		*get_grname(t_tar *, gid_t);

/*
** Pax header filling functions
*/
t_pax		*get_name(const char *, t_pax  *);
t_pax		*get_md(struct stat *, t_pax *);
t_pax		*get_id(struct stat *, t_pax *);
t_pax		*get_len(struct stat *, t_pax *);
t_pax		*get_tme(struct stat *, t_pax *);
t_pax		*get_link(struct stat *, t_pax *,  const char *);
t_pax		*get_usr(t_pax *, gid_t );
t_pax		*get_gr(t_pax *, gid_t );
unsigned int	get_summ(t_pax *);

char		*get_typeflag(struct stat );
int		create_file(int ac, char **av);
unsigned int	get_sum(t_tar *header);

/*
** posix_hdr.c
*/
void		*get_header(const char *filename, struct stat *buf, t_tar *ptr);

/*
** pax_hdr.c
*/
t_pax		*get_pax(const char *filename, struct stat buf);

#endif
