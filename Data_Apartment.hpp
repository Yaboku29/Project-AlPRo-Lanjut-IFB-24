#ifndef DATA_APARTEMEN_HPP
#define DATA_APARTEMEN_HPP
#include <iostream>
#include "Utilitas.hpp"
#include "json.hpp"
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>

struct unit {
    int ID;
    string nama;
    string tipe;
    string lokasi;
    string fasilitas;
    int hargaPerBulan;
    bool statusTersedia=true;
};

void tampilkanSemuaDataApartemen();
void tampilkanDataApartemen(); 
void sewaUnit(); 
void hitungTotalPendapatan();
void kelolaDataApartemen();
void tambahDataApartemen(); 
void hapusDataApartemen(); 
void ubahStatusApartemen();


#endif