#ifndef AKUN_HPP
#define AKUN_HPP
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct akun_penyewa{
    int ID;
    string username;
    string password;
    string email;
};
void tambahAkun(const akun_penyewa &akunBaru);
void bacaJumlahAkun();
void adminMenu();
void signInPenyewa();
void sign_up();
void Penyewa_Menu(int ID);

#endif