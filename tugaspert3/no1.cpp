#include <iostream>
#include <algorithm>
using namespace std;

const int M = 100;
int number[M];

int binarySearch (int x, int l, int r){
    if (r >= 1) {
        int mid = 1 + (r - 1)/2;
        if (number[mid] == x)
            return mid;
        if (number[mid] > x)
            return binarySearch (x,l,mid - 1);
        return binarySearch (x,mid + 1, r);
    }
    return -1;
}

int main(){
    int n;

    cout <<"Input how many data you want to input to an array : ";
    cin >> n;


    for (int i=0 ; i<n ; i++){
        cout <<"Input data number "<< i+1 <<" : ";
        cin >> number[i];
    }
    sort (number, number + n);

    int z;
    cout <<"Input the data you want to find :";
    cin >> z;

    int result = binarySearch (z, 0 ,n -1);
    if (result == -1 )
    cout <<"Data can't be found." <<endl;
    else
    cout <<"data is found at index number "<<result<<endl;

    return 0;
}