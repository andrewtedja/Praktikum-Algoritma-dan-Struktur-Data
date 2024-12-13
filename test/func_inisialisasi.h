# include "boolean.h"
# include "adt_mesinkarakter.h"
# include "adt_mesinkata.h"
# include "customADT_database.h"

// PENTING: kita menggunakan Database *data sebagai passing variabel
// perhatikan cara akses database di database.h
// gunakan/ubah database seperlunya saja (yg dijelaskan di I.S, F.S, Proses)

// note: tambahkan include sesuai kebutuhan

/* INISIALISASI */
void inisialisasi(Database *data);
/*  I.S database terdefinisi dan kosong
    F.S database terisi dengan file-file config
    Proses: - meminta input folderpath
            - melakukan load terhadap file-filenya
            - membuat file config kosong apabila foldernya kosong (belum ada file config sebelumnya)
                - menetapkan default value untuk konfigurasi umum
*/

/* REGISTER */
void regisUser(Database *data);
/*  I.S databaseUser sembarang
    F.S - jika databaseUser tidak penuh, User baru ditambahkan
        - jika databaseUser penuh, abort dan muncul pesan kesalahan
    Proses: meminta input nama email, password, generate id baru, dan memasukkannya ke UserList
            lakukan validasi terhadap input
*/

/* LOGIN */
void login(Database *data);
/*  I.S - currentUserID = 0 (artinya pasti belum ada yg login), 
        - currentPage = 'l'
    F.S - currentUserID adalah user id yang berhasil login, 
        - currentPage = 'h'
    Proses: meminta input sesuai spesifikasi
            lakukan validasi terhadap input
*/

/* LOGOUT */
void logout(Database *data);
/*  I.S - currentUserID > 0 (artinya pasti sudah ada yg login), 
        - currentPage='h'
    F.S - currentUserID menjadi 0, 
        - currentPage='l'
    Proses: mengubah kondisi kedua parameter
            lakukan validasi terhadap input
*/