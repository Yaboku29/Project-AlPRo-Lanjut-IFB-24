#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// KUMPULAN STRUCT MASUKIN SINI
//Struct untuk unit apartemen
struct unit {
    string ID;
    string nama;
    string tipe;
    string lokasi;
    string fasilitas;
    int hargaPerBulan;
    bool statusTersedia=true;
};

//struct untuk banyak akun penyewa
struct akun_penyewa{
    int ID;
    string username;
    string password;
    string email;
}; 

// KUMPULAN DATA (UNIT, AKUN, ADMIN, ETC) MASUKIN SINI
// data unit
unit data_unit[301]={

    {"1", "Apartemen A", "Studio", "Jakarta", "AC, TV, Kulkas, Kamar Mandi", 1000000, true},
    {"2", "Apartemen B", "Studio", "Jakarta", "Kolam Renang, Gym", 5000000, true},
    {"3", "Apartemen C", "2BR", "Bandung", "Gym, Tempat Yoga", 7000000, false},
    {"4", "Apartemen D", "1BR", "Surabaya", "Bioskop Pribadi", 6000000, true},
    {"5", "Apartemen E", "3BR", "Jakarta", "Kolam Renang", 9000000, false},
    {"6", "Apartemen F", "2BR", "Sleman", "Jasa Antar MBG, Akun Kaskus Premium", 1000000, false},
    {"7", "Apartemen G", "Studio", "Surabaya", "-", 2000000, true},
    {"8", "Apartemen H", "3BR", "Sleman", "-", 1500000, true},
    {"9", "Apartemen I", "Loft", "Surabaya", "WiFi 6G (illegal), Jasa Antar Makanan", 2000000, true},
    
    }; 
int jumlahUnit = 9;


// data akun penyewa
akun_penyewa penyewa[1001];  
int akun=0;


bool cariUnit(int index,string& pilihID_unit);
//Data Akun 
void loginMenu();
void signUpMenu();
void adminMenu();
void penyewaMenu();
void signInPenyewa(); 
//Data Apartemen
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

int main() {
    // loginMenu();
    // return 0;
    tampilkanDataApartemen();
}

//Menu Awal
void loginMenu() {
    system("cls");
    int pilihan;
    cout << "=== SISTEM MANAJEMEN APARTEMEN ===" << endl;
    cout << "1. Login sebagai Admin" << endl;
    cout << "2. Login sebagai Penyewa" << endl;
    cout << "3. Keluar" << endl;
    
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            adminMenu();
            break;
        case 2:
            signInPenyewa();
            break;
        case 3:
            cout << "Terima kasih telah menggunakan sistem ini." << endl;
            exit(0);
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            loginMenu();
    }
}

//Membuat Akun Penyewa
void signUpMenu() {
    system("cls");
    akun++;
    cout << "=== MENU SIGN UP ===" << endl;
    for(int i=akun;i<=akun;i++){
        penyewa[i].ID=i;
        cout<<"Masukkan email: ";
        cin>>penyewa[i].email;
        cout<<"Masukkan Username: ";
        cin>>penyewa[i].username;
        cout<<"Masukkan password: ";
        cin>>penyewa[i].password;
    }
    cout << "Akun telah selesai dibuat." << endl;
    cout << "Masuk ke sign-in..." << endl;
    getchar();
    signInPenyewa();
}
//Login Penyewa
void signInPenyewa() {
    int pilihan;
    char yes_or_no;
    string username_penyewa;
    string password_penyewa;
    bool check_username=false;
    bool check_password=false;
    system("cls");

    cout << "=== LOGIN PENYEWA ===" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            cout<<"Masukkan Username: ";
            cin>>username_penyewa;
            cout<<"Masukkan Password: ";
            cin>>password_penyewa;
            
            for(int i=1;i<=akun;i++){
                if(username_penyewa==penyewa[i].username){//check username
                    check_username=true;
                }
                if(password_penyewa==penyewa[i].password){
                    check_password=true;
                }
            }
            if (check_username==true&&check_password==true){
                cout<<"Login berhasil"<<endl;
                cout<<"Tekan enter untuk melanjutkan...";
                cin.ignore();
                getchar();
                penyewaMenu();
            }
            else{
                cout<<"Username atau Password ada yang salah"<<endl;
                cout<<"Apakah Anda benar-benar sudah punya akun? (y/n): ";
                cin>>yes_or_no;
                if(yes_or_no=='y'||yes_or_no=='Y') signInPenyewa();
                else if(yes_or_no=='N'||yes_or_no=='n'){
                    cout<<"Tolong buat akun terlebih dahulu."<<endl;
                    cin.ignore();
                    cout<<"Tekan enter untuk melanjutkan...";
                    getchar();
                    signUpMenu();
                }
                else {
                    cout<<"Input tidak ada yang sesuai."<<endl;
                    cout<<"Maka akan dilempar ke menu awal."<<endl;
                    loginMenu();
                }
            }
                 
            break;
        case 2:
            signUpMenu();
            break;
        case 3:
            loginMenu(); 
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            signInPenyewa();
    }
}

