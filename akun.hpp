#ifndef AKUN_HPP
#define AKUN_HPP
#include <iostream>
#include <fstream>

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
void Penyewa_Menu();

#endif