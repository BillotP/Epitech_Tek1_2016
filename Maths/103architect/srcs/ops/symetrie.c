/*
** symetrie.c for 103Architect in /home/bender/Repo/103architect/clement
**
** Made by Junior Bender
** Login   <bender@epitech.net>
**
** Started on  Tue Dec  6 18:42:02 2016 Junior Bender
** Last update Tue Dec 13 16:32:03 2016 John Doe
*/

#include "../../include/my.h"

void	symetry(int ac, char **av)
{
  float matrix[3][3];
  float new_coord1, new_coord2 = 0;
  float A = atof(av[4]) / 180 * M_PI;

  matrix[0][0] = cos(2*A);
  matrix[0][1] = sin(2*A);
  matrix[0][2] = 0;
  matrix[1][0] = sin(2*A);
  matrix[1][1] = -cos(2*A);
  matrix[1][2] = 0;
  matrix[2][0] = 0;
  matrix[2][1] = 0;
  matrix[2][2] = 1; /* Calcul des nouvelles coordonées */
  new_coord1 = (matrix[0][0] * atof(av[1]) + matrix[0][1] * atof(av[2]) \
		+ matrix[0][2]);
  new_coord2 = (matrix[1][0] * atof(av[1]) + matrix[1][1] * atof(av[2]) + \
		matrix[1][2]); /* Affichage de la matrice */
  printf("Symmetry about an axis inclined with an angle of %.0f degrees\n", \
	 atof(av[4]));
  printf("%.2f\t%.2f\t%.2f\n%.2f\t%.2f\t%.2f\n%.2f\t%.2f\t%.2f\n", \
	 matrix[0][0], matrix[0][1], matrix[0][2], matrix[1][0], \
	 matrix[1][1], matrix[1][2], matrix[2][0], matrix[2][1], matrix[2][2]);
  /* Affichage des nouvelles coordonées */
  printf("(%.0f,%.0f)=>(%.2f,%.2f)\n", atof(av[1]), atof(av[2]), new_coord1, \
	 new_coord2);
}

void	symetryM(int ac, char **av, int i, t_list *maillon)
{
      float matrix[3][3];
      float A = atof(av[i + 1]) / 180 * M_PI;
      printf("Symmetry about an axis inclined with an angle of %.f degrees\n", atof(av[i + 1]));
      matrix[0][0] = cos(2*A);
      matrix[0][1] = sin(2*A);
      matrix[0][2] = 0;
      matrix[1][0] = sin(2*A);
      matrix[1][1] = -cos(2*A);
      matrix[1][2] = 0;
      matrix[2][0] = 0;
      matrix[2][1] = 0;
      matrix[2][2] = 1;

      feed_matrix(maillon, matrix);
  }
