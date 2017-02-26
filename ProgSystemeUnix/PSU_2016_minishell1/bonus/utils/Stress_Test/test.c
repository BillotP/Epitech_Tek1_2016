/*
** test.c for test in /home/bender/Repo/PSU_2016_minishell1/Stress_Test
** 
** Made by Junior Bender
** Login   <bender@epitech.net>
** 
** Started on  Sun Jan 15 16:14:19 2017 Junior Bender
** Last update Sun Jan 15 16:16:26 2017 Junior Bender
*/

#include <stdio.h>

int	main(int ac, char **av)
{
  if ((av[1]))
    {
      printf("Valeur de av[1] : [%s]\n", av[1]);
      return (0);
    }
  printf("pas de av ... :(\n");
  return (1);
}
