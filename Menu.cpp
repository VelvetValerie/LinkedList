#include <iostream>
#include <string>
#include <limits> // DITAMBAHKAN: Library untuk menangani buffer input dengan lebih baik.

using namespace std;

// Struktur Buah (Tidak ada perubahan)
struct Buah {
    string nama;
    int jumlah;
    Buah* next;
};

// DITAMBAHKAN: Deklarasi fungsi (prototypes) untuk praktik pemrograman yang baik.
void tambahBuah(Buah*& head);
void daftarBuah(Buah* head);
void cariBuah(Buah* head);
void hapusBuah(Buah*& head);
void urutkanBuah(Buah* head); 
void tukarData(Buah* a, Buah* b);

// --- FUNGSI BARU ---
// DITAMBAHKAN: Fungsi pembantu untuk menukar data, digunakan oleh urutkanBuah.
void tukarData(Buah* a, Buah* b) {
    string tempNama = a->nama;
    int tempJumlah = a->jumlah;
    a->nama = b->nama;
    a->jumlah = b->jumlah;
    b->nama = tempNama;
    b->jumlah = tempJumlah;
}

// --- Implementasi Fungsi ---

// DIUBAH: Fungsi ini sekarang hanya menambahkan satu buah dan kembali ke menu.
void tambahBuah(Buah*& head) {
    Buah* baru = new Buah();
    // ... (Logika input dan validasi tetap sama)
    do {
        cout << "Masukkan nama buah: ";
        getline(cin, baru->nama);
        if (baru->nama.empty()) {
            cout << "[ERROR] Nama buah tidak boleh kosong!\n";
        }
    } while (baru->nama.empty());

    do {
        cout << "Masukkan jumlah: ";
        cin >> baru->jumlah;
        if (cin.fail() || baru->jumlah <= 0) {
            cout << "[ERROR] Jumlah harus angka positif!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            baru->jumlah = 0;
        }
    } while (baru->jumlah <= 0);

    baru->next = nullptr;
    if (head == nullptr) {
        head = baru;
    } else {
        Buah* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "\nBuah '" << baru->nama << "' berhasil ditambahkan!\n";

    // DIHAPUS: Perulangan "Tambah buah lagi? (y/n)" yang tadinya ada di dalam fungsi ini.
}

// DIUBAH: Sama seperti fungsi lainnya, perulangan internal dihapus.
void daftarBuah(Buah* head) {
    cout << "\n--- Daftar Buah ---\n";
    if (head == nullptr) {
        cout << "Belum ada buah di dalam inventori.\n";
    } else {
        int no = 1;
        Buah* temp = head;
        while (temp != nullptr) {
            cout << no++ << ". " << temp->nama << " (Jumlah: " << temp->jumlah << ")\n";
            temp = temp->next;
        }
    }
    cout << "--------------------\n";
    
    // DIHAPUS: Perulangan "Lihat daftar buah lagi? (y/n)".
}

// DIUBAH: Perulangan internal dihapus.
void cariBuah(Buah* head) {
    if (head == nullptr) {
        cout << "\nInventori masih kosong.\n";
        return;
    }
    string cari;
    cout << "Masukkan nama buah yang dicari: ";
    getline(cin, cari);

    Buah* temp = head;
    bool ditemukan = false;
    while (temp != nullptr) {
        if (temp->nama == cari) {
            cout << "\nBuah ditemukan: " << temp->nama << " (Jumlah: " << temp->jumlah << ")\n";
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }
    if (!ditemukan) {
        cout << "\nBuah dengan nama '" << cari << "' tidak ditemukan.\n";
    }

    // DIHAPUS: Perulangan "Cari buah lagi? (y/n)".
}

// DIUBAH: Perulangan internal dihapus.
void hapusBuah(Buah*& head) {
    if (head == nullptr) {
        cout << "\nInventori masih kosong.\n";
        return;
    }
    string hapusNama;
    cout << "Masukkan nama buah yang ingin dihapus: ";
    getline(cin, hapusNama);

    Buah* temp = head;
    Buah* prev = nullptr;
    bool ditemukan = false;
    // ... (Logika penghapusan tetap sama)
    while (temp != nullptr) {
        if (temp->nama == hapusNama) {
            if (prev == nullptr) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "\nBuah '" << hapusNama << "' berhasil dihapus.\n";
            ditemukan = true;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (!ditemukan) {
        cout << "\nBuah dengan nama '" << hapusNama << "' tidak ditemukan.\n";
    }

    // DIHAPUS: Perulangan "Hapus buah lagi? (y/n)".
}

// --- FUNGSI BARU ---
// DITAMBAHKAN: Seluruh blok fungsi untuk mengurutkan daftar buah.
void urutkanBuah(Buah* head) {
    if (head == nullptr || head->next == nullptr) {
        cout << "\nTidak cukup buah untuk diurutkan.\n";
        return;
    }
    int kriteria;
    cout << "\n--- Urutkan Berdasarkan ---\n";
    cout << "1. Nama (A-Z)\n";
    cout << "2. Jumlah (Sedikit ke Banyak)\n";
    cout << "Pilih kriteria: ";
    cin >> kriteria;

    if (kriteria != 1 && kriteria != 2) {
        cout << "\n[ERROR] Pilihan kriteria tidak valid.\n";
        return;
    }

    bool ditukar;
    do {
        ditukar = false;
        Buah* current = head;
        while (current->next != nullptr) {
            bool harusTukar = false;
            if (kriteria == 1 && current->nama > current->next->nama) {
                harusTukar = true;
            } else if (kriteria == 2 && current->jumlah > current->next->jumlah) {
                harusTukar = true;
            }
            
            if (harusTukar) {
                tukarData(current, current->next);
                ditukar = true;
            }
            current = current->next;
        }
    } while (ditukar);

    cout << "\nDaftar buah berhasil diurutkan!\n";
    cout << "Pilih menu '2. Lihat Daftar Buah' untuk melihat hasilnya.\n";
}

// --- Fungsi Utama (main) ---
int main() {
    Buah* head = nullptr;
    int pilihan;

    do {
        // DIUBAH: Tampilan menu dibuat sedikit lebih rapi dan ada tambahan opsi baru.
        cout << "\n===============================\n";
        cout << "===   Menu Inventori Buah   ===\n";
        cout << "===============================\n";
        cout << "1. Tambah Buah\n";
        cout << "2. Lihat Daftar Buah\n";
        cout << "3. Cari Buah\n";
        cout << "4. Hapus Buah\n";
        cout << "5. Urutkan Daftar Buah\n"; // DITAMBAHKAN: Opsi menu baru.
        cout << "0. Keluar\n";
        cout << "===============================\n";
        cout << "Pilih menu: ";

        cin >> pilihan;

        // DITAMBAHKAN: Blok validasi untuk memastikan input adalah angka.
        if (cin.fail()) {
            cout << "\n[ERROR] Input tidak valid. Harap masukkan angka sesuai menu.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            pilihan = -1;
            continue;
        }
        
        // DITAMBAHKAN: Baris krusial untuk membersihkan buffer input setelah `cin >>`.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch(pilihan) {
            case 1:
                tambahBuah(head);
                break;
            case 2:
                daftarBuah(head);
                break;
            case 3:
                cariBuah(head);
                break;
            case 4:
                hapusBuah(head);
                break;
            // DITAMBAHKAN: Case untuk memanggil fungsi baru.
            case 5:
                urutkanBuah(head);
                break;
            case 0:
                cout << "\nKeluar dari program...\n";
                break;
            default:
                cout << "\n[ERROR] Pilihan tidak valid. Silakan coba lagi.\n";
        }
        
        // DITAMBAHKAN: Blok untuk menjeda program agar pengguna bisa melihat output sebelum kembali ke menu.
        if (pilihan != 0) {
             cout << "\nTekan Enter untuk kembali ke menu...";
             cin.get();
        }

    } while(pilihan != 0);

    // Pembersihan memori (Tidak ada perubahan, sudah benar dari awal)
    while (head != nullptr) {
        Buah* hapus = head;
        head = head->next;
        delete hapus;
    }
    
    return 0;
}
