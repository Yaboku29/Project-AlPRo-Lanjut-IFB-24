#ifndef DATA_APARTEMEN_HPP
#define DATA_APARTEMEN_HPP
#include <iostream>
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

void tampilkanSemuaDataApartemen();
void tampilkanDataApartemen(); 
void sewaUnit(); 
void hitungTotalPendapatan();
void kelolaDataApartemen();
void tambahDataApartemen(); 
void hapusDataApartemen(); 
void ubahStatusApartemen();

void cariDataApartemen();
void cariIDapartemen();
void cariTipeApartemen();
void cariHargaApartemen();
void cariRangeHargaApartemen();
void cariKetersediaanApartemen();
void urutKecilBesar(unit data_unit[],int jmldata);
void urutBesarKecil(unit data_unit[], int jmldata);


#endif