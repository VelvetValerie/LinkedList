#include <iostream>
#include <string>
using namespace std;

//Struktur node buah
struct Buah {
    string nama;
    int jumlah;
    Buah* next;
};

//Fungsi untuk menambahkan buah
//Jika daftar buah tidak ada, maka buah baru akan menjadi head
void tambahBuah(Buah*& head) {
    char ulang;
    do {
    Buah* baru = new Buah();
    cin.ignore();
    do {
        cout << "Masukkan nama buah: ";
        getline(cin, baru->nama);
        if (baru->nama.empty()) {
            cout << "Nama buah tidak boleh kosong!\n";
        }
    } while (baru->nama.empty());

    do {
        cout << "Masukkan jumlah: ";
        cin >> baru->jumlah;
        if (cin.fail() || baru->jumlah <= 0) {
            cout << "Jumlah harus angka positif!\n";
            cin.clear();
            cin.ignore(1000, '\n');
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
    cout << "Buah berhasil ditambahkan!\n";
    cout << "Tambah buah lagi? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'y' || ulang == 'Y');
}

//Fungsi untuk menampilkan daftar buah
//Jika daftar buah kosong, maka tampil pesan "Belum ada buah"
void daftarBuah(Buah* head) {
    char ulang;
    do {
        if (head == nullptr) {
            cout << "Belum ada buah.\n";
        } else {
            cout << "Daftar Buah:\n";
            int no = 1;
            Buah* temp = head;
            while (temp != nullptr) {
                cout << no++ << ". " << temp->nama << " (Jumlah: " << temp->jumlah << ")\n";
                temp = temp->next;
            }
        }
        cout << "Lihat daftar buah lagi? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'y' || ulang == 'Y');
}

//Fungsi untuk mencari buah berdasarkan nama
//Jika buah ada pada daftar, tampilkan nama dan jumlahnya
//Jika tidak ada, maka pesan "Buah tidak ditemukan" akan tampil.
void cariBuah(Buah* head) {
    char ulang;
    do {
    if (head == nullptr) {
        cout << "Belum ada buah.\n";
        return;
    }
    cin.ignore();
    string cari;
    cout << "Masukkan nama buah yang dicari: ";
    getline(cin, cari);

    Buah* temp = head;
    bool ditemukan = false;
    while (temp != nullptr) {
        if (temp->nama == cari) {
            cout << "Buah ditemukan: " << temp->nama << " (Jumlah: " << temp->jumlah << ")\n";
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }
    if (!ditemukan) {
        cout << "Buah tidak ditemukan.\n";
    }
    cout << "Cari buah lagi? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'y' || ulang == 'Y');
}

// Fungsi untuk menghapus buah berdasarkan nama
// Jika buah ditemukan, hapus buah tersebut dan tampilkan pesan berhasil
// Jika tidak ditemukan, tampilkan pesan "Buah tidak ditemukan"
void hapusBuah(Buah*& head) {
    char ulang;
    do {
        if (head == nullptr) {
            cout << "Belum ada buah.\n";
            return;
        }
        cin.ignore(); // Tambahkan baris ini untuk membersihkan buffer
        string hapusNama;
        cout << "Masukkan nama buah yang ingin dihapus: ";
        getline(cin, hapusNama);

        Buah* temp = head;
        Buah* prev = nullptr;
        bool ditemukan = false;
        while (temp != nullptr) {
            if (temp->nama == hapusNama) {
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Buah berhasil dihapus.\n";
                ditemukan = true;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
        if (!ditemukan) {
            cout << "Buah tidak ditemukan.\n";
        }
        cout << "Hapus buah lagi? (y/n): ";
        cin >> ulang;
        cin.ignore();
    } while (ulang == 'y' || ulang == 'Y');
}

int main() {
    Buah* head = nullptr;
    int pilihan;
    do {
        cout << "\n=== Menu Inventori ===\n" << endl;
        cout << "1. Tambah Buah\n" << endl;
        cout << "2. Daftar Buah\n" << endl;
        cout << "3. Cari Buah\n" << endl;
        cout << "4. Hapus Buah\n" << endl;
        cout << "0. Keluar\n" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Fitur Tambah buah\n";
                tambahBuah(head);
                break;
            case 2:
                cout << "Fitur Daftar buah\n";
                daftarBuah(head);
                break;
            case 3:
                cout << "Fitur Cari buah\n";
                cariBuah(head);
                break;
            case 4:
                cout << "Fitur Hapus buah\n";
                hapusBuah(head);
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        cout << endl;
    } while(pilihan != 0);

    while (head != nullptr) {
        Buah* hapus = head;
        head = head->next;
        delete hapus;
    }
    return 0;
}