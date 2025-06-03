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
    // Lebar kolom yang lebih besar
    const int wID = 6, wNama = 25, wTipe = 15, wLokasi = 20, wFasilitas = 45, wHarga = 18, wStatus = 15;
    cout << left
         << "|" << setw(wID) << "ID"
         << "|" << setw(wNama) << "Nama"
         << "|" << setw(wTipe) << "Tipe"
         << "|" << setw(wLokasi) << "Lokasi"
         << "|" << setw(wFasilitas) << "Fasilitas"
         << "|" << setw(wHarga) << "Harga/Bulan"
         << "|" << setw(wStatus) << "Status" << "|" << endl;
    cout << setfill('-') << setw(wID+1) << "-"
         << setw(wNama+1) << "-"
         << setw(wTipe+1) << "-"
         << setw(wLokasi+1) << "-"
         << setw(wFasilitas+1) << "-"
         << setw(wHarga+1) << "-"
         << setw(wStatus+1) << "-" << setfill(' ') << endl;
    for (int i = 1; i < 301; i++) {
        if (data_unit[i].ID == 0) continue;
        cout << left
             << "|" << setw(wID) << data_unit[i].ID
             << "|" << setw(wNama) << data_unit[i].nama
             << "|" << setw(wTipe) << data_unit[i].tipe
             << "|" << setw(wLokasi) << data_unit[i].lokasi
             << "|" << setw(wFasilitas) << data_unit[i].fasilitas
             << "|Rp." << setw(wHarga-3) << data_unit[i].hargaPerBulan
             << "|" << setw(wStatus) << (data_unit[i].statusTersedia ? "Tersedia" : "Tidak Tersedia") << "|" << endl;
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
            cout << left << setw(17) << "Tersedia" << ": " << (data_unit[indexUnit].statusTersedia ? "Tersedia" : "Tidak Tersedia") << endl;
            do {
                cout << "Apakah Anda yakin ingin menyewa unit ini? (y/n): ";
                cin >> JadiSewa;
                if (!(JadiSewa =='y' || JadiSewa =='n')) {
                    cout << "Masukkan input yang benar! (y/n)" << endl;
                    system("pause");
                }
            } while (!(JadiSewa =='y' || JadiSewa =='n'));
            
            if (JadiSewa=='y'){
                
                cout << "Masukkan Bulan masuk (1-12): ";
                cin >> bulanMasuk;
                cout << "Masukkan Bulan keluar (1-12): ";
                cin >> bulanKeluar;

                if (bulanMasuk < 1 || bulanMasuk > 12 || bulanKeluar < 1 || bulanKeluar > 12) {
                cout << "Input bulan tidak valid!" << endl;
                    
                } else{

                    if (bulanKeluar>=bulanMasuk){
                        jmlBulan = bulanKeluar - bulanMasuk + 1;
                    } else {
                        jmlBulan = (bulanKeluar + 12) - bulanMasuk + 1;
                    }
                    data_unit[indexUnit].statusTersedia=false;
                    int totalHarga = data_unit[indexUnit].hargaPerBulan * jmlBulan;
                    cout << "Unit " << pilihID_unit << " berhasil disewa." << endl;
                    cout << "Nama Penyewa\t: " << penyewa.username << endl;
                    cout << "ID Penyewa\t: " << penyewa.ID << endl;
                    cout << "Total Harga\t: Rp." << totalHarga << endl;
                    cout << "Silahkan melakukan pembayaran ke admin." << endl;
                    // Simpan data penyewaan
                    simpanPenyewaan(pilihID_unit, penyewa.ID, bulanMasuk, bulanKeluar, totalHarga);
                    system("pause");
                    Penyewa_Menu(ID);
                }
            } else {
                sewaUnit(penyewa,ID);
            }
            
    }
    
} 
void simpanPenyewaan(int idUnit, int idPenyewa, int bulanMasuk, int bulanKeluar, int totalHarga) {
    ofstream fileSewa("Data_Sewa.txt", ios::app);
    if(fileSewa.is_open()){
        fileSewa << idUnit << ";" << idPenyewa << ";" << bulanMasuk << ";" << bulanKeluar << ";" << totalHarga << endl;
        fileSewa.close();
    }
}

