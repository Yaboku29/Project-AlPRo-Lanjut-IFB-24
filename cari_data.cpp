#include "cari_data.hpp"
#include "Utilitas.hpp"
using namespace std;
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