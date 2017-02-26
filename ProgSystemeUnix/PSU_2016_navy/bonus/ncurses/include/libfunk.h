/*
** libfunk.h for Testlib in /home/bender/Snippets/testlib/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sun Jan 29 12:17:02 2017 John Doe
** Last update Wed Feb  1 21:00:59 2017 John Doe
*/

#ifndef LIBFUNK_H_
# define LIBFUNK_H_

#include <unistd.h>
#include <errno.h>
#include <string.h>
/*
** string.c aka string.h
*/
ssize_t	len(const char *str);
int			strn_cmp(const char *s1, const char *s2, size_t n);
char		*my_strcat(char *dest, const char *src);
char		*my_strdup(const char *src);

/*
** stdlib adapted
*/
int			findgoodpath(const char *name, char **paths);
int			check_thatbinary(const char *name);
int			my_atoi(const char *str);
int			pprint(const char *str, int fd);
char		*my_malloc(char *str, size_t len);
char		**clean_freetab(char **ptr);
char		*clean_free(char *ptr);

char  				*clean_args(const char *str);
const  char		*removetrailingspace(const char *str);

/*
** error macro
*/
#define FDERR 	"Bad file descriptor"
#define NOEXST	": No such file or directory\n"
#define NOEXEC  ": Command not found.\n"
#define SEGFLT  "Segmentation fault (core dumped)\n"
#define FPERR   "Floating exception (core dumped)\n"
#define NOPERM	": Permission denied.\n"
/*
** got an error? an error message ?
**   an exit code... ???
** call 8.8.4 int errors right now!
*/
int						errors(const char *errmsg, int exitval);
int						p_exit(const char *str, int exitval);

/*
** Get next line defined
*/
#ifndef READ_SIZE
# define READ_SIZE (30)
#endif

#ifndef GET_NEXT_LINE_H_INCLUDED
# define GET_NEXT_LINE_H_INCLUDED

char	*get_next_line(const int fd);
#endif
/*
** P-printf defined
*/
#include <stdarg.h>

int				flag_match(const char c);
int				flg_d(va_list list, int fd);
int				flg_i(va_list list, int fd);
int				flg_c(va_list list, int fd);
int				flg_s(va_list list, int fd);

int				p_printf(int fd, const char *format, ...);
int				p_putnbr(long nb, int fd);
void			flag_funct(int (*ptr[4])(va_list list, int fd));

/*
** Strtowordtab defined
*/
typedef struct s_count {
  int		i;
  int		j;
  int		wrd;
}							t_count;

int			init_buffer(char *str, const char *delim, char ***tab);
int			check_words(char c, const char *delim);
void		move_str(int *i, int *linesize, char *str, const char *delim);
char		**strto_wordtab(char *str, const char *delim);

#endif
