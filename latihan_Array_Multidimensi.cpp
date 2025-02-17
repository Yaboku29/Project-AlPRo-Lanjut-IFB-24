#include <iostream>

using namespace std;

int main(){
    system("cls");
    int matriks[5][5];
    int dia_prim=0;
    int dia_sen=0;
    cout<<"Masukkan elemen matrisk 3x3: "<<endl;
    //Input Matriks
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>matriks[i][j];
        }
    }
    //Hitung diagonal Primer
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(i==j) dia_prim+=matriks[i][j];
        }
    }
    //Hitung Diagonal Sekunder
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(j==4-i) dia_sen+=matriks[i][j];
        }
    }
    cout<<dia_prim<<endl;
    cout<<dia_sen<<endl;
    cout<<"AKHIR";
  
}