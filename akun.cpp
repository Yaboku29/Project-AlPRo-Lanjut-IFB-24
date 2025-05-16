#include "akun.hpp"
using namespace std;
int akun=0;
void bacaJumlahAkun(int *jumlah){

}
void adminMenu(){
    clearScreen();
}
void signInPenyewa(){
    clearScreen();
}
void sign_up(){
    clearScreen();
    ofstream DatabaseAkunPenyewa("dataAkunPenyewa.txt",ios::app);
    if(!DatabaseAkunPenyewa.is_open()){
        cout<<"Database Tidak DITEMUKAN.\n";
        return;
    }
    //Hitung=========
    // int jumlahBaris=0;
    // char karakterNewline;
    // while(DatabaseAkunPenyewa.get(karakterNewline)){

    // }
    
}
void Penyewa_Menu(){
    clearScreen();
}