#include "cari_data.hpp"
#include "Utilitas.hpp"
#include "Data_Apartment.hpp"
#include <algorithm>
#include <cctype>

using namespace std;

// Helper untuk pencarian string mirip (case-insensitive, ignore space)
bool isSimilar(const string& a, const string& b) {
    string sa, sb;
    for(char c : a) if(!isspace(c)) sa += tolower(c);
    for(char c : b) if(!isspace(c)) sb += tolower(c);
    return sa.find(sb) != string::npos;
}

void cariDataApartemen(){
    clearScreen();
    int menu;
    cout << "\nCari Data berdasarkan :\n";
    cout << "1. ID\n";
    cout << "2. Tipe\n";
    cout << "3. Harga\n";
    cout << "4. Range Harga\n";
    cout << "5. Ketersediaan\n";
    cout << "Pilih : "; cin >> menu;

    switch (menu)
    {
    case 1:
        cariIDapartemen();
        break;
    case 2:
        cariTipeApartemen();
        break;
    case 3:
        cariHargaApartemen();//tetap
        break;
    case 4:
        cariRangeHargaApartemen();//tetap
        break;
    case 5:
        cariKetersediaanApartemen();//tetap
        break;
    default:
        break;
    }
}

void cariIDapartemen(){
    string cariIDstr;
    cout << "Masukkan ID Apartemen yang dicari: ";
    cin >> cariIDstr;
    bool found = false;
    for(int i=1; i<301; i++){
        if(data_unit[i].ID == 0) continue;
        string idStr = to_string(data_unit[i].ID);
        if(isSimilar(idStr, cariIDstr)){
            cout << "Data ditemukan:\n";
            cout << "ID: " << data_unit[i].ID << endl;
            cout << "Nama: " << data_unit[i].nama << endl;
            cout << "Tipe: " << data_unit[i].tipe << endl;
            cout << "Lokasi: " << data_unit[i].lokasi << endl;
            cout << "Fasilitas: " << data_unit[i].fasilitas << endl;
            cout << "Harga/Bulan: Rp." << data_unit[i].hargaPerBulan << endl;
            cout << "Status: " << (data_unit[i].statusTersedia ? "Tersedia" : "Tidak Tersedia") << endl;
            found = true;
        }
    }
    if(!found) cout << "Data tidak ditemukan!\n";
}

void cariTipeApartemen(){
    string tipe;
    cout << "Masukkan tipe apartemen yang dicari: ";
    cin.ignore();
    getline(cin, tipe);
    bool found = false;
    for(int i=1; i<301; i++){
        if(data_unit[i].ID != 0 && isSimilar(data_unit[i].tipe, tipe)){
            cout << "ID: " << data_unit[i].ID << ", Nama: " << data_unit[i].nama << ", Harga: Rp." << data_unit[i].hargaPerBulan << endl;
            found = true;
        }
    }
    if(!found) cout << "Tidak ada apartemen dengan tipe tersebut.\n";
}

void cariHargaApartemen(){
    int harga;
    cout << "Masukkan harga maksimum: ";
    cin >> harga;
    if(cin.fail()){
        cin.clear(); cin.ignore(1000,'\n');
        cout << "Input tidak valid!\n";
        return;
    }
    bool found = false;
    for(int i=1; i<301; i++){
        if(data_unit[i].ID != 0 && data_unit[i].hargaPerBulan <= harga){
            cout << "ID: " << data_unit[i].ID << ", Nama: " << data_unit[i].nama << ", Harga: Rp." << data_unit[i].hargaPerBulan << endl;
            found = true;
        }
    }
    if(!found) cout << "Tidak ada apartemen di bawah harga tersebut.\n";
}

void cariRangeHargaApartemen(){
    int minHarga, maxHarga;
    cout << "Masukkan harga minimum: ";
    cin >> minHarga;
    cout << "Masukkan harga maksimum: ";
    cin >> maxHarga;
    if(cin.fail()){
        cin.clear(); cin.ignore(1000,'\n');
        cout << "Input tidak valid!\n";
        return;
    }
    bool found = false;
    for(int i=1; i<301; i++){
        if(data_unit[i].ID != 0 && data_unit[i].hargaPerBulan >= minHarga && data_unit[i].hargaPerBulan <= maxHarga){
            cout << "ID: " << data_unit[i].ID << ", Nama: " << data_unit[i].nama << ", Harga: Rp." << data_unit[i].hargaPerBulan << endl;
            found = true;
        }
    }
    if(!found) cout << "Tidak ada apartemen dalam range harga tersebut.\n";
}

void cariKetersediaanApartemen(){
    cout << "Daftar Apartemen Tersedia:\n";
    bool found = false;
    for(int i=1; i<301; i++){
        if(data_unit[i].ID != 0 && data_unit[i].statusTersedia){
            cout << "ID: " << data_unit[i].ID << ", Nama: " << data_unit[i].nama << ", Harga: Rp." << data_unit[i].hargaPerBulan << endl;
            found = true;
        }
    }
    if(!found) cout << "Tidak ada apartemen yang tersedia saat ini.\n";
}

void urutKecilBesar(unit data_unit[],int jmldata){
    for(int i=1; i<jmldata; i++){
        for(int j=i+1; j<=jmldata; j++){
            if(data_unit[i].hargaPerBulan > data_unit[j].hargaPerBulan){
                swap(data_unit[i], data_unit[j]);
            }
        }
    }
}

void urutBesarKecil(unit data_unit[], int jmldata){
    for(int i=1; i<jmldata; i++){
        for(int j=i+1; j<=jmldata; j++){
            if(data_unit[i].hargaPerBulan < data_unit[j].hargaPerBulan){
                swap(data_unit[i], data_unit[j]);
            }
        }
    }
}