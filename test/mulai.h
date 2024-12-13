#ifndef MULAI_H
#define MULAI_H

#include "../adt/mesinkata.h"
#include "../adt/boolean.h"

extern Word folderKonfigurasi;

// Fungsi utama
void displayWelcomeMessage();
void displayGoodbyeMessage();
void displayMenu();
void inisialisasi();
void validasiFolderKonfigurasi(Word folder);
void cekDanBuatFileKonfigurasi(char *folderPath);

#endif
