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
void tambahBuah(Buah*& head) {
    Buah* baru = new Buah();
    cout << "Masukkan nama buah: ";
    cin.ignore();
    getline(cin, baru->nama);
    cout << "Masukkan jumlah: ";
    cin >> baru->jumlah;
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
}

void daftarBuah(Buah* head) {
    if (head == nullptr) {
        cout << "Belum ada buah.\n";
        return;
    }
    cout << "Daftar Buah:\n";
    int no = 1;
    while (head != nullptr) {
        cout << no++ << ". " << head->nama << " (Jumlah: " << head->jumlah << ")\n";
        head = head->next;
    }
}

int main() {
    int pilihan;
    do {
        cout << "=== Menu Inventori ===" << endl;
        cout << "1. Tambah Buah" << endl;
        cout << "2. Daftar Buah" << endl;
        cout << "3. Cari Buah" << endl;
        cout << "4. Hapus Buah" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                cout << "Fitur Tambah buah\n";
                // Tambahkan kode tambah buah di sini
                break;
            case 2:
                cout << "Fitur Daftar buah\n";
                // Tambahkan kode daftar buah di sini
                break;
            case 3:
                cout << "Fitur Cari buah\n";
                // Tambahkan kode cari buah di sini
                break;
            case 4:
                cout << "Fitur Hapus buah\n";
                // Tambahkan kode hapus buah di sini
                break;
            case 0:
                cout << "Keluar dari program.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        cout << endl;
    } while(pilihan != 0);

    return 0;
}