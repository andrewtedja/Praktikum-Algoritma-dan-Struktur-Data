# ifndef DATABASE_H
# define DATABASE_H

# include "boolean.h"
# include "customADT_email-list.h"
# include "customADT_email-reply-tree.h"
# include "customADT_user-list.h"

/* ========== ADT Database ========== */

/* Definisi Database */
typedef struct {
    int currentUserID;          // user id yang sedang login
    char currentPage;           // kode page yg sedang aktif
    /* Keterangan:
        s = start/initiation page
        l = login page
        h = home page (yang ada notifnya itu loh)
        d = draft page
        i = inbox page
        r = reply page
    */
    int configMaxInbox;         // konfigurasi umum: maksimum data yg ditampilkan di inbox
    int configImportance;       // konfigurasi umum: minimal interaksi yg dianggap important
    EmailList databaseEmail;    // konfigurasi email: [Email, Email, Email] berisi semua email yang ada
    UserList databaseUser;      // konfigurasi user: [User, User, User] berisi semua user yang terdaftar
    BinTree databaseReply;      // berisi email yg direply
} Database;

/* ========== AKSES dengan Selektor ========== */
# define curUserID(d)       (d).currentUserID
# define curPage(d)         (d).currentPage
# define confMaxInbox(d)    (d).configMaxInbox
# define confImportance(d)  (d).configImportance
# define dataEmail(d)       (d).databaseEmail
# define dataUser(d)        (d).databaseUser
# define dataReply(d)       (d).databaseReply

/* ========== Operasi ADT Database ========== */

/* KONSTRUKTOR */
void CreateDatabase(Database *data);
/*  I.S sembarang
    F.S terbentuk database kosong, currentUserID dan currentPage default
*/

# endif
