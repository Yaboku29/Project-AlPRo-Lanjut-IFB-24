#include "akun.hpp"
#include "Utilitas.hpp"
using namespace std;
int akun=0;

void tambahAkun(const akun_penyewa &akunBaru){
    ofstream DatabaseAkunPenyewa("dataAkunPenyewa.txt",ios::app);
    if(!DatabaseAkunPenyewa.is_open()){
        cout<<"Database Tidak DITEMUKAN.\n";
        return;
    }
}

void bacaJumlahAkun(){
    ifstream DatabaseAkunPenyewa("dataAkunPenyewa.txt");
    if(!DatabaseAkunPenyewa.is_open()){
        cout<<"Database Tidak DITEMUKAN.\n";
        return;
    }
    string baris;
    int jumlahBaris;
    while(getline(DatabaseAkunPenyewa,baris)){
        if(!baris.empty()) jumlahBaris++;
    }
    DatabaseAkunPenyewa.close();
    akun=jumlahBaris;
}



void adminMenu(){
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
void signInPenyewa(){
    clearScreen();
}
void sign_up(){
    clearScreen();
    akun_penyewa akunBaru;
    //Hitung=========
    bacaJumlahAkun();
    cout<<BLUE<<"Masukkan Email: ";
    cin>>akunBaru.email;
    cin.ignore();
    cout<<BLUE<<"Masukkan Username: ";
    cin>>akunBaru.username;
    cin.ignore();
    cout<<BLUE<<"Masukkan Password: ";
    cin>>akunBaru.password;
    akunBaru.ID=akun+1;
    tambahAkun(akunBaru);
    cout<<BOLD<<GREEN<<"SELAMAT AKUN ANDA SUDAH TERDAFTAR"<<RESET<<endl;
    cout<<"Silakan sign-in dengan akun anda"<<endl;
    cin.ignore();
    system("pause");
    signInPenyewa();
}
void Penyewa_Menu(){
    clearScreen();
}