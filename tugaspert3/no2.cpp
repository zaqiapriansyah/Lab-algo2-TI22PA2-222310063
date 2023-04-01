#include <iostream>
#include <algorithm>
using namespace std;

const int A = 100;
string buku[A];

int binarySearch (string x, int l, int r){
    if (r >= 1) {
        int mid = 1 + (r - 1)/2;
        if (buku[mid] == x)
            return mid;
        if (buku[mid] > x)
            return binarySearch (x,l,mid - 1);
        return binarySearch (x,mid + 1, r);
    }
    return -1;
}

int main(){
    int n;

    cout <<"Masukkan jumlah banyak buku : ";
    cin >> n;


    for (int i=0 ; i<n ; i++){
        cout <<"Masukkan nama buku "<< i+1 <<" : ";
        cin >> buku[i];
    }
    sort (buku, buku + n);

    string z;
    cout <<"Masukkan nama buku yang ingin dicari :";
    cin >> z;

    int result = binarySearch (z, 0 ,n -1);
    if (result == -1 )
    cout <<"Nama yang dimasukkan tidak dapat ditemukan." <<endl;
    else
    cout <<"Buku ditemukan pada nomor "<<result<<endl;

    return 0;
}