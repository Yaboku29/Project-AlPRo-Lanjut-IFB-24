#include <iostream>
#include <string>
using namespace std;

void loginMenu();
void signUpMenu();
void adminMenu();
void penyewaMenu();
void signInPenyewa(); 
void tampilkanDataApartemen(); 
void sewaUnit(); 
void hitungTotalPendapatan(); 
void kelolaDataApartemen(); 
void tambahDataApartemen(); 
void hapusDataApartemen(); 
void ubahStatusApartemen();
int main() {
    loginMenu();
    return 0;
}

void loginMenu() {
    system("cls");
    int pilihan;
    cout << "=== SISTEM MANAJEMEN APARTEMEN ===" << endl;
    cout << "1. Login sebagai Admin" << endl;
    cout << "2. Login sebagai Penyewa" << endl;
    cout << "3. Keluar" << endl;
    
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            adminMenu();
            break;
        case 2:
            signInPenyewa();
            break;
        case 3:
            cout << "Terima kasih telah menggunakan sistem ini." << endl;
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            loginMenu();
    }
}

void signUpMenu() {
    system("cls");

    cout << "=== MENU SIGN UP ===" << endl;
    cout << "Fitur sign up belum diimplementasikan." << endl;
    cout << "Kembali ke menu login..." << endl;
    loginMenu();
}

void signInPenyewa() {
    int pilihan;
    system("cls");

    cout << "=== LOGIN PENYEWA ===" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout << "Fitur sign in penyewa belum diimplementasikan." << endl;
            penyewaMenu(); 
            break;
        case 2:
            signUpMenu();
            break;
        case 3:
            loginMenu(); 
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            signInPenyewa();
    }
}

void adminMenu() {
    int pilihan;
    system("cls");

    cout << "=== MENU ADMIN ===" << endl;
    cout << "1. Kelola Data Apartemen (Tambah/Hapus/Edit Status)" << endl;
    cout << "2. Tampilkan Data Apartemen" << endl;
    cout << "3. Cek Total Pendapatan Bulanan" << endl;
    cout << "4. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            kelolaDataApartemen(); // Pindah ke menu kelola data apartemen
            break;
        case 2:
            tampilkanDataApartemen(); // Contoh pemanggilan fungsi
            break;
        case 3:
            int bulan;
            cout << "Masukkan bulan (1-12): ";
            cin >> bulan;
            hitungTotalPendapatan();
            break;
        case 4:
            loginMenu();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            adminMenu();
    }
}

void penyewaMenu() {
    int pilihan;
    system("cls");

    cout << "=== MENU PENYEWA ===" << endl;
    cout << "1. Tampilkan Data Apartemen" << endl;
    cout << "2. Sewa Unit Apartemen" << endl;
    cout << "3. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            tampilkanDataApartemen(); 
            break;
        case 2:
            sewaUnit();
            break;
        case 3:
            loginMenu();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            penyewaMenu();
    }
}

void kelolaDataApartemen() {
    int pilihan;
    system("cls");

    cout << "=== KELOLA DATA APARTEMEN ===" << endl;
    cout << "1. Tambah Data Apartemen" << endl;
    cout << "2. Hapus Data Apartemen" << endl;
    cout << "3. Ubah Status Apartemen (Disewa/Tidak Disewa)" << endl;
    cout << "4. Kembali ke Menu Admin" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            tambahDataApartemen(); 
            break;
        case 2:
            hapusDataApartemen(); 
            break;
        case 3:
            ubahStatusApartemen(); 
            break;
        case 4:
            adminMenu();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            kelolaDataApartemen();
    }
}

void tambahDataApartemen() {
    cout << "Fitur tambah data apartemen belum diimplementasikan." << endl;
    kelolaDataApartemen(); 
}

void hapusDataApartemen() {
    cout << "Fitur hapus data apartemen belum diimplementasikan." << endl;
    kelolaDataApartemen(); 
}

void ubahStatusApartemen() {
    cout << "Fitur ubah status apartemen belum diimplementasikan." << endl;
    kelolaDataApartemen(); 
}

void tampilkanDataApartemen() {
    
}

void sewaUnit() {
    
}

void hitungTotalPendapatan() {
    
}