void adminMenu() {
    int pilihan;
    system("cls");

    cout << "=== MENU ADMIN ===" << endl;
    cout << "1. Kelola Data Apartemen (Tambah/Hapus/Edit Status)" << endl;
    cout << "2. Tampilkan Data Apartemen" << endl;
    cout << "3. Cek Total Pendapatan Bulanan" << endl;
    cout << "4. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            kelolaDataApartemen(); // Pindah ke menu kelola data apartemen
            break;
        case 2:
            tampilkanDataApartemen(); // Contoh pemanggilan fungsi
            break;
        case 3:
            int bulan;
            cout << "Masukkan bulan (1-12): ";
            cin >> bulan;
            hitungTotalPendapatan();
            break;
        case 4:
            loginMenu();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            adminMenu();
    }
}

void penyewaMenu() {
    int pilihan;
    system("cls");

    cout << "=== MENU PENYEWA ===" << endl;
    cout << "1. Tampilkan Data Apartemen" << endl;
    cout << "2. Sewa Unit Apartemen" << endl;
    cout << "3. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            tampilkanDataApartemen(); 
            break;
        case 2:
            sewaUnit();
            break;
        case 3:
            loginMenu();
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            penyewaMenu();
    }
}

void kelolaDataApartemen() {
    int pilihan;
    system("cls");

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
            kelolaDataApartemen();
    }
}

void tambahDataApartemen() {
    cout << "Fitur tambah data apartemen belum diimplementasikan." << endl;
    kelolaDataApartemen(); 
}

void hapusDataApartemen() {
    cout << "Fitur hapus data apartemen belum diimplementasikan." << endl;
    kelolaDataApartemen(); 
}

void ubahStatusApartemen() {
    cout << "Fitur ubah status apartemen belum diimplementasikan." << endl;
    kelolaDataApartemen(); 
}

void tampilkanDataApartemen() {
    tampilkanSemuaDataApartemen();

    int menu;
    cout << "\n1. Cari Data\n";
    cout << "2. Urutkan Harga (rendah ke tinggi)\n";
    cout << "3. Urutkan Harga (tinggi ke rendah)\n";
    cout << "Pilih : "; cin >> menu;

    switch (menu)
    {
    case 1:
        cariDataApartemen();
        break;
    case 2:
        urutKecilBesar(data_unit,jumlahUnit);
        break;
    case 3:
        urutBesarKecil(data_unit,jumlahUnit);
        break;
    default:
        break;
    }
}

void sewaUnit() {
    system("cls");
    data_unit[1].ID="1";
    string pilihID_unit;
    tampilkanSemuaDataApartemen();

    cout << "Pilih ID unit yang ingin disewa: ";
    cin >> pilihID_unit;
    system("cls");

    if(cariUnit(1, pilihID_unit) == false) {
        
        cout << "Unit dengan ID: " << pilihID_unit << " tidak tersedia.\nSilahkan pilih yang lain.\n";
        system("pause");
        sewaUnit(); 
    }
}

void hitungTotalPendapatan() {
    
}

