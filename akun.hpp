#ifndef AKUN_HPP
#define AKUN_HPP
#include "Data_Apartment.hpp"

struct akun_penyewa{
    int ID;
    string username;
    string password;
    string email;
};
void bacaJumlahAkun();
void adminMenu();
void signInPenyewa();
void sign_up();
void Penyewa_Menu();

#endif