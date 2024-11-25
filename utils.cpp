#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "utils.h"

void show_loading() {
    clear();
    mvprintw(10, 10, "Loading...");
    refresh();
    for (int i = 0; i < 10; i++) {
        mvprintw(12, 10 + i, ".");
        refresh();
        usleep(200000);
    }
    clear();
}

int read_high_score() {
    FILE *file = fopen(FileSkor, "r");
    int high_score = 0;
    if (file) {
        fscanf(file, "%d", &high_score);
        fclose(file);
    }
    return high_score;
}
