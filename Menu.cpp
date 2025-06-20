#include <iostream>
#include <string>
using namespace std;

//Struktur node barang
struct Barang {
    string nama;
    int jumlah;
    Barang* next;
};

//Fungsi untuk menambahkan barang
void tambahBarang(Barang*& head) {
    Barang* baru = new Barang();
    cout << "Masukkan nama buah: ";
    cin.ignore();
    getline(cin, baru->nama);
    cout << "Masukkan jumlah: ";
    cin >> baru->jumlah;
    baru->next = nullptr;

     if (head == nullptr) {
        head = baru;
    } else {
        Barang* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Buah berhasil ditambahkan!\n";
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
                cout << "Fitur Tambah Barang\n";
                // Tambahkan kode tambah barang di sini
                break;
            case 2:
                cout << "Fitur Daftar Barang\n";
                // Tambahkan kode daftar barang di sini
                break;
            case 3:
                cout << "Fitur Cari Barang\n";
                // Tambahkan kode cari barang di sini
                break;
            case 4:
                cout << "Fitur Hapus Barang\n";
                // Tambahkan kode hapus barang di sini
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