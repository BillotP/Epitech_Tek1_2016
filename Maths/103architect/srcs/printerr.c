/*
** printerr.c for 103Architect in /home/bender/Repo/103architect/srcs/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Tue Dec  6 20:54:22 2016 John Doe
** Last update Tue Dec  6 21:08:14 2016 John Doe
*/

#include "../include/my.h"
#include <unistd.h>

int		printerr(char *errormsg)
{
  for (int i = 0; errormsg[i]; i++)
    write(2, &errormsg[i], 1);
  return (84);
}
