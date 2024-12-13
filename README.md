<br />
<div align="center">
  <h1 align="center">Tugas Besar IF2110 Algoritma & Struktur Data ITB</h1>
  <p align="center">
    <h3> PurryMail</h3>
    <h4> Program simulasi Email dengan bahasa C </h4>
<br>
</p>
</div>
<div align="center" id="contributor">
  <strong>
    <h3>Dipersiapkan oleh Kelompok K03 - C</h3>
    <table align="center">
      <tr>
        <td style="text-align: center;">NIM</td>
        <td style="text-align: center;">Nama</td>
      </tr>
      <tr>
        <td style="text-align: center;">13523129</td>
        <td style="text-align: center;">Ivant Samuel Silaban</td>
      </tr>
      <tr>
        <td style="text-align: center;">13523142</td>
        <td style="text-align: center;">Nathanael Rachmat</td>
      </tr>
      <tr>
        <td style="text-align: center;">13523154</td>
        <td style="text-align: center;">Theo Kurniady</td>
      </tr>
      <tr>
        <td style="text-align: center;">13523158</td>
        <td style="text-align: center;">Lukas Raja Agripa</td>
      </tr>
      <tr>
        <td style="text-align: center;">13522160</td>
        <td style="text-align: center;">I Made Wiweka Putera</td>
      </tr>
    </table>
  </strong>
</div>

## External Links

