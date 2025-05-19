#include "akun.hpp"
#include "Data_Apartment.hpp"
#include "Utilitas.hpp"

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
        return;
    }
    string baris;
    int jumlahBaris;
    while(getline(DatabaseAkunPenyewa,baris)){
        if(!baris.empty()) jumlahBaris++;
    }
    DatabaseAkunPenyewa.close();
    akun=jumlahBaris;
}



void adminMenu(){
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
            
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            adminMenu();
    }
}
void signInPenyewa(){
    clearScreen();
    ifstream fileAkun("dataAkunPenyewa.txt");
    string usn_signIn, pass_signIn;
    int pilih;
    akun_penyewa akunLogin;
    string line;
    bool ditemukan = false;
    cout << "=== LOGIN PENYEWA ===" << endl;
    cout << "1. Sign In" << endl;
    cout << "2. Sign Up" << endl;
    cout << "3. Kembali ke Menu Login" << endl;
    cout << "Pilihan: ";
    cin >> pilih;
   

    switch (pilih)
    {
    case 1:
        
         clearScreen();
            cout << "===== Sign In =====\n\n";
            cout << "Username: ";
            cin.ignore();
            getline(cin, usn_signIn);
            cout << "Password: ";
            getline(cin, pass_signIn);

            if (!fileAkun.is_open()) {
                cout << "Tidak bisa membuka file\n";
                system("pause");
                return;
            }

            while (getline(fileAkun, line)) {
                if (line.empty()) continue;

                stringstream ss(line);
                string ID_str;
                getline(ss, ID_str, ';');
                getline(ss, akunLogin.username, ';');
                getline(ss, akunLogin.password, ';');
                getline(ss, akunLogin.email, ';');

                if (akunLogin.username == usn_signIn && akunLogin.password == pass_signIn) {
                    akunLogin.ID = stoi(ID_str);
                    ditemukan = true;
                    break;
                }
            }

            fileAkun.close();

            if (ditemukan) {
                cout << BOLD << GREEN << "Login berhasil! Selamat datang, " << akunLogin.username << RESET << endl;
                system("pause");
                Penyewa_Menu(); // Pindah ke menu penyewa
            } else {
                cout << RED << "Username atau Password salah!" << RESET << endl;
                system("pause");
                signInPenyewa(); // Kembali login
            }

        break;
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
    //Hitung=========
    bacaJumlahAkun();
    cout<<BLUE<<"Masukkan Email: ";
    cin>>akunBaru.email;
    cin.ignore();
    cout<<BLUE<<"Masukkan Username: ";
    cin>>akunBaru.username;
    cin.ignore();
    cout<<BLUE<<"Masukkan Password: ";
    cin>>akunBaru.password;
    akunBaru.ID=akun+1;
    tambahAkun(akunBaru);
    cout<<BOLD<<GREEN<<"SELAMAT AKUN ANDA SUDAH TERDAFTAR"<<RESET<<endl;
    cout<<"Silakan sign-in dengan akun anda"<<endl;
    cin.ignore();
    system("pause");
    signInPenyewa();
}
void Penyewa_Menu(){
    clearScreen();
}