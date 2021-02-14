/*
** sokoban.h for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban/bonus
** 
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
** 
** Started on  Tue Dec 13 17:02:33 2016 Leandre Blanchard
** Last update Tue Dec 20 18:38:08 2016 Léandre Blanchard
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <curses.h>
#include <termios.h>
#include <dirent.h>
#include <SFML/Audio/Music.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <SFML/System/InputStream.h>
#include <SFML/System/Time.h>
#include <SFML/System/Vector3.h>
#include <stddef.h>
#include <time.h>

#include "colors.h"
#include "my.h"

#define ARGS_ERROR 84
#define BUFFER_ERROR 84
#define READ_EMPTY 84
#define MALLOC_ERROR 84
#define BUG 84
#define QUIT 0

typedef struct s_xy
{
  int x;
  int y;
} t_xy;

typedef struct s_vars
{
  int i;
  int j;
  int k;
} t_vars;

extern sfMusic *theme;

int p_x_o_check(char **, char *);

void tight(char *, char **);

void menu_tight(char **);

void help();

void x_char(char **, int, int, int);

void sharp_char(char **, int, int);

void o_char(char **, int, int);

void p_char(char **, int, int);

void space_char(char **, int, int);

void init_pairs();

void put_tab_color(char **, int, int, t_xy *);

int scores(char **, t_xy *);

char **display_files(DIR *);

int test_wf(char *);

int receive_keys(int, int, char **);

void names_print(char **);

char *menu_loop(char **);

void title(char **);

int check_pose(char **, char *);

int check_lose(char **, char *);

void lose_screen(char **, char *, int);

int check_boxes(char **, int, int);

void win_screen(char *, int, int);

char *menu();

t_xy xy_tuple(int, int);

int check_spot(char **, t_xy *);

t_xy *add_coord(char **);

t_xy loop_screen(char **, char *, t_xy, t_xy *);

char **restart_path(char *);

int main(void);

t_xy move_right(char **, t_xy);

t_xy move_left(char **, t_xy);

t_xy move_up(char **, t_xy);

t_xy move_down(char **, t_xy);

t_xy check_pos_mvt(char **, t_xy, char *, int);

t_xy get_pos(char **);

void my_put_tab(char **);

int terrain_display(char **, char *, int);

int my_tablen(char **);

char **str_to_tab(char *);

int nb_of_line(char *);

int line_len(char *);

#endif /* !SOKOBAN_H_ */
