#include "akun.hpp"
#include "Utilitas.hpp"
using namespace std;
void menu();

int main(){
    menu();
}

void menu(){
    clearScreen();
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
            cin.ignore();
            system("pause");
            menu();
            break;
        case 2:
            signInPenyewa();
            cin.ignore();
            system("pause");
            menu();
            break;
        case 3:
            cout << "Terima kasih telah menggunakan sistem ini." << endl;
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            cin.ignore();
            system("pause");
            menu();
    }
}