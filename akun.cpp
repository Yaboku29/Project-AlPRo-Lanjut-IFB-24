#include "akun.hpp"
#include "cari_data.hpp"
#include "Utilitas.hpp"
using namespace std;

akun_admin admin_data[] = {
    {"Ariz","123240070"},
    {"Lintang","123240065"},
    {"Yasmine","123240064"},
    {"Shafiq","123240085"},
    {"Rayhan","123240054"},
};
int akun=0;

void tambahAkun(const akun_penyewa &akunBaru){
    ofstream DatabaseAkunPenyewa("dataAkunPenyewa.txt",ios::app);
    if(!DatabaseAkunPenyewa.is_open()){
        cout<<"Database Tidak DITEMUKAN.\n";
        return;
    }
    DatabaseAkunPenyewa << akunBaru.ID << ';'
                        << akunBaru.username << ';'
                        << akunBaru.password << ';'
                        << akunBaru.email << '\n';

    DatabaseAkunPenyewa.close();
}

void bacaJumlahAkun(){
    ifstream DatabaseAkunPenyewa("dataAkunPenyewa.txt");
    if(!DatabaseAkunPenyewa.is_open()){
        cout<<"Database Tidak DITEMUKAN.\n";
        akun = 0;
        return;
    }
    string baris;
    int jumlahBaris = 0;
    while(getline(DatabaseAkunPenyewa,baris)){
        if(!baris.empty()) jumlahBaris++;
    }
    DatabaseAkunPenyewa.close();
    akun=jumlahBaris;
}



void adminMenu(){
    string usn, pass;
    bool found = false;
    system("cls");
    cout << BOLD << YELLOW <<"<======= Silahkan login dahulu =======>\n\n";
    cout << "Username: ";
    cin >> usn;
    cout << "Password: ";
    cin >> pass;

    for(int i=0; i<5; i++){
        if(usn == admin_data[i].username && pass == admin_data[i].password){
            cout << BOLD << GREEN << "Login berhasil! Selamat datang, " << usn << RESET << endl;
            system("pause");
            found = true;
            break;
        }
    }

    if(!found){
        cout << RED << "Username atau Password salah!" << RESET << endl;
        system("pause");
        return;
    }
    int pilihan;
    do{
        clearScreen();
        cout << BOLD << BLUE << "=== MENU ADMIN ===" << RESET << endl;
        cout << "1. Kelola Data Apartemen (Tambah/Hapus/Edit Status)" << endl;
        cout << "2. Tampilkan Data Apartemen" << endl;
        cout << "3. Cek Total Pendapatan Bulanan" << endl;
        cout << "4. Logout" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        if(cin.fail()){
            cin.clear(); cin.ignore(1000,'\n');
            cout << RED << "Input tidak valid!" << RESET << endl;
            system("pause");
            continue;
        }
        switch (pilihan) {
            case 1:
                kelolaDataApartemen();
                break;
            case 2:
                tampilkanDataApartemen();
                system("pause");
                break;
            case 3:
                hitungTotalPendapatan();
                break;
            case 4:
                cout << "Logout...\n";
                system("pause");
                return;
                break;
            default:
                cout << RED << "Pilihan tidak valid. Silakan coba lagi." << RESET << endl;
                system("pause");
                break;
        }
    } while (pilihan != 4);
}

void signInPenyewa(){
    clearScreen();
    int pilih;
    cout << "=== LOGIN PENYEWA ===" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilih;
    if(cin.fail()){
        cin.clear(); cin.ignore(1000,'\n');
        cout << RED << "Input tidak valid!" << RESET << endl;
        system("pause");
        return;
    }
    switch (pilih)
    {
    case 1:{
        clearScreen();
        string usn_signIn, pass_signIn;
        cout << "===== Sign In =====\n\n";
        cout << "Username: ";
        cin.ignore();
        getline(cin, usn_signIn);
        cout << "Password: ";
        getline(cin, pass_signIn);
        ifstream fileAkun("dataAkunPenyewa.txt");
        if (!fileAkun.is_open()) {
            cout << "Tidak bisa membuka file\n";
            system("pause");
            return;
        }
        akun_penyewa akunLogin;
        string line;
        bool ditemukan = false;
        while (getline(fileAkun, line)) {
            if (line.empty()) continue;
            stringstream ss(line);
            string ID_str;
            getline(ss, ID_str, ';');
            getline(ss, akunLogin.username, ';');
            getline(ss, akunLogin.password, ';');
            getline(ss, akunLogin.email, ';');
            if (strcasecmp(akunLogin.username.c_str(), usn_signIn.c_str()) == 0 && akunLogin.password == pass_signIn) {
                akunLogin.ID = stoi(ID_str);
                ditemukan = true;
                break;
            }
        }
        fileAkun.close();
        if (ditemukan) {
            cout << BOLD << GREEN << "Login berhasil! Selamat datang, " << akunLogin.username << RESET << endl;
            system("pause");
            Penyewa_Menu(akunLogin.ID);
        } else {
            cout << RED << "Username atau Password salah!" << RESET << endl;
            system("pause");
        }
        break;}
    case 2:
        sign_up();
        break;
    default:
        break;
    }
}

void sign_up(){
    clearScreen();
    akun_penyewa akunBaru;
    bacaJumlahAkun();
    cout<<BLUE<<"Masukkan Email: ";
    cin>>akunBaru.email;
    cin.ignore();
    cout<<BLUE<<"Masukkan Username: ";
    getline(cin, akunBaru.username);
    cout<<BLUE<<"Masukkan Password: ";
    getline(cin, akunBaru.password);
    akunBaru.ID=akun+1;
    tambahAkun(akunBaru);
    cout<<BOLD<<GREEN<<"SELAMAT AKUN ANDA SUDAH TERDAFTAR"<<RESET<<endl;
    cout<<"Silakan sign-in dengan akun anda"<<endl;
    system("pause");
    signInPenyewa();
}

void Penyewa_Menu(int ID){
    akun_penyewa penyewaAkun;
    ifstream fileAkun("dataAkunPenyewa.txt");
    string line;
    bool ditemukan = false;
    while(getline(fileAkun, line)){
        if(line.empty()) continue;
        stringstream ss(line);
        string ID_str;
        getline(ss, ID_str, ';');
        getline(ss, penyewaAkun.username, ';');
        getline(ss, penyewaAkun.password, ';');
        getline(ss, penyewaAkun.email, ';');
        if(stoi(ID_str) == ID){
            penyewaAkun.ID = ID;
            ditemukan = true;
            break;
        }
    }
    fileAkun.close();
    if(!ditemukan){
        cout << "Data penyewa tidak ditemukan!\n";
        system("pause");
        return;
    }
    int pilihan;
    do {
        clearScreen();
        cout << "=== MENU PENYEWA ===" << endl;
        cout << "1. Sewa Unit Apartemen" << endl;
        cout << "2. Cari Data Apartemen" << endl;
        cout << "3. Logout" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        if(cin.fail()){
            cin.clear(); cin.ignore(1000,'\n');
            cout << RED << "Input tidak valid!" << RESET << endl;
            system("pause");
            continue;
        }
        switch(pilihan){
            case 1:
                sewaUnit(penyewaAkun, penyewaAkun.ID);
                break;
            case 2:
                cariDataApartemen();
                system("pause");
                break;
            case 3:
                cout << "Logout...\n";
                system("pause");
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                system("pause");
        }
    } while(pilihan != 3);
}

#ifdef _WIN32
#include <cstring>
int strcasecmp(const char* s1, const char* s2) {
    return _stricmp(s1, s2);
}
#endif