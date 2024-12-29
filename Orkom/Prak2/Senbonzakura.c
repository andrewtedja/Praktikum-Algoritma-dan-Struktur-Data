/**
 * Nama: Andrew Tedjapratama
 * NIM: 13523148
 * Jawaban dari soal Senbonzakura
 */

#include <stdio.h>
#include <stdlib.h>

unsigned char key[6];
unsigned char expected[] = {
    0x11, 0x01, 0x31, 0x09,
    0x3f, 0x01, 0x11, 0x01,
    0x36, 0x44, 0x2e, 0x07,
    0x09, 0x05, 0x78, 0x09,
    0x2f, 0x0c, 0x03, 0x44,
    0x36, 0x0d, 0x7a, 0x06,
    0x03, 0x03, 0x39, 0x0d,
    0x7a, 0x0c, 0x03, 0x0f,
    0x3d, 0x44, 0x3e, 0x0d
};

void trap() {
    printf("trap");
    exit(1);
}

void java_adalah_key() {
    unsigned char temp_key[] = {0x62, 0x64, 0x58, 0x64, 0x5A, 0x68};
    for (int i = 0; i < 6; i++) {
        key[i] = temp_key[i];
    }
}

void what_is_this(const unsigned char *input, unsigned char *output, int length) {
    for (int i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % 6]; 
    }
}

int compare_arrays(const unsigned char *a, const unsigned char *b, int length) {
    for (int i = 0; i < length; i++) {
        if (a[i] != b[i]) {
            return 1; 
        }
    }
    return 0; 
}

int main() {
    java_adalah_key();

    int length = sizeof(expected) / sizeof(expected[0]);
    unsigned char *output = (unsigned char *)malloc(length);
    if (!output) {
        trap();
        return 1;
    }

    unsigned char *user_input = (unsigned char *)malloc(length);
    if (!user_input) {
        free(output);
        trap();
        return 1;
    }

    // Inputnya seimeisen toka muda ni naga dake de
    printf("Masukkan input: ");
    for (int i = 0; i < length; i++) {
        int c = getchar();
        if (c == EOF || c == '\n') {
            free(output);
            free(user_input);
            trap();
        }
        user_input[i] = (unsigned char)c;
    }

    // buat trap ketika enter
    int extra = getchar();
    if (extra != '\n' && extra != EOF) {
        free(output);
        free(user_input);
        trap();
    }

    what_is_this(user_input, output, length);

    if (compare_arrays(output, expected, length) == 0) {
        printf("Berhasil!");
    } else {
        free(output);
        free(user_input);
        trap();
    }

    free(output);
    free(user_input);
    return 0;
}