void tampilkanSemuaDataApartemen(){
    int IDlength = 6, namaLength = 21, tipeLength = 10, hargaLength = 20, tersediaLength = 13;
    int totalLength = IDlength + namaLength + tipeLength + hargaLength + tersediaLength + 13;

    cout << setfill('=') << setw(totalLength) << "" << endl;
    cout << setfill(' ') << left << "|| " << setw(IDlength) << "ID" << "| " << setw(namaLength) << "nama" << "| " << setw(tipeLength) << "tipe"  << "| " << setw(hargaLength) << "harga/bulan"  << "| " << setw(tersediaLength) << "tersedia"  << "||" << endl;
    cout << setfill('-') << setw(totalLength) << "" << endl;;
    for (int i=0; i < jumlahUnit; i++) {
        cout << setfill(' ') << left << "|| " << setw(IDlength) << data_unit[i].ID << "| " << setw(namaLength) << data_unit[i].nama << "| " << setw(tipeLength) << data_unit[i].tipe  << "| " << setw(hargaLength) << data_unit[i].hargaPerBulan  << "| " << setw(tersediaLength) << data_unit[i].statusTersedia  << "||" << endl;
    }
    cout << setfill('=') << setw(totalLength) << "" << endl;
}

void cariDataApartemen(){

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
        cariHargaApartemen();
        break;
    case 4:
        cariRangeHargaApartemen();
        break;
    case 5:
        cariKetersediaanApartemen();
        break;
    default:
        break;
    }


}

void cariIDapartemen(){
    string cari;
    cout << "Masukkan ID Apartemen yang ingin dicari : "; cin >> cari;

    //asumsi ID urut

    int bwh = 0, atas = jumlahUnit;
    bool ketemu = false;

    while (bwh <= atas)
    {
        int tgh = (bwh + atas) / 2;
        if (data_unit[tgh].ID == cari)
        {
            cout << "\nNama : " << data_unit[tgh].nama << endl;
            cout << "Tipe : " << data_unit[tgh].tipe << endl;
            cout << "Lokasi : " << data_unit[tgh].lokasi << endl;
            cout << "Fasilitas : " << data_unit[tgh].fasilitas << endl;
            cout << "Harga : " << data_unit[tgh].hargaPerBulan << " / bulan\n";
            cout << "Ketersediaan : " << data_unit[tgh].statusTersedia << endl;
            ketemu = true;
            break;
        } 
        else if (data_unit[tgh].ID > cari)
        {
            atas = tgh - 1;
        }
        else if (data_unit[tgh].ID < cari)
        {
            bwh = tgh + 1;
        }
    }

    if (ketemu == false)
    {
        cout << "\nData apartemen dengan ID " << cari << " tidak ditemukan.";
    }
}

void cariTipeApartemen(){
    string cari;
    cout << "Masukkan tipe apartemen : "; cin.ignore(); getline(cin,cari);

    bool ketemu = false;

    for (int i = 0; i < jumlahUnit; i++)
    {
        if (data_unit[i].tipe == cari)
        {
            cout << "\nID : " << data_unit[i].ID << endl;
            cout << "Nama : " << data_unit[i].nama << endl;
            cout << "Lokasi : " << data_unit[i].lokasi << endl;
            cout << "Fasilitas : " << data_unit[i].fasilitas << endl;
            cout << "Harga : " << data_unit[i].hargaPerBulan << " / bulan\n";
            cout << "Ketersediaan : " << data_unit[i].statusTersedia << endl;
            ketemu = true;
        }
    }

    if (ketemu == false)
    {
        cout << "\nTipe apartemen " << cari << " tidak ditemukan.";
    }
    
    
}

void cariHargaApartemen(){
    int cari;
    cout << "Masukkan harga apartemen : "; cin >> cari;

    bool ketemu = false;

    for (int i = 0; i < jumlahUnit; i++)
    {
        if (data_unit[i].hargaPerBulan == cari)
        {
            cout << "\nID : " << data_unit[i].ID << endl;
            cout << "Nama : " << data_unit[i].nama << endl;
            cout << "Tipe : " << data_unit[i].tipe << endl;
            cout << "Lokasi : " << data_unit[i].lokasi << endl;
            cout << "Fasilitas : " << data_unit[i].fasilitas << endl;
            cout << "Ketersediaan : " << data_unit[i].statusTersedia << endl;
            ketemu = true;
        }
    }

    if (ketemu == false)
    {
        cout << "\nApartemen dengan harga " << cari << " tidak ditemukan.";
    }
    
}

