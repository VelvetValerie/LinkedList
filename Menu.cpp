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

//Fungsi untuk menampilkan daftar buah
//Jika daftar buah kosong, maka tampil pesan "Belum ada buah"
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

//Fungsi untuk mencari buah berdasarkan nama
//Jika buah ada pada daftar, tampilkan nama dan jumlahnya
//Jika tidak ada, maka pesan "Buah tidak ditemukan" akan tampil.
void cariBuah(Buah* head) {
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
}

// Fungsi untuk menghapus buah berdasarkan nama
// Jika buah ditemukan, hapus buah tersebut dan tampilkan pesan berhasil
// Jika tidak ditemukan, tampilkan pesan "Buah tidak ditemukan"
void hapusBuah(Buah*& head) {
    if (head == nullptr) {
        cout << "Belum ada buah.\n";
        return;
    }
    cin.ignore();
    string hapusNama;
    cout << "Masukkan nama buah yang ingin dihapus: ";
    getline(cin, hapusNama);

    Buah* temp = head;
    Buah* prev = nullptr;
    while (temp != nullptr) {
        if (temp->nama == hapusNama) {
            if (prev == nullptr) {
                // Hapus head
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            cout << "Buah berhasil dihapus.\n";
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Buah tidak ditemukan.\n";
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

    while (head != nullptr) {
        Buah* hapus = head;
        head = head->next;
        delete hapus;
    }
    return 0;
}