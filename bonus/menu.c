/*
** menu.c for sokoban in /home/lblanchard/System_unix/PSU_2016_my_sokoban/bonus
**
** Made by Leandre Blanchard
** Login   <lblanchard@epitech.net>
**
** Started on  Mon Dec 12 20:29:18 2016 Leandre Blanchard
** Last update Tue Dec 20 17:37:51 2016 Léandre Blanchard
*/

#include "include/sokoban.h"

int receive_keys(int i, int a, char **names)
{
    if (i == KEY_DOWN)
        a = a + 1;
    if (i == KEY_UP)
        a = a - 1;
    if (names[a] == NULL)
        a = 0;
    if (a < 0)
        a = my_tablen(names) - 1;
    refresh();
    if (i == 'x' || i == 'X')
        a = (-1);
    return (a);
}

char **display_files(DIR *dir)
{
    struct dirent *folder;
    char **names;
    int i;

    i = 0;
    if ((names = malloc(sizeof(char *) * 20)) == NULL)
        return (NULL);
    folder = readdir(dir);
    while ((folder = readdir(dir)) != NULL)
    {
        if (test_wf(folder->d_name) == 0)
        {
            names[i] = strdup(folder->d_name);
            i = i + 1;
        }
    }
    names[i] = NULL;
    while (i < 0)
    {
        mvprintw(
            LINES / 2 - 8 - i, COLS / 2 - my_strlen(names[i]) / 2, names[i]);
        i = i + 1;
    }
    closedir(dir);
    return (names);
}

void names_print(char **names)
{
    int j;

    j = 0;
    while (names[j] != NULL)
    {
        mvprintw(LINES / 2 + j, COLS / 2 - my_strlen(names[j]) / 2, names[j]);
        j = j + 1;
    }
    mvprintw(LINES / 2 + j + 1,
             COLS / 2 - 20,
             "\\--------------------------------------/");
}

char *menu_loop(char **names)
{
    int i;
    int a;

    a = 0;
    i = 0;
    while (a != (-1))
    {
        clear();
        title(names);
        names_print(names);
        mvprintw(LINES / 2 + a, COLS / 2 - my_strlen(names[a]) / 2 - 3, "->");
        i = getch();
        a = receive_keys(i, a, names);
        if (i == 10)
            return (names[a]);
        refresh();
        if (i == 'x' || i == 'X')
            break;
        if (i == 'h' || i == 'H')
            help();
    }
    endwin();
    return (NULL);
}

void title(char **names)
{
    menu_tight(names);
    mvprintw(LINES / 2 - 7, COLS / 2 - 12, "SOKOBAN GAME on terminal");
    mvprintw(LINES / 2 - 6, COLS / 2 - 15, "Select a file to open (in .sk)");
    mvprintw(LINES / 2 - 5, COLS / 2 - 8, "Press [X] to quit");
    mvprintw(LINES / 2 - 4, COLS / 2 - 9, "Press [H] for tips");
    mvprintw(LINES / 2 - 2,
             COLS / 2 - 20,
             "/--------------------------------------\\");
    mvprintw(LINES - 1, COLS - 35, "SOKOBAN made by Leandre Blanchard");
}