void cariRangeHargaApartemen(){
    int caribwh, cariatas;
    cout << "Masukkan batas bawah harga apartemen : "; cin >> caribwh;
    cout << "Masukkan batas atas harga apartemen  : "; cin >> cariatas;

    if (caribwh <= cariatas){

    bool ketemu = false;

    for (int i = 0; i < jumlahUnit; i++)
    {
        if (data_unit[i].hargaPerBulan >= caribwh && data_unit[i].hargaPerBulan <= cariatas)
        {
            cout << "\nID : " << data_unit[i].ID << endl;
            cout << "Nama : " << data_unit[i].nama << endl;
            cout << "Tipe : " << data_unit[i].tipe << endl;
            cout << "Lokasi : " << data_unit[i].lokasi << endl;
            cout << "Fasilitas : " << data_unit[i].fasilitas << endl;
            cout << "Harga : " << data_unit[i].hargaPerBulan << " / bulan\n";
            cout << "Ketersediaan : " << data_unit[i].statusTersedia << endl;
            ketemu = true;
        }
    }

    if (ketemu == false)
    {
        cout << "\nApartemen dengan range harga " << caribwh << " - " << cariatas << " tidak ditemukan.";
    }

    } else { 
    cout << "\nRange harga invalid.";
    }
}

void cariKetersediaanApartemen(){
    int cari;

    cout << "1. Cari apartemen yang diisi\n";
    cout << "0. Cari apartemen yang kosong\n";
    cout << "Pilih : "; cin >> cari;

    bool ketemu;

    if (cari == 1 || cari == 0) {
        for (int i = 0; i < jumlahUnit; i++)
    {
        if (data_unit[i].statusTersedia == cari) 
        {
            cout << "\nID : " << data_unit[i].ID << endl;
            cout << "Nama : " << data_unit[i].nama << endl;
            cout << "Tipe : " << data_unit[i].tipe << endl;
            cout << "Lokasi : " << data_unit[i].lokasi << endl;
            cout << "Fasilitas : " << data_unit[i].fasilitas << endl;
            cout << "Harga : " << data_unit[i].hargaPerBulan << " / bulan\n";
            cout << "Ketersediaan : " << data_unit[i].statusTersedia << endl;
            ketemu = true;
        }
    }
    } 
    else {
        cout << "\nPilihan Invalid\n";
    }
}

void urutKecilBesar(unit data_unit[], int jmldata){
    for (int i = 0; i < jmldata; i++)
    {
        for (int j = i + 1; j < jmldata; j++)
        {
            if (data_unit[j].hargaPerBulan < data_unit[i].hargaPerBulan)
            {
               int temp = data_unit[i].hargaPerBulan;
               data_unit[i].hargaPerBulan = data_unit[j].hargaPerBulan;
               data_unit[j].hargaPerBulan = temp;
            }   
        }
    }
    
    tampilkanSemuaDataApartemen(); 
}

void urutBesarKecil(unit data_unit[], int jmldata){
    for (int i = 0; i < jmldata; i++)
    {
        for (int j = i + 1; j < jmldata; j++)
        {
            if (data_unit[j].hargaPerBulan > data_unit[i].hargaPerBulan)
            {
               int temp = data_unit[i].hargaPerBulan;
               data_unit[i].hargaPerBulan = data_unit[j].hargaPerBulan;
               data_unit[j].hargaPerBulan = temp;
            }   
        }
    }
    
    tampilkanSemuaDataApartemen();
}

bool cariUnit(int index, string& pilihID_unit) {
    if (index > jumlahUnit) {
        return false;
    }
    if (data_unit[index].ID == pilihID_unit) {
        if (data_unit[index].statusTersedia) {
            data_unit[index].statusTersedia = false;
            cout << "Unit " << pilihID_unit << endl;
            cout << left << setw(17) << "Nama" << ": " << data_unit[index].nama << endl;
            cout << left << setw(17) << "Tipe" << ": " << data_unit[index].tipe << endl;
            cout << left << setw(17) << "Fasilitas" << ": " << data_unit[index].fasilitas << endl;
            cout << left << setw(17) << "Lokasi" << ": " << data_unit[index].lokasi << endl;
            cout << left << setw(17) << "Harga Perbulan" << ": " << data_unit[index].nama << endl;
            cout << left << setw(17) << "Tersedia" << ": " << data_unit[index].statusTersedia << endl;


        } else {
            cout << "Unit " << pilihID_unit << " sudah disewa." << endl;
        }
        return true;
    }
    return cariUnit(index + 1, pilihID_unit);
}