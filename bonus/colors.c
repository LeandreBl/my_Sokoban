/*
** colors.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban/bonus
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Dec 13 15:47:44 2016 Leandre Blanchard
** Last update Tue Dec 20 17:05:13 2016 Léandre Blanchard
*/

#include "include/sokoban.h"

void		x_char(char **tab, int z, int i, int j)
{
  if (z == 1)
    attron(COLOR_PAIR(2));
  else
    attron(COLOR_PAIR(3));
  mvprintw(LINES / 2 - my_tablen(tab) / 2 + i,
	   COLS / 2 - my_strlen(tab[i]) / 2 + j, "X");
  (z == 1) ? attroff(COLOR_PAIR(2)) : attroff(COLOR_PAIR(3));
}

void		p_char(char **tab, int i, int j)
{
  attron(COLOR_PAIR(4));
  mvprintw(LINES / 2 - my_tablen(tab) / 2 + i,
	   COLS / 2 - my_strlen(tab[i]) / 2 + j, "P");
  attroff(COLOR_PAIR(4));
}

void		sharp_char(char **tab, int i, int j)
{
  attron(COLOR_PAIR(1) | A_BOLD);
  mvprintw(LINES / 2 - my_tablen(tab) / 2 + i,
	   COLS / 2 - my_strlen(tab[i]) / 2 + j, "#");
  attroff(COLOR_PAIR(1));
}

void		o_char(char **tab, int i, int j)
{
  attron(COLOR_PAIR(7));
  mvprintw(LINES / 2 - my_tablen(tab) / 2 + i,
	   COLS / 2 - my_strlen(tab[i]) / 2 + j, "O");
  attroff(COLOR_PAIR(2));
}

void		space_char(char **tab, int i, int j)
{
  attron(COLOR_PAIR(2));
  mvprintw(LINES / 2 - my_tablen(tab) / 2 + i,
	   COLS / 2 - my_strlen(tab[i]) / 2 + j, " ");
  attroff(COLOR_PAIR(2));
}

