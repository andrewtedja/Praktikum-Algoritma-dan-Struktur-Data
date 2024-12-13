#include "save_load.h"
#include "login_logout.h"
#include "mulai.h"
#include <stdio.h>
#include <stdlib.h>

void loadUserConfig(const char *filePath) {
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Terjadi kegagalan dalam membuka file pengguna.config.\n");
        return;
    }

    fscanf(file, "%d\n", &daftarUser.length);
    daftarUser.array = (User *)malloc(daftarUser.capacity * sizeof(User));
    for (int i = 0; i < daftarUser.length; i++) {
        fscanf(file, "%s\n", daftarUser.array[i].id);
        fscanf(file, "%s\n", daftarUser.array[i].email);
        fscanf(file, "%s\n", daftarUser.array[i].password);
    }

    fclose(file);
}

void saveUserConfig(const char *filePath) {
    FILE *file = fopen(filePath, "w");
    if (file == NULL) {
        printf("Terjadi kegagalan dalam membuka file pengguna.config.\n");
        return;
    }
    // Efisiensi length untuk menghindari baris kosong pada file pengguna.config
    for (int i = daftarUser.length - 1; i >= 0; i--) {
        if (daftarUser.array[i].id[0] != '\0') {
            daftarUser.length = i + 1;
            break;
        }
    }
    fprintf(file, "%d\n", daftarUser.length);
    for (int i = 0; i < daftarUser.length; i++) {
        fprintf(file, "%s\n", daftarUser.array[i].id);
        fprintf(file, "%s\n", daftarUser.array[i].email);
        fprintf(file, "%s\n", daftarUser.array[i].password);
    }

    fclose(file);
}

void freeUserConfig() {
    if (daftarUser.array != NULL) {
        free(daftarUser.array);
        daftarUser.array = NULL;
    }
}