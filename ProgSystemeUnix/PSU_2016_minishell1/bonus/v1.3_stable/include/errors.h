/*
** errors.h for Minishell1 in /home/bender/GrowUp/snippetsandmore/minishell1/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Mon Jan 16 22:42:19 2017 John Doe
** Last update	Sat Jan 21 18:18:45 2017 Full Name
*/

#ifndef ERRORS_H_
# define ERRORS_H_

#include <signal.h>
#include <errno.h>
#include <string.h>

#define ERRNO	my_strcat("%s\n", strerror(errno))

#define FDERR 	"Bad file descriptor"
#define NOEXST	": No such file or directory\n"
#define NOEXEC  ": Command not found.\n"
#define SEGFLT  "Segmentation fault (core dumped)\n"
#define FPERR   "Floating point exception (core dumped)\n"
#define NOPERM	": Permission denied.\n"
/*
** got an error? an error message ?
**   an exit code... ???
** call 8.8.4 int errors right now!
*/

int						errors(const char *errmsg, int exitval);
int						p_exit(const char *str, int exitval);
#endif
