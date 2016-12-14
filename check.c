/*
** check.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Dec 12 15:54:03 2016 Leandre Blanchard
** Last update Tue Dec 13 17:01:33 2016 Leandre Blanchard
*/

#include "include/sokoban.h"

int	count_x(char **tab, char *path)
{
  int	i;
  int	j;
  int   nb;

  nb = 0;
  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (j != line_len(path))
	{
	  if (tab[i][j] == 'X')
	    nb = nb + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  return (nb);
}

int	check_lose(char **tab, char *path)
{
  int	i;
  int   j;
  int	blocs;

  blocs = 0;
  i = 0;
  while (tab[i] != NULL)
    {
      j = 0;
      while (j != line_len(path))
	{
	  if (tab[i][j] == 'X' && check_boxes(tab, i, j) == 1)
	    blocs = blocs + 1;
	  j = j + 1;
	}
      i = i + 1;
    }
  if (blocs == count_x(tab, path))
    return (1);
  return (0);
}

int	check_boxes(char **tab, int x, int y)
{
  if ((tab[x - 1][y] == '#' || tab[x - 1][y] == 'X')
      && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
	  || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
    return (1);
  if ((tab[x + 1][y] == '#' || tab[x + 1][y] == 'X')
      && (tab[x][y - 1] == '#' || tab[x][y + 1] == '#'
	  || tab[x][y - 1] == 'X' || tab[x][y + 1] == 'X'))
    return (1);
  return (0);
}
