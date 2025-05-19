#include "Data_Apartment.hpp"
#include "akun.hpp"
#include "Utilitas.hpp"
#include <fstream>
using namespace std;


unit data_unit[301]={

    {1, "Apartemen A", "Studio", "Jakarta", "AC, TV, Kulkas, Kamar Mandi", 1000000, true},
    {2, "Apartemen B", "Studio", "Jakarta", "Kolam Renang, Gym", 5000000, true},
    {3, "Apartemen C", "2BR", "Bandung", "Gym, Tempat Yoga", 7000000, false},
    {4, "Apartemen D", "1BR", "Surabaya", "Bioskop Pribadi", 6000000, true},
    {5, "Apartemen E", "3BR", "Jakarta", "Kolam Renang", 9000000, false},
    {6, "Apartemen F", "2BR", "Sleman", "Jasa Antar MBG, Akun Kaskus Premium", 1000000, false},
    {7, "Apartemen G", "Studio", "Surabaya", "-", 2000000, true},
    {8, "Apartemen H", "3BR", "Sleman", "-", 1500000, true},
    {9, "Apartemen I", "Loft", "Surabaya", "WiFi 6G (illegal), Jasa Antar Makanan", 2000000, true},
    
    }; 
int jumlahUnit = 9;

void tampilkanSemuaDataApartemen(){
    clearScreen();
}

void tampilkanDataApartemen(){
    clearScreen();
}
void sewaUnit(akun_penyewa penyewa){
    clearScreen();
    data_unit[1].ID=1;
    int pilihID_unit;
    char JadiSewa;
    int indexUnit=1;
    tampilkanSemuaDataApartemen();

    cout << "Pilih ID unit yang ingin disewa: ";
    cin >> pilihID_unit;
    system("cls");

    if(cariUnit(indexUnit, pilihID_unit) == false) {
        
        cout << "Unit dengan ID: " << pilihID_unit << " tidak tersedia.\nSilahkan pilih yang lain.\n";
        system("pause");
        sewaUnit(); 
    } else {
            cin.ignore();
            cout << "Unit " <<setfill(' ')<< pilihID_unit << endl;
            cout << left << setw(17) << "Nama" << ": " << data_unit[indexUnit].nama << endl;
            cout << left << setw(17) << "Tipe" << ": " << data_unit[indexUnit].tipe << endl;
            cout << left << setw(17) << "Fasilitas" << ": " << data_unit[indexUnit].fasilitas << endl;
            cout << left << setw(17) << "Lokasi" << ": " << data_unit[indexUnit].lokasi << endl;
            cout << left << setw(17) << "Harga Perbulan" << ": Rp." << data_unit[indexUnit].hargaPerBulan << endl;
            cout << left << setw(17) << "Tersedia" << ": " << (data_unit[indexUnit].statusTersedia) << endl;
            do
            {
                cout << "Apakah Anda yakin ingin menyewa unit ini? (y/n): ";
                cin >> JadiSewa;
                if (!(JadiSewa =='y' || JadiSewa =='n')) {
                    cout << "Masukkan input yang benar! (y/n)" << endl;
                    system("pause");
                }
            } while (!(JadiSewa =='y' || JadiSewa =='n'));
            
            if (JadiSewa=='y'){
                // BELOM BIKIN VARIABEL BULAN MASUK & KELUAR
                cout << "Masukkan Bulan masuk: " << endl;
                cout << "Masukkan Bulan keluar: " << endl;

                data_unit[indexUnit].statusTersedia=false;
                cout << "Unit " << pilihID_unit << " berhasil disewa." << endl;
                cout << "Nama Penyewa\t: " << penyewa.username << endl;
                cout << "ID Penyewa\t: " << penyewa.ID << endl;
                cout << "Total Harga\t: Rp." << data_unit[indexUnit].hargaPerBulan /* dikali jumlah bulan */<< endl;
                cout << "Silahkan melakukan pembayaran ke admin." << endl;
                system("pause");
                Penyewa_Menu();
            } else {
                sewaUnit();
            }
            
    }
    
} 
void hitungTotalPendapatan(){
    clearScreen();
}
void kelolaDataApartemen(){
    clearScreen();
}
void tambahDataApartemen(){
    clearScreen();
} 
void hapusDataApartemen(){
    clearScreen();
} 
void ubahStatusApartemen(){
    clearScreen();
}

bool cariUnit(int &index, int pilihID_unit) {
    if (index > jumlahUnit) {
        return false;
    }
    if (data_unit[index].ID == pilihID_unit) {
        if (data_unit[index].statusTersedia) {
            cout << "Unit " << pilihID_unit << " tersedia." << endl;
            


        } else {
            cout << "Unit " << pilihID_unit << " sudah disewa." << endl;
        }
        return true;
    }
    index++;
    return cariUnit(index, pilihID_unit);
}
//===================================