-   [Link Drive](https://drive.google.com/drive/folders/1JAVO1-JrP30rbMhhLhjYVrhoF0vDTs09)
-   [Link Spesifikasi](https://docs.google.com/document/d/19kKYXkapPCNZzR6tMNw01RW-NoHgLkcz-Aj4VuKoD-M/edit?tab=t.0#heading=h.kfubrmne03ed)
-   [Link Q&A](https://docs.google.com/spreadsheets/d/1Bh_0vtsmF0947cgc54ObfWdCI-fS-AcO1k3jpzTXm5U/edit?usp=drive_web&ouid=106681560138166355842)
-   [Link Laporan](https://docs.google.com/document/d/1LMkrz6R9FI4Kr7ff8PmJTAjHgR_hN9lW/edit)

## Pendahuluan

Tugas besar ini bertujuan agar dapat mengenali dan memahami konsep dan dasar struktur data, mendesain dan mengimplementasi struktur data, melakukan pemecahan masalah menggunakan struktur data yang sesuai, dan dapat menggunakan struktur data yang telah disediakan oleh pustaka

<p align="center">
Anda dapat melihat spesifikasi tugas besar tersebut melalui link berikut :
<br>
<a href="https://docs.google.com/document/d/19kKYXkapPCNZzR6tMNw01RW-NoHgLkcz-Aj4VuKoD-M/edit?tab=t.0#heading=h.kfubrmne03ed"> <Strong>Spesifikasi Tugas Besar IF2110 Algoritma & Struktur Data 2024/2025</Strong>
</a>
</p>

<!-- GETTING STARTED -->

## Getting Started

### Prerequisites

Untuk melakukan kompilasi dan penggunaan Makefile diperlukan

-   Makefile
    ```sh
    # untuk Linux Ubuntu
    sudo apt install make
    ```
-   GCC
    ```sh
    # untuk Linux Ubuntu
    sudo apt install gcc
    ```

### Installation

_Berikut adalah proses instalasi_

1. Clone the repo
    ```sh
    https://github.com/Labpro-21/if2110-tugas-besar-2024-if2110-03-c.git
    ```
2. Install GCC
    ```sh
    sudo apt install gcc
    ```
3. Install Make
    ```sh
    sudo apt install make
    ```
4. CD to project directory
    ```sh
    cd if2110-tugas-besar-2024-if2110-03-c
    ```
5. Use Makefile to run the program
    ```sh
    make all
    ```
    <!-- INSTURCTION -->

## Instruction

Instruksi-instruksi yang dapat dilakukan :

`make build` : To build from source to binary into bin/main  
`make all` : Run binary directly after building  
`make clean` : Remove all build generated files

<!-- FEATURES -->

## Features

### Fitur Utama

### 1. Inisialisasi

Memuat database pengguna, email, data umum, data group, dan jadwal kesibuikan dari file konfigurasi untuk mendukung seluruh fitur aplikasi.

### 2. Perintah

Menyediakan berbagai perintah dan mengeksekusinya seperti (tidak terbatas padaa) login, logout, baca pesan, dan daftar inbox untuk navigasi sistem.

### 3. Pengguna

Mengelola informasi pengguna, termasuk autentikasi dengan fitur login/logout.
Daftar Perintah :

-   `REGISTER`: Mendaftarkan pengguna baru ke sistem.
-   `LOGIN`: Masuk ke sistem menggunakan email dan kata sandi.
-   `LOGOUT`: Keluar dari akun pengguna saat ini.

### 4. Draft Email

Membantu pengguna menyusun, menyimpan, mengubah, dan mengirim draft email.
Daftar Perintah :

-   `BUAT_DRAFT`: Membuat draft email baru.
-   `BATAL`: Membatalkan draft yang sedang dibuat.
-   `UBAH_DRAFT`: Mengedit draft yang sudah ada.
-   `KIRIM_DRAFT`: Mengirim email dari draft yang dipilih.
-   `LIHAT_DRAFT`: Menampilkan detail draft saat ini.
-   `UNDO`: Membatalkan perubahan terakhir pada draft.
-   `REDO`: Mengembalikan perubahan yang dibatalkan.

### 5. Inbox Utama Email

Menampilkan daftar email yang diterima pengguna dengan fitur pagination.
Daftar Perintah :

-   `DAFTAR_INBOX`: Menampilkan semua email yang diterima pengguna.
-   `LANJUT`: Navigasi ke halaman berikutnya dalam daftar inbox.
-   `SEBELUM`: Navigasi ke halaman sebelumnya dalam daftar inbox.
-   `BACA_PESAN`: Membaca detail email tertentu.
-   `KELUAR`: Keluar dari tampilan inbox.

### 6. Balas Email

Memungkinkan pengguna membalas email dengan subjek dan isi otomatis.
Daftar Perintah :

-   `BALAS_PESAN [EMAIL ID]`: Membalas email berdasarkan ID dengan menambahkan subjek otomatis (Re:)

### 7. Status Kepentingan

Memberikan label penting pada email untuk pengelompokan prioritas.
Daftar Perintah :

-   `STATUS_KEPENTINGAN`: Menandai atau menghapus tanda kepentingan pada email tertentu.

### 8. Notifikasi

Memberikan pemberitahuan untuk email baru dan tindakan penting lainnya.

### 9. Save & Load

Menyimpan dan memuat data ke/dari file konfigurasi.
Daftar Perintah :

-   `SAVE`: Menyimpan database pengguna, email, dan grup ke file konfigurasi.
-   `LOAD`: Memuat database dari file konfigurasi yang dipilih

### Fitur Tambahan

### 1. Enkripsi

Melindungi isi email dengan enkripsi sederhana untuk keamanan data.
Daftar Perintah :

-   `ENKRIPSI`: Menenkripsi pesan pada email.
-   `DEKRIPSI`: Mendekripsi pesan yang dienkripsi.

### 2. Starred Email

Memberi tanda bintang pada email penting untuk akses cepat ke inbox khusus.
Daftar Perintah :

-   `STAR [EMAIL ID]`: Menandai email dengan ID tertentu sebagai email penting.
-   `DAFTAR_STARRED`: Menampilkan daftar email yang diberi tanda bintang.
-   `UNSTAR [EMAIL ID]`: Menghapus tanda bintang dari email tertentu.

### 3. Mailing List

Membuat grup email untuk mengirim pesan ke banyak penerima sekaligus.
Daftar Perintah :

-   `BUAT_GROUP`: Membuat grup baru dengan nama tertentu dan daftar anggota.
-   `DAFTAR_GROUP`: Menampilkan daftar grup yang telah dibuat.
-   `BROADCAST [GROUPID]`: Mengirim email broadcast ke semua anggota group berdasarkan ID group.
-   `LIHAT [GROUPID]`: Melihat informasi group berdasarkan ID group.

### 4. Jadwal Kesibukan

Menyimpan jadwal kesibukan mingguan setiap agen sehingga agen-agen dapat melihat waktu luang agen lain.
Daftar Perintah :

-   `LIHAT_JADWAL`: Melihat jadwal kesibukan user sendiri.
-   `LIHAT_JADWAL [EMAIL USER]`: Menampilkan jadwal kesibuikan user lain berdasarkan email user lain yang diinput.
-   `UBAH_JADWAL`: Mengubah jadwal kesibukan user sendiri.

### 5. Scheduling

Menampilkan jadwal kesibukan gabungan seluruh agen yang diundang (termasuk diri sendiri).
Daftar Perintah :

-   `SCHEDULE [USER EMAILS]`: Menampilkan jadwal kesibukan gabungan antara diri sendiri dan seluruh agen yang diundang.
-   `LIHAT_JADWAL [EMAIL USER]`: Menampilkan jadwal kesibuikan user lain berdasarkan email user lain yang diinput.
-   `UBAH_JADWAL`: Mengubah jadwal kesibukan user sendiri.

<br>
<h3 align="center"> THANK YOU! </h3>
