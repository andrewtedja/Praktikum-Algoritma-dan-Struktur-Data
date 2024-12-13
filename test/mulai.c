#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "../adt/mesinkata.h"
#include "mulai.h"
#include "login_logout.h"
#include "interface.h"
#include "save_load.h"

Word folderKonfigurasi;

/* ********** FUNGSI UTILITAS ********** */

/* ********** FUNGSI UTAMA ********** */

void displayWelcomeMessage() {
    printf("\n======================================\n");
    printf("|      SELAMAT DATANG DI PURRYMAIL     |\n");
    printf("|         Email Service v1.0           |\n");
    printf("======================================\n");
}

void displayGoodbyeMessage() {
    printf("\n======================================\n");
    printf("|   Terima kasih telah menggunakan     |\n");
    printf("|          PURRYMAIL v1.0              |\n");
    printf("|        Sampai jumpa kembali!         |\n");
    printf("======================================\n\n");
}

void displayMenu() {
    printf("\n=====================================\n");
    printf("|          P U R R Y M A I L        |\n");
    printf("|          Email Service v1.0       |\n");
    printf("=====================================\n");

    if (!isLoggedIn) {
        printf("\nPerintah yang tersedia:\n");
        printf("1. REGISTER - Membuat akun baru\n");
        printf("2. LOGIN    - Masuk ke akun\n");
        printf("3. SAVE     - Simpan data pengguna\n");
        printf("4. LOAD     - Muat data pengguna\n");
        printf("5. QUIT     - Keluar aplikasi\n");
        printf("\nFormat: <PERINTAH>;\n");
        printf("Contoh: REGISTER;\n");
    } else {
        printf("\nStatus: Login sebagai %s\n", currentUser.email);
        printf("\nPerintah yang tersedia:\n");
        printf("1. LOGOUT - Keluar akun\n");
        printf("2. SAVE   - Simpan data pengguna\n");
        printf("3. LOAD   - Muat data pengguna\n");
        printf("4. QUIT   - Keluar aplikasi\n");
        printf("\nFormat: <PERINTAH>;\n");
        printf("Contoh: LOGOUT;\n");
    }
    printf("\n=====================================\n");
}

void inisialisasi() {
    printf("Masukkan folder konfigurasi di dalam folder config untuk dimuat: ");
    STARTWORD();
    char currentInput[512];

    if (currentChar == ';') {
        my_strncpy(currentInput, currentWord.TabWord, currentWord.Length);
        folderKonfigurasi.Length = 9;
        my_strcpy(folderKonfigurasi.TabWord, "./config/");
        my_strcat(folderKonfigurasi.TabWord, currentInput);
        folderKonfigurasi.Length += currentWord.Length;
        folderKonfigurasi.TabWord[folderKonfigurasi.Length] = '\0';
        printf("Folder konfigurasi yang dimuat: ");
        for (int i = 0; i < folderKonfigurasi.Length; i++) {
            printf("%c", folderKonfigurasi.TabWord[i]);
        }
        printf("\n");
        validasiFolderKonfigurasi(folderKonfigurasi);
        delay(3000);
        my_strcpy(emailConfig.TabWord, folderKonfigurasi.TabWord); emailConfig.Length = folderKonfigurasi.Length;
        my_strcpy(penggunaConfig.TabWord, folderKonfigurasi.TabWord); penggunaConfig.Length = folderKonfigurasi.Length;
        my_strcpy(umumConfig.TabWord, folderKonfigurasi.TabWord); umumConfig.Length = folderKonfigurasi.Length;
        my_strcat(emailConfig.TabWord, "/email.config"); emailConfig.Length += 13;
        my_strcat(penggunaConfig.TabWord, "/pengguna.config"); penggunaConfig.Length += 16;
        my_strcat(umumConfig.TabWord, "/umum.config"); umumConfig.Length += 12;
    } else {
        printf("[Error] Masukan harus diakhiri dengan ';'\n");
        exit(EXIT_FAILURE);
    }
}

void validasiFolderKonfigurasi(Word folder) {
    char path[512];
    my_strncpy(path, folder.TabWord, folder.Length);
    printf("Memeriksa alamat folder: %s\n", path);

    struct stat st;
    if (stat(path, &st) == 0 && S_ISDIR(st.st_mode)) {
        printf("Folder konfigurasi ditemukan!\n");
        cekDanBuatFileKonfigurasi(path);
    } else {
        printf("Folder konfigurasi tidak ditemukan!\n");
        exit(EXIT_FAILURE);
    }
}

void cekDanBuatFileKonfigurasi(char *folderPath) {
    char filePath[512];
    const char *files[] = {"umum.config", "pengguna.config", "email.config"};
    FILE *file;

    for (int i = 0; i < 3; i++) {
        my_strcpy(filePath, folderPath);
        my_strcat(filePath, "/");
        my_strcat(filePath, files[i]);

        file = fopen(filePath, "r");
        if (file) {
            printf("File konfigurasi %s ditemukan.\n", files[i]);
            fclose(file);
        } else {
            file = fopen(filePath, "w");
            if (file) {
                printf("File konfigurasi %s berhasil dibuat.\n", files[i]);
                fclose(file);
            } else {
                printf("Gagal membuat file konfigurasi: %s\n", filePath);
                exit(EXIT_FAILURE);
            }
        }
    }
}
