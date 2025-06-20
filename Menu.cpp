#include <iostream>
#include <string>
using namespace std;

struct Barang {
    string nama;
    int jumlah;
    Barang* next;
};

int main() {
    int pilihan;
    do {
        cout << "=== Menu Inventori ===" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Daftar Barang" << endl;
        cout << "3. Cari Barang" << endl;
        cout << "4. Hapus Barang" << endl;
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