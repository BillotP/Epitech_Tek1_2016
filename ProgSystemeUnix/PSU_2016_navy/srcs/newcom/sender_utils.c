/*
** sender_utils.c for PSU_2016_navy in /home/bender/Repo/PSU_2016_navy/srcs/newcom/
**
** Made by John Doe
** Login   <login_x@epitech.eu>
**
** Started on  Sun Feb 19 19:30:15 2017 John Doe
** Last update Sun Feb 19 19:31:00 2017 John Doe
*/

#include "navy.h"

/*
** swap values with XOR
** if coords sent in
** reverse order.
*/

void	swap(char *xp, char *yp)
{
    *xp ^= *yp;
    *yp = *xp ^ *yp;
    *xp ^= *yp;
}
/*
** Parse user input expression
** 1 if values are good
** zero otherwise.
*/
int			isokcmd(char *cmd)
{
  int		i;
  int		ok;
  const char  *legitchar;

  ok = i = 0;
  legitchar = "ABCDEFGHabcdefgh12345678";
  while (legitchar[i])
    {
      if (cmd[0] == legitchar[i])
	ok++;
      if (cmd[1] == legitchar[i])
	ok++;
      i++;
    }
  if (ok == 2)
    return (1);
  return (0);
}
/*
** Print prompt
*/
void		print_prompt(void)
{
  write(1, "\x1B[0mattack: ", 12);
  write(1, "\x1B[3m", 4);
}
/*
** correct user
** input
*/
char		*correct_input(char *cmd)
{
  if ((is_num(cmd[0])))
    swap(&cmd[0], &cmd[1]);
  if ((is_lwcse(cmd[0])))
    cmd[0] -= 32;
  return (cmd);
}
