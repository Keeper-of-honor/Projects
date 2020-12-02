#include <ncurses.h>
#include <unistd.h>

int main()
{

    initscr();
    curs_set(0);

	int count = 20;
	int x = 0;
	int y = 0;
    while (count--)
    {
        mvaddch(y++, x++,'o');
        refresh();
        sleep(1);
    }

    getch();
    endwin();
}
