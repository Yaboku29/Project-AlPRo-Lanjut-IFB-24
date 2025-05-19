#include "Data_Apartment.hpp"
#include "Utilitas.hpp"
#include <fstream>


unit data_unit[301]={
    {},
    };
int jumlahUnit = 9;

void muatDataUnitDariFile(const string& namaFile) {
    ifstream file(namaFile);
    if (!file.is_open()) {
        cout << "Gagal membuka file: " << namaFile << endl;
        return;
    }

    string baris;
    int index = 1;

    while (getline(file, baris) && index < 301) {
        stringstream ss(baris);
        string token;

        getline(ss, token, ';');
        data_unit[index].ID = stoi(token);

        getline(ss, data_unit[index].nama, ';');
        getline(ss, data_unit[index].tipe, ';');
        getline(ss, data_unit[index].lokasi, ';');
        getline(ss, data_unit[index].fasilitas, ';');

        getline(ss, token, ';');
        data_unit[index].hargaPerBulan = stoi(token);

        getline(ss, token, ';');
        data_unit[index].statusTersedia = (token == "1");

        index++;
    }

    file.close();
}


void tampilkanDataApartemen(){
    clearScreen();
    cout << left
         << setw(5)  << "ID"
         << setw(15) << "Nama"
         << setw(10) << "Tipe"
         << setw(12) << "Lokasi"
         << setw(35) << "Fasilitas"
         << setw(15) << "Harga/Bulan"
         << setw(10) << "Status"
         << endl;

    cout << setfill('-') << setw(112) << "-" << setfill(' ') << endl;

    for (int i = 1; i < 301; i++) {
        if (data_unit[i].ID == 0) continue; // Lewati index kosong

        cout << left
             << setw(5)  << data_unit[i].ID
             << setw(15) << data_unit[i].nama
             << setw(10) << data_unit[i].tipe
             << setw(12) << data_unit[i].lokasi
             << setw(35) << data_unit[i].fasilitas
             << "Rp." << setw(11) << data_unit[i].hargaPerBulan
             << (data_unit[i].statusTersedia ? "Tersedia" : "Tidak")
             << endl;
    }

}
void sewaUnit(const akun_penyewa &penyewa,int ID){
    clearScreen();
    
    data_unit[1].ID=1;
    int pilihID_unit;
    char JadiSewa;
    int indexUnit=1;
    int bulanMasuk,bulanKeluar,jmlBulan;

    tampilkanDataApartemen();

    cout << "Pilih ID unit yang ingin disewa: ";
    cin >> pilihID_unit;
    system("cls");

    if(cariUnit(indexUnit, pilihID_unit) == false) {
        
        cout << "Unit dengan ID: " << pilihID_unit << " tidak tersedia.\nSilahkan pilih yang lain.\n";
        system("pause");
        sewaUnit(penyewa,ID); 
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
                
                cout << "Masukkan Bulan masuk (contoh: 12): " << endl;
                cin >> bulanMasuk;
                cout << "Masukkan Bulan keluar (contoh: 12): " << endl;
                cin >> bulanKeluar;

                if (bulanMasuk < 1 || bulanMasuk > 12 || bulanKeluar < 1 || bulanKeluar > 12) {
                cout << "Input bulan tidak valid!" << endl;
                    
                } else{

                    if (bulanKeluar>bulanMasuk){
                        jmlBulan = bulanKeluar - bulanMasuk;
                    } else {
                        jmlBulan = (bulanKeluar + 12) - bulanMasuk;
                    }
                }



                data_unit[indexUnit].statusTersedia=false;
                cout << "Unit " << pilihID_unit << " berhasil disewa." << endl;
                cout << "Nama Penyewa\t: " << penyewa.username << endl;
                cout << "ID Penyewa\t: " << penyewa.ID << endl;
                cout << "Total Harga\t: Rp." << data_unit[indexUnit].hargaPerBulan*jmlBulan<< endl;
                cout << "Silahkan melakukan pembayaran ke admin." << endl;
                system("pause");
                Penyewa_Menu(ID);
            } else {
                sewaUnit(penyewa,ID);
            }
            
    }
    
} 
void hitungTotalPendapatan(){
    clearScreen();
}
void kelolaDataApartemen(){
    clearScreen();
    int pilihan;
    do
    {
        cout << "=== KELOLA DATA APARTEMEN ===" << endl;
        cout << "1. Tambah Data Apartemen" << endl;
        cout << "2. Hapus Data Apartemen" << endl;
        cout << "3. Ubah Status Apartemen (Disewa/Tidak Disewa)" << endl;
        cout << "4. Kembali ke Menu Admin" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahDataApartemen(); 
                break;
            case 2:
                hapusDataApartemen(); 
                break;
            case 3:
                ubahStatusApartemen(); 
                break;
            case 4:
                adminMenu();
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan!=4);
    
}
void tambahDataApartemen(){
    clearScreen();

    simpanDataUnit();
} 
void hapusDataApartemen(){
    clearScreen();
} 
void ubahStatusApartemen(){
    clearScreen();
}

void simpanDataUnit() {
    int lastId=0;
    string baris;
    fstream fileUnit("Data_Unit.txt",ios::in | ios::out | ios::app);

    if (fileUnit.is_open()) {

        while (getline(fileUnit, baris)) {
                size_t pos = baris.find(';'); // cari posisi titik koma pertama
                if (pos != string::npos) {
                    int nomor = stoi(baris.substr(0, pos)); // ambil nomor unit (ID)
                    lastId = nomor; // simpan nomor terakhir
                }

        for(int i=lastId; i<=100; i++) {
            if (data_unit[i].ID!=0){
                fileUnit << data_unit[i].ID << ";" << data_unit[i].nama << ";" 
                << data_unit[i].tipe << ";" << data_unit[i].lokasi <<";"
                << data_unit[i].fasilitas<< ";"<< data_unit[i].hargaPerBulan<< ";" 
                << data_unit[i].statusTersedia<<";"<< endl; 
            } else {
                break;
                }
            }
        
        }
    fileUnit.close();
    }
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