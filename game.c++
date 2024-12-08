#include <ncurses/ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "utils.h"
#include "game.h"

void play_game() {
    int high_score = read_high_score();
    int guess, number, attempts = 0;
    srand(time(NULL));
    number = rand() % 100 + 1;

    clear();
    mvprintw(1, 10, "TEBAK ANGKA!");
    mvprintw(2, 10, "Saya memikirkan angka antara 1 hingga 100.");
    mvprintw(3, 10, "Coba tebak angkanya!");
    mvprintw(5, 10, "Skor Tertinggi: %d", high_score);
    refresh();

    for (int i = 0; i < 5; i++) {
        mvprintw(7, 10, "Memikirkan angka: %d", rand() % 100 + 1);
        refresh();
        usleep(300000);
    }
    clear();
    mvprintw(1, 10, "Angka sudah siap! Coba tebak!");
    refresh();

    while (1) {
        mvprintw(3, 10, "Masukkan tebakan Anda: ");
        echo();
        scanw("%d", &guess);
        noecho();
        attempts++;

        if (guess > number) {
            mvprintw(5, 10, "Terlalu besar! Coba lagi.");
            beep();
        } else if (guess < number) {
            mvprintw(5, 10, "Terlalu kecil! Coba lagi.");
            beep();
        } else {
            mvprintw(5, 10, "Benar! Angka tersebut adalah %d.", number);
            mvprintw(7, 10, "Jumlah percobaan: %d", attempts);
            if (high_score == 0 || attempts < high_score) {
                mvprintw(9, 10, "Selamat! Anda mencetak skor tertinggi baru!");
                write_high_score(attempts);
            }
            break;
        }
        refresh();
    }

    mvprintw(11, 10, "Tekan 'm' untuk kembali ke menu, atau 'r' untuk main lagi.");
    refresh();

    while (1) {
        int ch = getch();
        if (ch == 'm') break;
        if (ch == 'r') {
            play_game();
            break;
        }
    }
}

#ifndef GAME_H
#define GAME_H

void play_game();

#endif