void hitungTotalPendapatan(){
    clearScreen();
    int bulan;
    cout << "Masukkan bulan (1-12): ";
    cin >> bulan;
    ifstream fileSewa("Data_Sewa.txt");
    string baris;
    int total = 0;
    while(getline(fileSewa, baris)){
        if(baris.empty()) continue;
        stringstream ss(baris);
        string idUnit, idPenyewa, bulanMasuk, bulanKeluar, totalHarga;
        getline(ss, idUnit, ';');
        getline(ss, idPenyewa, ';');
        getline(ss, bulanMasuk, ';');
        getline(ss, bulanKeluar, ';');
        getline(ss, totalHarga, ';');
        // Cek apakah bulanMasuk atau bulanKeluar sesuai
        int bMasuk = stoi(bulanMasuk);
        int bKeluar = stoi(bulanKeluar);
        if(bulan >= bMasuk && bulan <= bKeluar){
            total += stoi(totalHarga);
        }
    }
    fileSewa.close();
    cout << "Total pendapatan bulan " << bulan << ": Rp." << total << endl;
    system("pause");
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
                return;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
                break;
        }
    } while (pilihan!=4);
    
}
void tambahDataApartemen(){
    clearScreen();
    unit newUnit;
    // Cari ID terkecil yang kosong (auto increment, reuse slot kosong)
    int autoID = 1;
    for(int i=1; i<301; i++){
        if(data_unit[i].ID == 0){
            autoID = i;
            break;
        }
    }
    newUnit.ID = autoID;
    cout << "=== Tambah Data Apartemen ===" << endl;
    cout << "ID (otomatis): " << newUnit.ID << endl;
    cin.ignore();
    cout << "Nama: ";
    getline(cin, newUnit.nama);
    cout << "Tipe: ";
    getline(cin, newUnit.tipe);
    cout << "Lokasi: ";
    getline(cin, newUnit.lokasi);
    cout << "Fasilitas: ";
    getline(cin, newUnit.fasilitas);
    cout << "Harga per Bulan: ";
    cin >> newUnit.hargaPerBulan;
    newUnit.statusTersedia = true;
    // Simpan ke file (tulis ulang seluruh data agar tidak duplikat)
    data_unit[newUnit.ID] = newUnit;
    ofstream fileUnit("Data_Unit.txt");
    if(fileUnit.is_open()){
        for(int i=1; i<301; i++){
            if(data_unit[i].ID != 0){
                fileUnit << data_unit[i].ID << ";" << data_unit[i].nama << ";" << data_unit[i].tipe << ";" << data_unit[i].lokasi << ";" << data_unit[i].fasilitas << ";" << data_unit[i].hargaPerBulan << ";" << (data_unit[i].statusTersedia?"1":"0") << endl;
            }
        }
        fileUnit.close();
        cout << "Data apartemen berhasil ditambahkan!\n";
    } else {
        cout << "Gagal membuka file Data_Unit.txt\n";
    }
    system("pause");
} 
void hapusDataApartemen(){
    clearScreen();
    tampilkanDataApartemen();
    int hapusID;
    cout << "=== Hapus Data Apartemen ===" << endl;
    cout << "Masukkan ID unit yang ingin dihapus: ";
    cin >> hapusID;
    ifstream fileIn("Data_Unit.txt");
    ofstream fileOut("Data_Unit_temp.txt");
    string baris;
    bool found = false;
    while(getline(fileIn, baris)){
        if(baris.empty()) continue;
        stringstream ss(baris);
        string idStr;
        getline(ss, idStr, ';');
        if(stoi(idStr) == hapusID){
            found = true;
            continue; // skip baris ini
        }
        fileOut << baris << endl;
    }
    fileIn.close();
    fileOut.close();
    remove("Data_Unit.txt");
    rename("Data_Unit_temp.txt", "Data_Unit.txt");
    if(found) cout << "Data apartemen berhasil dihapus!\n";
    else cout << "ID tidak ditemukan!\n";
    system("pause");
} 
void ubahStatusApartemen(){
    clearScreen();
    tampilkanDataApartemen();
    int ubahID;
    cout << "=== Ubah Status Apartemen ===" << endl;
    cout << "Masukkan ID unit yang ingin diubah statusnya: ";
    cin >> ubahID;
    ifstream fileIn("Data_Unit.txt");
    ofstream fileOut("Data_Unit_temp.txt");
    string baris;
    bool found = false;
    while(getline(fileIn, baris)){
        if(baris.empty()) continue;
        stringstream ss(baris);
        string idStr, nama, tipe, lokasi, fasilitas, harga, status;
        getline(ss, idStr, ';');
        getline(ss, nama, ';');
        getline(ss, tipe, ';');
        getline(ss, lokasi, ';');
        getline(ss, fasilitas, ';');
        getline(ss, harga, ';');
        getline(ss, status, ';');
        if(stoi(idStr) == ubahID){
            found = true;
            cout << "Status sekarang: " << (status == "1" ? "Tersedia" : "Tidak Tersedia") << endl;
            cout << "Ubah ke (1=Tersedia, 0=Tidak Tersedia): ";
            string newStatus;
            cin >> newStatus;
            fileOut << idStr << ";" << nama << ";" << tipe << ";" << lokasi << ";" << fasilitas << ";" << harga << ";" << newStatus << endl;
        } else {
            fileOut << baris << endl;
        }
    }
    fileIn.close();
    fileOut.close();
    remove("Data_Unit.txt");
    rename("Data_Unit_temp.txt", "Data_Unit.txt");
    if(found) cout << "Status apartemen berhasil diubah!\n";
    else cout << "ID tidak ditemukan!\n";
    system("pause");
}
bool cariUnit(int &index, int pilihID_unit) {
    // Fungsi rekursif untuk mencari unit berdasarkan ID
    if (index > 300) {
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

void cariDataApartemen();