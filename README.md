# 📚 Sistem Manajemen Perpustakaan Modern (SMPM) - Kelompok 4

> **Proyek UAS Praktikum Algoritma dan Struktur Data**
>
> Sistem Manajemen Perpustakaan Modern merupakan aplikasi berbasis **C++ Console** yang menerapkan konsep **Singly Linked List**, **Queue**, dan **Stack** untuk mengelola koleksi buku, layanan antrean mahasiswa, serta pencatatan riwayat transaksi perpustakaan.

---

## 📂 Struktur Folder Proyek

```
Sistem-Manajemen-Perpustakaan-Modern/
│
├── docs/
│   ├── Laporan.pdf
│   ├── Flowchart.pdf
│   └── PPT Sistem Manajemen Perpustakaan Modern.pptx
│
├── src/
│   └── Main.cpp
│
├── .gitignore
│
└── README.md
```

**Keterangan Folder**
- **docs/** : Berisi dokumen pendukung proyek.
  - `Laporan.pdf`
  - `Flowchart.pdf`
  - `PPT Sistem Manajemen Perpustakaan Modern.pptx`
- **src/** : Berisi source code utama (`Main.cpp`).
- **.gitignore** : Mengabaikan file yang tidak perlu diunggah ke Git.
- **README.md** : Dokumentasi proyek dan pembagian tugas.

---

**Keterangan Folder:**
- **docs/** : Berisi dokumen pendukung proyek (Laporan, Flowchart, dan PPT).
- **src/** : Berisi source code utama (`Main.cpp`).
- **.gitignore** : Mengabaikan file yang tidak perlu diunggah ke Git.
- **README.md** : Dokumentasi proyek dan pembagian tugas kelompok.

---

# 👥 Tim Pengembang & Pembagian Tugas

Proyek ini dikembangkan menggunakan **Git Branching Workflow**, di mana setiap anggota mengerjakan modul yang berbeda di cabangnya masing-masing, kemudian digabungkan (*merge*) ke branch utama.

---

## 01. Aditya Maulana Firdaus — Ketua / Lead Developer & Integrator
**NIM:** 2503010003

### Modul
Core Architecture, Utility Function, Main Program, dan Integrasi Sistem.

### Tanggung Jawab
- Mendesain struktur program secara keseluruhan.
- Membuat fungsi utilitas inti:
  - `toLowerManual()` (konversi huruf kecil)
  - `angkaKeStringManual()` (konversi angka ke string)
- Menyusun fungsi utama `main()` beserta alur navigasi menu aplikasi.
- Menambahkan validasi input menu guna mencegah *error/crash*.
- Mengintegrasikan seluruh berkas kiriman dari setiap anggota kelompok.
- Melakukan testing, debugging, merge branch, dan finalisasi program.

---

## 02. Nazwa Allia Kusmana — Book Database Module
**NIM:** 2503010036

### Modul
Linked List Initialization & Book Database

### Daftar Fungsi
- `sisipBuku()`
- `loadDatabaseBuku()`
- `tampilkanSemuaBuku()`
- `rekomendasiBuku()`
- `cariBuku()`

### Tanggung Jawab
Mengelola penyimpanan data buku menggunakan struktur data **Singly Linked List**, memuat data awal bawaan (*hardcoded*) perpustakaan, menampilkan seluruh daftar koleksi buku, serta melakukan pencarian buku berdasarkan judul maupun ID.

---

## 03. Sri Agnia — Collection Management Module
**NIM:** 2503010040

### Modul
Collection Management & Sorting

### Daftar Fungsi
- `tambahBuku()`
- `hapusBuku()`
- `urutkanBuku()`
- `pushRiwayat()`

### Tanggung Jawab
Mengembangkan fitur rekomendasi buku pintar, penambahan koleksi buku baru via input user, penghapusan koleksi dari list berdasarkan ID buku, serta pengurutan data buku (A-Z) menggunakan algoritma **Bubble Sort** berbasis manipulasi pointer.

---

## 04. Devina Putri Nur Aliah — Queue Service Module
**NIM:** 2503010045

### Modul
Queue Service & Book Borrowing

### Daftar Fungsi
- `tambahAntreanLoket()`
- `tampilkanSemuaAntrean()`
- `panggilAntreanLoket()`
- `pinjamBuku()`

### Tanggung Jawab
Mengembangkan sistem antrean pelayanan loket perpustakaan menggunakan prinsip **Queue (FIFO)**, menampilkan daftar antrean aktif, memanggil mahasiswa sesuai urutan antrean untuk dilayani di meja loket, serta menangani proses peminjaman buku.

---

## 05. Rezki Ahmad Fauzi — Transaction & Report Module
**NIM:** 2503010018

### Modul
Book Return, Stack & Reporting

### Daftar Fungsi
- `kembalikanBuku()`
- `lihatRiwayatTransaksi()`
- `lihatLaporanKeuanganDenda()`
- `hapusRiwayatTerbaru()`

### Tanggung Jawab
Mengembangkan modul pengembalian buku, melakukan pencatatan setiap riwayat transaksi yang sukses ke dalam struktur data **Stack (LIFO)**, mengelola laporan akumulasi keuangan denda kas perpustakaan, serta menyediakan fitur pembatalan/penghapusan riwayat transaksi paling atas (*Pop Stack*).

---

# 🚀 Fitur Program

| No | Fitur Utama | Struktur Data Pendukung | Pendekatan / Algoritma |
|:--:|:------------|:------------------------|:-----------------------|
| 1 | Database Koleksi Buku | Singly Linked List | Dynamic Memory Allocation |
| 2 | Pencarian Buku | Singly Linked List | Sequential Search |
| 3 | Pengurutan Buku (A-Z) | Singly Linked List | Bubble Sort (Pointer Manipulation) |
| 4 | Antrean Loket Mahasiswa| Queue | FIFO (First In First Out) |
| 5 | Riwayat Sirkulasi | Stack | LIFO (Last In First Out) |
| 6 | Laporan Kas Denda | Variabel Global & Stack | Akumulasi Data Dinamis |

---

# 🔗 Integrasi Antar Modul

Program dirancang agar seluruh struktur data terhubung secara logis sehingga membentuk satu ekosistem perpustakaan yang utuh:

1. **Queue ➜ Transaksi Buku**: Mahasiswa diwajibkan mengambil nomor antrean loket terlebih dahulu. Transaksi peminjaman atau pengembalian hanya dapat diproses apabila ada mahasiswa aktif yang sedang dilayani di meja loket.
2. **Linked List ➜ Status Buku**: Setiap kali transaksi peminjaman (sukses) atau pengembalian dilakukan, sistem otomatis merubah status ketersediaan (`bool tersedia`) pada node buku di Linked List.
3. **Transaksi ➜ Stack**: Seluruh data transaksi yang berhasil dieksekusi akan otomatis dibungkus menjadi informasi teks lalu di-*push* ke dalam Stack sebagai rekam jejak riwayat.
4. **Pengembalian ➜ Kas Denda**: Jika pengembalian buku melewati batas waktu peminjaman, sistem menghitung denda secara otomatis dan langsung mengakumulasikannya ke kas denda perpustakaan.
5. **Sorting ➜ Tampilan Buku**: Setelah proses pengurutan pointer selesai, daftar buku akan langsung diperbarui dalam keadaan terurut rapi dari A sampai Z.

---

# 🗺️ Struktur Menu Program

### 📖 Menu 1 — Manajemen Koleksi Buku
- Tampilkan Semua Buku
- Cari Buku Berdasarkan Judul / ID
- Rekomendasi Buku
- Urutkan Buku (A-Z)
- Tambah Buku
- Hapus Buku

### 🧾 Menu 2 — Layanan Loket Perpustakaan
- Tambah Antrean Mahasiswa
- Lihat Antrean Aktif
- Panggil / Proses Antrean Terdepan
- Layanan Peminjaman Buku
- Layanan Pengembalian Buku

### 📊 Menu 3 — Laporan & Sirkulasi Perpustakaan
- Lihat Riwayat Transaksi Terbaru
- Lihat Laporan Kas Keuangan Denda
- Hapus Riwayat Transaksi Terbaru (Pop)

### 🚪 Menu 4 — Keluar Program
Saat program ditutup, sistem akan menjalankan proses *deallokasi memori*. Seluruh node sisa pada struktur **Linked List**, **Queue**, dan **Stack** akan dihapus menggunakan perintah `delete` untuk memastikan **tidak terjadi memory leak**.

---

# 💻 Teknologi yang Digunakan

- **Bahasa Pemrograman** : C++ (Standard Template Library minimal / Murni Pointer Objek)
- **IDE Pengembangan** : Code::Blocks / Visual Studio Code
- **Struktur Data** : Singly Linked List, Queue (FIFO), Stack (LIFO)
- **Version Control** : Git & GitHub

---

# 📖 Informasi Akademik

* **Mata Kuliah** : Praktikum Algoritma dan Struktur Data
* **Program Studi** : Teknik Informatika
* **Institusi** : Universitas Perjuangan Tasikmalaya
* **Kelompok** : 4 
