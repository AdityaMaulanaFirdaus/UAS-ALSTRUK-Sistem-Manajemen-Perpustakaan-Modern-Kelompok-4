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
    string id;
    cout << "\nMasukkan ID Buku Baru: "; getline(cin, id);
    
    NodeBuku* temp = headBuku;
    while (temp != NULL) {
        if (toLowerManual(temp->idBuku) == toLowerManual(id)) {
            cout << "[Error] ID Buku '" << id << "' sudah terdaftar di sistem!\n";
            return;
        }
        temp = temp->next;
    }

    string judul, pengarang;
    cout << "Masukkan Judul Buku : "; getline(cin, judul);
    cout << "Masukkan Pengarang  : "; getline(cin, pengarang); 
    
    sisipBuku(id, judul, pengarang, true);
    cout << "\n>> [Sukses] Buku \"" << judul << "\" berhasil ditambahkan ke rak!\n";
}

void hapusBuku() {
    
    if (headBuku == NULL) {
        cout << "\nPerpustakaan kosong, tidak ada buku untuk dihapus.\n";
        return;
    }
    string id;
    cout << "\nMasukkan ID Buku yang ingin dihapus: "; getline(cin, id);

    NodeBuku* temp = headBuku;
    NodeBuku* prev = NULL;

    while (temp != NULL && toLowerManual(temp->idBuku) != toLowerManual(id)) {
        prev = temp;
        temp = temp->next; 
    }

    if (temp == NULL) {
        cout << "\n[Info] Buku dengan ID '" << id << "' tidak ditemukan.\n";
        return;
    }
    
    if (!temp->tersedia) {
    cout << "\n[Peringatan] Buku sedang dipinjam sehingga tidak dapat dihapus.\n";
    return;
	}

    if (prev == NULL) { 
        headBuku = headBuku->next;
    } else {
        prev->next = temp->next;
    }
    delete temp;
    cout << "\n>> [Sukses] Buku dengan ID '" << id << "' berhasil dihapus.\n";

}

void urutkanBuku() {
     if (headBuku == NULL || headBuku->next == NULL) return;

    bool ditukar;
    NodeBuku* ptr1;
    NodeBuku* lptr = NULL; 

    do {
        ditukar = false;
        ptr1 = headBuku;
        NodeBuku* prev = NULL;

        while (ptr1->next != lptr) {
            if (toLowerManual(ptr1->judul) > toLowerManual(ptr1->next->judul)) {
                NodeBuku* nextNode = ptr1->next;
                
                ptr1->next = nextNode->next;
                nextNode->next = ptr1;

                if (prev == NULL) {
                    headBuku = nextNode; 
                } else {
                    prev->next = nextNode;
                }

                ditukar = true;
                ptr1 = nextNode; 
            }
            prev = ptr1;
            ptr1 = ptr1->next;
        }
        lptr = ptr1; 
    } while (ditukar);

    cout << "\n>> [Sukses] Seluruh koleksi buku berhasil diurutkan berdasarkan Judul Buku (A-Z) via Manipulasi Pointer!\n";
    tampilkanSemuaBuku();
}

void pushRiwayat(string info) {
    NodeStack* baru = new NodeStack;
    baru->infoTransaksi = info;
    baru->next = topStack;
    topStack = baru;
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
    if (mahasiswaAktif == "") {
        cout << "\n[Peringatan] Silakan panggil antrean loket terlebih dahulu sebelum melayani transaksi!\n";
        return;
    }
    if (toLowerManual(keperluanAktif) != "kembali") {
    cout << "\n[Peringatan] Mahasiswa ini mengambil antrean untuk peminjaman buku.\n";
    return;
	}
    string id;
    cout << "\n[Melayani: " << mahasiswaAktif << " - " << nimAktif << "]\nMasukkan ID Buku untuk dikembalikan: "; getline(cin, id);
    NodeBuku* temp = headBuku;

    while (temp != NULL) {
        if (toLowerManual(temp->idBuku) == toLowerManual(id)) {
            if (!temp->tersedia) {
                int hari;
                cout << "Berapa hari buku ini dipinjam? : "; cin >> hari; cin.ignore();
                
                temp->tersedia = true;
                string infoDenda = "";
                if (hari > 7) {
                    int denda = (hari - 7) * 5000;
                    totalDendaPerpus += denda; 
                    
                    infoDenda = " (Terlambat " + angkaKeStringManual(hari - 7) + " hari, Denda: Rp" + angkaKeStringManual(denda) + ")";
                    cout << "\n[Denda] Anda terlambat! Total denda sebesar Rp" << denda << " dimasukkan ke Kas Perpus.\n";
                }
                
                pushRiwayat(mahasiswaAktif + " (" + nimAktif + ") mengembalikan buku: " + temp->judul + infoDenda);
                cout << "\n>> [Sukses] Buku \"" << temp->judul << "\" telah diterima kembali.\n";
                mahasiswaAktif = ""; nimAktif = ""; keperluanAktif = "";
            } else {
                cout << "\n[Peringatan] Buku ini sudah ada di dalam rak perpustakaan.\n";
            }
            return;
        }
        temp = temp->next;
    }
    cout << "\n[Error] ID Buku tidak terdaftar.\n";
}

void lihatRiwayatTransaksi() {
    cout << "\n==================================================\n";
    cout << "        RIWAYAT TRANSAKSI TERBARU (STACK)          \n";
    cout << "==================================================\n";
    if (topStack == NULL) {
        cout << " Belum ada riwayat transaksi sirkulasi buku.\n";
        cout << "==================================================\n";
        return;
    }
    NodeStack* temp = topStack;
    int no = 1;
    while (temp != NULL) {
        cout << " [" << no++ << "] " << temp->infoTransaksi << "\n";
        temp = temp->next;
    }
    cout << "==================================================\n";
}

void lihatLaporanKeuanganDenda() {
    cout << "\n==================================================\n";
    cout << "       LAPORAN KAS PENDAPATAN DENDA PERPUS        \n";
    cout << "==================================================\n";
    cout << " Total Dana Terkumpul: Rp" << totalDendaPerpus << "\n";
    cout << " [Info] Seluruh dana denda akan dialokasikan untuk\n"; 
    cout << "        perawatan dan restok buku perpustakaan.\n";
    cout << "==================================================\n";
}

void hapusRiwayatTerbaru() {
    if (topStack == NULL) {
        cout << "\n[Info] Riwayat transaksi sudah kosong.\n";
        return;
    }
    NodeStack* temp = topStack;
    topStack = topStack->next;
    cout << "\n>> [Sukses] Riwayat: \"" << temp->infoTransaksi << "\" telah dihapus.\n";
    delete temp;
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
