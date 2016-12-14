/*
** scores.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban/bonus
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Dec 13 11:49:36 2016 Leandre Blanchard
** Last update Tue Dec 13 18:43:02 2016 Leandre Blanchard
*/

#include "include/sokoban.h"

void		init_pairs()
{
  init_pair(1, COLOR_MAGENTA, COLOR_MAGENTA);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_RED, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_WHITE, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_BLUE, COLOR_BLACK);
}

int		scores(char **tab, t_xy *posdot)
{
  int		i;
  int		score;

  i = 0;
  score = 0;
  while (posdot[i].x < 2000)
    {
      if (tab[posdot[i].x][posdot[i].y] == 'X')
	score = score + 100;
      i = i + 1;
    }
  attron(COLOR_PAIR(4));
  mvprintw(1, COLS / 2 - 10, "<Your score is [%d]>", score);
  attroff(COLOR_PAIR(4));
  return (score);
}

void		put_tab_color(char **tab, int i, int j, t_xy *posdot)
{
  int		k;
  int		z;

  z = 0;
  k = 0;
  if (tab[i][j] == 'X')
    {
      while (posdot[k].x != 2000)
	{
	  if (i == posdot[k].x && j == posdot[k].y)
	    z = 1;
	  k = k + 1;
	}
      x_char(tab, z, i, j);
    }
  if (tab[i][j] == 'P')
    p_char(tab, i, j);
  if (tab[i][j] == '#')
    sharp_char(tab, i, j);
  if (tab[i][j] == 'O')
    o_char(tab, i, j);
  if (tab[i][j] == ' ')
    space_char(tab, i, j);
}
