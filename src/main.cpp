#include <iostream>
#include <string>

using namespace std;

struct NodeBuku {
    string idBuku;
    string judul;
    string pengarang;
    bool tersedia;
    NodeBuku* next;
};

struct NodeQueue {
    string namaMahasiswa;
    string nim;            
    string keperluan;      
    NodeQueue* next;
}; 

struct NodeStack {
    string infoTransaksi;
    NodeStack* next;
};

NodeBuku* headBuku = NULL;
NodeQueue* frontQueue = NULL;
NodeQueue* rearQueue = NULL;
NodeStack* topStack = NULL;

string mahasiswaAktif = "";
string nimAktif = "";      
string keperluanAktif = "";

int totalDendaPerpus = 0;

string toLowerManual(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] = s[i] + 32; 
        }
    }
    return s;
}

string angkaKeStringManual(int angka) {
    if (angka == 0) return "0";
    string hasil = "";
    while (angka > 0) {
        char digit = (angka % 10) + '0';
        hasil = digit + hasil;
        angka /= 10;
    }
    return hasil;
}


// ============================================================================
// TUGAS 1 - Modul Linked List Initialization & Book Database (Oleh: Nazwa)
// ============================================================================

void sisipBuku(string id, string judul, string pengarang, bool tersedia) {

}

void loadDatabaseBuku() {

}

void tampilkanSemuaBuku() {

}

void rekomendasiBuku(string idBukuAsli, string pengarangAsli, string judulAsli) {

}

void cariBuku() {

}


// ============================================================================
// --- TUGAS 2 - Modul Collection Management & Sorting (Oleh: Sri agnia) ---
// ============================================================================

void tambahBuku() {

}

void hapusBuku() {

}

void urutkanBuku() {

}

void pushRiwayat(string info) {

}


// ============================================================================
// --- TUGAS 3 - Modul Queue Service & Book Borrowing (Oleh: Devina) ---
// ============================================================================

void tambahAntreanLoket() {

}

void tampilkanSemuaAntrean() {

}

void panggilAntreanLoket() {

}

void pinjamBuku() {

}


// ============================================================================
// --- TUGAS 4 - Modul Book Return, Stack & Reporting (Oleh: Rezki) ---
// ============================================================================

void kembalikanBuku() {

}

void lihatRiwayatTransaksi() {

}

void lihatLaporanKeuanganDenda() {

}

void hapusRiwayatTerbaru(){
	
}


// ===================================================================================================================
// --- Tugas 5 Modul Core Architecture, Utility Function, Main Program, dan Integrasi Sistem. (Oleh: Aditya Maulana F) ---
// ===================================================================================================================

