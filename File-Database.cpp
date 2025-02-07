#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Fungsi untuk menambahkan data ke file
void tambahData() {
    ofstream file("database.txt", ios::app);
    if (!file) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    int id, umur;
    string nama;

    cout << "Masukkan ID: ";
    cin >> id;
    cin.ignore(); // Menghindari error input string setelah integer
    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan Umur: ";
    cin >> umur;

    file << id << "," << nama << "," << umur << endl;
    file.close();

    cout << "Data berhasil ditambahkan!" << endl;
}

// Fungsi untuk menampilkan semua data dalam file
void tampilkanData() {
    ifstream file("database.txt");
    if (!file) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    string line;
    cout << "=== Data dalam Database ===" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

// Fungsi untuk mencari data berdasarkan ID
void cariData() {
    ifstream file("database.txt");
    if (!file) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    int cariID;
    cout << "Masukkan ID yang dicari: ";
    cin >> cariID;

    string line;
    bool ditemukan = false;
    while (getline(file, line)) {
        if (line.find(to_string(cariID) + ",") == 0) { // ID ada di awal baris
            cout << "Data ditemukan: " << line << endl;
            ditemukan = true;
            break;
        }
    }
    file.close();

    if (!ditemukan) {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk memperbarui data berdasarkan ID
void updateData() {
    ifstream file("database.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    int updateID, umur;
    string nama;
    bool ditemukan = false;

    cout << "Masukkan ID yang akan diperbarui: ";
    cin >> updateID;
    cin.ignore();
    cout << "Masukkan Nama baru: ";
    getline(cin, nama);
    cout << "Masukkan Umur baru: ";
    cin >> umur;

    string line;
    while (getline(file, line)) {
        if (line.find(to_string(updateID) + ",") == 0) {
            tempFile << updateID << "," << nama << "," << umur << endl;
            ditemukan = true;
        } else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    remove("database.txt");
    rename("temp.txt", "database.txt");

    if (ditemukan) {
        cout << "Data berhasil diperbarui!" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Fungsi untuk menghapus data berdasarkan ID
void hapusData() {
    ifstream file("database.txt");
    ofstream tempFile("temp.txt");

    if (!file || !tempFile) {
        cout << "Gagal membuka file!" << endl;
        return;
    }

    int hapusID;
    cout << "Masukkan ID yang akan dihapus: ";
    cin >> hapusID;

    string line;
    bool ditemukan = false;

    while (getline(file, line)) {
        if (line.find(to_string(hapusID) + ",") == 0) {
            ditemukan = true;
        } else {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    remove("database.txt");
    rename("temp.txt", "database.txt");

    if (ditemukan) {
        cout << "Data berhasil dihapus!" << endl;
    } else {
        cout << "Data tidak ditemukan!" << endl;
    }
}

// Menu utama
int main() {
    int pilihan;
    do {
        cout << "\n=== Database Sederhana ===" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Tampilkan Data" << endl;
        cout << "3. Cari Data" << endl;
        cout << "4. Update Data" << endl;
        cout << "5. Hapus Data" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahData(); break;
            case 2: tampilkanData(); break;
            case 3: cariData(); break;
            case 4: updateData(); break;
            case 5: hapusData(); break;
            case 0: cout << "Keluar dari program..." << endl; break;
            default: cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 0);

    return 0;
}
    