#include <iostream>
#include <string>
using namespace std;

//Struct untuk unit apartemen
struct unit {
    
};

//struct untuk banyak akun penyewa
struct akun_penyewa{
    int ID;
    string username;
    string password;
    string email;
}; 
akun_penyewa penyewa[1001];
int akun=0;

//Data Akun 
void loginMenu();
void signUpMenu();
void adminMenu();
void penyewaMenu();
void signInPenyewa(); 
//Data Apartemen
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

//Menu Awal
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

//Membuat Akun Penyewa
void signUpMenu() {
    system("cls");
    akun++;
    cout << "=== MENU SIGN UP ===" << endl;
    for(int i=akun;i<=akun;i++){
        penyewa[i].ID=i;
        cout<<"Masukkan email: ";
        cin>>penyewa[i].email;
        cout<<"Masukkan Username: ";
        cin>>penyewa[i].username;
        cout<<"Masukkan password: ";
        cin>>penyewa[i].password;
    }
    cout << "Akun telah selesai dibuat." << endl;
    cout << "Masuk ke sign-in..." << endl;
    getchar();
    signInPenyewa();
}
//Login Penyewa
void signInPenyewa() {
    int pilihan;
    char yes_or_no;
    string username_penyewa;
    string password_penyewa;
    bool check_username=false;
    bool check_password=false;
    system("cls");

    cout << "=== LOGIN PENYEWA ===" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout<<"Masukkan Username: ";
            cin>>username_penyewa;
            cout<<"Masukkan Password: ";
            cin>>password_penyewa;
            
            for(int i=1;i<=akun;i++){
                if(username_penyewa==penyewa[i].username){//check username
                    check_username=true;
                }
                if(password_penyewa==penyewa[i].password){
                    check_password=true;
                }
            }
            if (check_username==true&&check_password==true){
                cout<<"Login berhasil"<<endl;
                cout<<"Tekan enter untuk melanjutkan...";
                cin.ignore();
                getchar();
                penyewaMenu();
            }
            else{
                cout<<"Username atau Password ada yang salah"<<endl;
                cout<<"Apakah Anda benar-benar sudah punya akun? (y/n): ";
                cin>>yes_or_no;
                if(yes_or_no=='y'||yes_or_no=='Y') signInPenyewa();
                else if(yes_or_no=='N'||yes_or_no=='n'){
                    cout<<"Tolong buat akun terlebih dahulu."<<endl;
                    cin.ignore();
                    cout<<"Tekan enter untuk melanjutkan...";
                    getchar();
                    signUpMenu();
                }
                else {
                    cout<<"Input tidak ada yang sesuai."<<endl;
                    cout<<"Maka akan dilempar ke menu awal."<<endl;
                    loginMenu();
                }
            }
                 
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
