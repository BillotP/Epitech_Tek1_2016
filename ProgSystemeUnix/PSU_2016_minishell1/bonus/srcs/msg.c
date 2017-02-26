/*
** msg.c for BOOK in /home/bender/Desktop/Snippets/book/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Thu Dec 22 14:20:53 2016 John Doe
** Last update	Mon Jan 02 17:07:25 2017 Full Name
*/

#include "pshell.h"

void		errors(char *errmsg)
{
  pprint(errmsg, 2);
  pprint("\n", 2);
  _exit(84);
}

void				help(char *helpmsg, char *buff)
{
  pprint(helpmsg, 1);
  *buff = '\0';
}

void				license(char *licencemsg, char *buff)
{
  pprint(licencemsg, 1);
  *buff = '\0';
}

void		clean_exit()
{
  pprint("See U!\n", 1);
  _exit (0);
}
