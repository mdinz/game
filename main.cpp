#include <ncurses/ncurses.h>
#include "utils.h"
#include "game.h"

int main() {
    initscr();
    start_color();
    init_pair(1, COLOR_CYAN, COLOR_BLACK);
    noecho();
    cbreak();
    curs_set(0);
    main_menu();
    endwin();
    return 0;
}

void main_menu() {
    int choice;

    while (1) {
        clear();
        attron(A_BOLD | COLOR_PAIR(1));
        mvprintw(1, 10, "=== GAME MINI ===");
        attroff(A_BOLD | COLOR_PAIR(1));
        mvprintw(3, 10, "1. Mainkan Permainan");
        mvprintw(4, 10, "2. Keluar");
        mvprintw(6, 10, "Pilih opsi: ");
        refresh();

        echo();
        scanw("%d", &choice);
        noecho();

        if (choice == 1) {
            show_loading();
            play_game();
        } else if (choice == 2) {
            clear();
            mvprintw(10, 10, "Terima kasih telah bermain!");
            refresh();
            usleep(2000000);
            break;
        } else {
            mvprintw(8, 10, "Pilihan tidak valid!");
            refresh();
            usleep(1000000);
        }
    }
}