int main() {
    loadDatabaseBuku(); 
    int menuUtama, subMenu;

    do {
        cout << "\n==================================================\n";
        cout << "                      \n";
        cout << "          SISTEM MANAJEMEN PERPUSTAKAAN           \n";
        cout << "                      \n";
        cout << "==================================================\n";
        cout << " [1] Menu Manajemen Koleksi Buku\n";
        cout << " [2] Menu Layanan Loket (Antrean & Transaksi)\n";
        cout << " [3] Menu Laporan Sirkulasi & Keuangan Perpustakaan\n";
        cout << " [4] Keluar Aplikasi\n";
        cout << "==================================================\n";
        cout << " Pilih Menu Utama (1-4): ";

        if (!(cin >> menuUtama)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n[Error] Input harus berupa angka!\n";
            continue;
        }
        cin.ignore();     
        switch(menuUtama) {
            case 1:
                do {
                    cout << "\n--- SUB-MENU: MANAJEMEN KOLEKSI BUKU ---\n";
                    cout << " [1] Tampilkan Semua Koleksi Buku\n";
                    cout << " [2] Cari Buku Berdasarkan Judul/ID & Rekomendasi\n";
                    cout << " [3] Urutkan Buku Berdasarkan Judul (A-Z)\n";
                    cout << " [4] Tambah Buku Baru\n";
                    cout << " [5] Hapus Koleksi Buku\n";
                    cout << " [6] Kembali ke Menu Utama\n";
                    cout << " Pilih Tindakan (1-6): ";
                    if (!(cin >> subMenu)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\n[Error] Input harus berupa angka!\n";
                        continue;
                    }
                    cin.ignore();
                    switch(subMenu) {
                        case 1: tampilkanSemuaBuku(); break;
                        case 2: cariBuku(); break;
                        case 3: urutkanBuku(); break;
                        case 4: tambahBuku(); break;
                        case 5: hapusBuku(); break;
                        case 6: break; 
                        default:
                            cout << "\n[Peringatan] Pilihan salah! Harap masukkan angka 1-6.\n";
                            break;
                    }
                } while (subMenu != 6);
                break;

            case 2:
                do {
                    cout << "\n--- SUB-MENU: LAYANAN LOKET PERPUS ---\n";
                    cout << " [1] Ambil Nomor Antrean Mahasiswa \n";
                    cout << " [2] Lihat Daftar Seluruh Antrean Aktif\n"; 
                    cout << " [3] Panggil/Proses Antrean Terdepan\n";
                    cout << " [4] Layanan Peminjaman Buku\n";
                    cout << " [5] Layanan Pengembalian Buku\n";
                    cout << " [6] Kembali ke Menu Utama\n";
                    cout << " Pilih Tindakan (1-6): ";
                    if (!(cin >> subMenu)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\n[Error] Input harus berupa angka!\n";
                        continue;
                    }
                    cin.ignore();
                    switch(subMenu) {
                        case 1: tambahAntreanLoket(); break;
                        case 2: tampilkanSemuaAntrean(); break; 
                        case 3: panggilAntreanLoket(); break;
                        case 4: pinjamBuku(); break;
                        case 5: kembalikanBuku(); break;
                        case 6: break; 
                        default:
                            cout << "\n[Peringatan] Pilihan salah! Harap masukkan angka 1-6.\n";
                            break;
                    }
                } while (subMenu != 6);
                break;

            case 3:
                do {
                    cout << "\n--- SUB-MENU: LAPORAN & SIRKULASI ---\n";
                    cout << " [1] Lihat Riwayat Transaksi Terbaru\n";
                    cout << " [2] Lihat Laporan Kas Denda\n"; 
                    cout << " [3] Hapus Riwayat Transaksi Terbaru\n";
                    cout << " [4] Kembali ke Menu Utama\n";
                    cout << " Pilih Tindakan (1-4): ";
                    if (!(cin >> subMenu)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "\n[Error] Input harus berupa angka!\n";
                        continue;
                    }
                    cin.ignore();
                    switch(subMenu) {
                        case 1: lihatRiwayatTransaksi(); break;
                        case 2: lihatLaporanKeuanganDenda(); break; 
                        case 3: hapusRiwayatTerbaru(); break;
                        case 4: break; 
                        default:
                            cout << "\n[Peringatan] Pilihan salah! Harap masukkan angka 1-4.\n";
                            break;
                    }
                } while (subMenu != 4);
                break;

            case 4:
                cout << "\n>> Keluar dari sistem perpustakaan. Sesi selesai!\n";
                while (headBuku != NULL) {
                    NodeBuku* temp = headBuku;
                    headBuku = headBuku->next;
                    delete temp;
                }
                while (frontQueue != NULL) {
                    NodeQueue* temp = frontQueue;
                    frontQueue = frontQueue->next;
                    delete temp;
                }
                while (topStack != NULL) {
                    NodeStack* temp = topStack;
                    topStack = topStack->next;
                    delete temp;
                }
                break; 

            default:
                cout << "\n[Peringatan] Pilihan salah! Harap masukkan angka 1-4.\n";
        }
    } while (menuUtama != 4);

    return 0;
}
