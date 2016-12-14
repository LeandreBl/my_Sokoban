/*
** help.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban/bonus
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Dec 13 16:08:24 2016 Leandre Blanchard
** Last update Tue Dec 13 18:13:29 2016 Leandre Blanchard
*/

#include "include/sokoban.h"

void		help_rules()
{
  attron(COLOR_PAIR(4));
  mvprintw(LINES / 2 - 3,
	   COLS / 2 - 17, "     The goal of the game is      ");
  mvprintw(LINES / 2 - 2,
	   COLS / 2 - 17, "     to pull every {X} of the     ");
  mvprintw(LINES / 2 - 1,
	   COLS / 2 - 17, "     game representating a box,   ");
  mvprintw(LINES / 2 + 0,
	   COLS / 2 - 17, "     on the storage locations     ");
  mvprintw(LINES / 2 + 1,
	   COLS / 2 - 17, "     marked with {O} character    ");
}

void		help_ascii_sokoban()
{
  attron(COLOR_PAIR(6));
  mvprintw(LINES / 2 - 9,
	   COLS / 2 - 18, "/-\\  /-\\  | / /-\\ |--\\   /-\\   |\\  | ");
  mvprintw(LINES / 2 - 8,
	   COLS / 2 - 18, "\\_   | |  |/  | | |--<  /___\\  | \\ | ");
  mvprintw(LINES / 2 - 7,
	   COLS / 2 - 18, "\\_/  \\_/  | \\ \\_/ |__/ /     \\ |  \\|");
}

void		help()
{
  int		i;

  i = 0;
  while (i == 0)
    {
      clear();
      init_pairs();
      attron(COLOR_PAIR(5));
      help_ascii_sokoban();
      mvprintw(LINES / 2 - 5,
	       COLS / 2 - 17, "         [SOKOBAN RULES]           ");
      attron(COLOR_PAIR(3));
      mvprintw(LINES / 2 - 4,
	       COLS / 2 - 17, "/--------------------------------\\");
      help_rules();
      attron(COLOR_PAIR(3));
      mvprintw(LINES / 2 + 2,
	       COLS / 2 - 17, "\\--------------------------------/");
      attron(COLOR_PAIR(2));
      mvprintw(LINES / 2 + 4,
	       COLS / 2 - 17, "    [Press any key to continue]");
      attroff(COLOR_PAIR(2));
      i = getch();
    }
}

void		tight(char *path, char **tab)
{
  while (LINES < my_tablen(tab) || COLS < line_len(path))
    {
      clear();
      mvprintw(LINES / 2, COLS / 2 - 11, "terminal too tight [!]");
      refresh();
    }
}

void		menu_tight(char **names)
{
  while (LINES < my_tablen(names) + 12 || COLS < 50)
    {
      clear();
      mvprintw(LINES / 2, COLS / 2 - 11, "terminal too tight [!]");
      refresh();
    }
}
