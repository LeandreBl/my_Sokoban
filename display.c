/*
** display.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Mon Dec  5 12:56:15 2016 Leandre Blanchard
** Last update Tue Dec 13 17:01:16 2016 Leandre Blanchard
*/

#include "include/sokoban.h"

int terrain_display(char **tab, char *path, int color)
{
  WINDOW *box;
  t_xy xy;
  t_xy *posdot;

  if (color == 0)
    color = 7;
  posdot = add_coord(posdot, tab);
  xy = get_pos(tab);
  initscr();
  start_color();
  init_pair(1, color, COLOR_BLACK);
  attron(COLOR_PAIR(1));
  while (1)
  {
    curs_set(0);
    tight(path, tab);
    xy = loop_screen(tab, path, xy, color);
    if (check_spot(tab, posdot) == 0)
      win_screen(tab, path, color);
    if (check_lose(tab, path) == 1)
      lose_screen(tab, path, color);
  }
  endwin();
  free(box);
  return (0);
}

void lose_screen(char **tab, char *path, int color)
{
  int key;

  key = 0;
  clear();
  refresh();
  mvprintw(LINES / 2 - 1, COLS / 2 - 5, "You lose !\n");
  mvprintw(LINES / 2, COLS / 2 - 5, "Restart ? Y/n\n");
  key = getch();
  while (key != 'n' && key != 'Y' && key != 'y')
    key = getch();
  if (key == 'n')
  {
    endwin();
    exit(QUIT);
  }
  if (key == 'Y' || key == 'y' || key == 32)
    terrain_display(str_to_tab(path), path, color);
}

t_xy loop_screen(char **tab, char *path, t_xy xy, int color)
{
  int i;

  i = 0;
  clear();
  while (tab[i] != NULL)
  {
    mvprintw(LINES / 2 - my_tablen(tab) / 2 + i,
             COLS / 2 - my_strlen(tab[i]) / 2, tab[i]);
    curs_set(0);
    i = i + 1;
  }
  refresh();
  xy = check_pos_mvt(tab, xy, path, color);
  return (xy);
}

void win_screen(char **tab, char *path, int color)
{
  int key;

  key = 0;
  clear();
  refresh();
  mvprintw(LINES / 2 - 1, COLS / 2 - 5, "You win !\n");
  mvprintw(LINES / 2, COLS / 2 - 5, "Restart ? Y/n\n");
  while (key != 'n' && key != 'Y' && key != 'y')
    key = getch();
  if (key == 'n')
  {
    endwin();
    exit(QUIT);
  }
  if (key == 'Y' || key == 'y')
    terrain_display(str_to_tab(path), path, color);
}
