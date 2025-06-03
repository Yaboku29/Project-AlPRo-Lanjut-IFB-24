#ifndef DATA_APARTEMEN_HPP
#define DATA_APARTEMEN_HPP
#include <iostream>
#include <string>
#include "json.hpp"
#include <fstream>
#include "akun.hpp"
using namespace std;
struct unit {
    int ID;
    string nama;
    string tipe;
    string lokasi;
    string fasilitas;
    int hargaPerBulan;
    bool statusTersedia=true;
};

void muatDataUnitDariFile(const string& namaFile);
//void tampilkanSemuaDataApartemen();
void tampilkanDataApartemen(); 
void sewaUnit(const akun_penyewa &penyewa,int ID); 
void hitungTotalPendapatan();
void kelolaDataApartemen();
void tambahDataApartemen(); 
void hapusDataApartemen(); 
void ubahStatusApartemen();
void simpanDataUnit();
bool cariUnit(int &index, int pilihID_unit);
void simpanPenyewaan(int idUnit, int idPenyewa, int bulanMasuk, int bulanKeluar, int totalHarga);

extern unit data_unit[301];
#endif