/*
** pshell.h for PShell in /home/bender/Desktop/Snippets/bookv2/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Fri Dec 23 21:11:36 2016 John Doe
** Last update	Wed Dec 28 14:27:35 2016 John Doe
*/

#ifndef READSIZE
# define 	READSIZE	(5000)
#endif

#ifndef BUFFERSIZE
# define BUFFERSIZE (READSIZE + 1)
# endif

#ifndef CMDSIZE
# define CMDSIZE (10000)
#endif

#ifndef PSHELL_H_
# define PSHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <dirent.h>
/*
** Readline autocomplete header
** for bonus
*/
#include <readline/readline.h>
#include <readline/history.h>
/*
** My headers :
*/
#include "strtowordtab.h"
#include "msg.h"

void			pprint(char *str, int fd);
void			printerr(char *errmsg);
ssize_t		len(char *str);

char			**set_env(char **environ);
char			**change_path(char **environ, char *path);
char			*set_path(char *path);
int				parse_env(char **env, char *str);
void			loop(char **environ);
void			exec(char **args, char **environ, char *buff);
void			shortcuts(char *buff);
void			clean_exit();
void			free_that_bfr(char **bfr);

char			*stradd(char *src, char *next);
char			*my_strcat(char *dest, char *src);
int				my_strncmp(char *s1, char *s2, int n);

typedef void (*sighandler_t)(int);
void	my_signal(int signum);
sighandler_t signal(int signum, sighandler_t handler);


#endif
