#include <iostream>

using namespace std;

int main(){
    system("cls");
    int A[5][5],B[5][5],C[5][5];
    //input A
    cout<<"Input Matriks A: "<<endl;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>A[i][j];
        }
    }
    cout<<"Input Matriks B: "<<endl;
    //Input B
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>B[i][j];
        }
    }
    //Penjumlahan
    cout<<"Matriks Penjumlahan"<<endl;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            C[i][j]=A[i][j]+B[i][j];
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    //Pengurangan
    cout<<"Matriks Pengurangan"<<endl;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            C[i][j]=A[i][j]-B[i][j];
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
    //Perkalian
    cout<<"matriks perkalian"<<endl;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            C[i][j]=0;
            for(int k=1;k<=3;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}