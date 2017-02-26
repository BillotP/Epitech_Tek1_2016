/*
** errors.h for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/include/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sat Feb 11 10:59:59 2017 John Doe
** Last update Sat Feb 11 11:00:18 2017 John Doe
*/

#ifndef ERRORS_H_
# define ERRORS_H_

#include <signal.h>
#include <errno.h>
#include <string.h>

#define FDERR 	"Bad file descriptor"
#define NOEXST	": No such file or directory\n"
#define NOEXEC  ": Command not found.\n"
/*
** got an error? an error message ?
**   an exit code... ???
** call 8.8.4 int errors right now!
*/

int						errors(const char *errmsg, int exitval);
int						p_exit(const char *str, int exitval);
#endif
