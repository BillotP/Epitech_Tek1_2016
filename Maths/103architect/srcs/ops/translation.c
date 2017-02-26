/*
** translation.c for 103Architect in /home/bender/Repo/103architect/clement
**
** Made by Junior Bender
** Login   <bender@epitech.net>
**
** Started on  Tue Dec  6 18:16:25 2016 Junior Bender
** Last update Tue Dec 13 16:24:27 2016 John Doe
*/

#include "../../include/my.h"

void		translation(int ac, char **av)
{
  float matrix[3][3];
  float new_coord1, new_coord2 = 0;

  matrix[0][0] = 1;
  matrix[0][1] = 0;
  matrix[0][2] = atof(av[4]);
  matrix[1][0] = 0;
  matrix[1][1] = 1;
  matrix[1][2] = atof(av[5]);
  matrix[2][0] = 0;
  matrix[2][1] = 0;
  matrix[2][2] = 1;
  /* affichage de la matrix */
  printf("%.2f\t%.2f\t%.2f\n%.2f\t%.2f\t%.2f\n%.2f\t%.2f\t%.2f\n", \
	 matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], matrix[1][1], \
	 matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]);
  /* calcul des nouvelles coordonées */
  new_coord1 = (matrix[0][0] * atof(av[1]) + matrix[0][1] * atof(av[2]) \
		+ matrix[0][2]);
  new_coord2 = (matrix[1][0] * atof(av[1]) + matrix[1][1] * atof(av[2]) \
		+ matrix[1][2]);
/* affichage des nouvelles coordonées */
  printf("Translation by the vector (%.2f, %.2f)\n", atof(av[4]), atof(av[5]));
  printf("(%.0f,%.0f)=>(%.2f,%.2f)\n", atof(av[1]), atof(av[2]), \
	 new_coord1, new_coord2);
}

void		translationM(int ac, char **av, int i, t_list *maillon)
{
  float matrix[3][3];

  printf("Translation by the vector (%.f, %.f)\n", atof(av[2]), atof(av[5]));
  matrix[0][0] = 1;
  matrix[0][1] = 0;
  matrix[0][2] = atof(av[i + 1]);
  matrix[1][0] = 0;
  matrix[1][1] = 1;
  matrix[1][2] = atof(av[i + 2]);
  matrix[2][0] = 0;
  matrix[2][1] = 0;
  matrix[2][2] = 1;

  feed_matrix(maillon, matrix);
}
