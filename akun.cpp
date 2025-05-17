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
    clearScreen();
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