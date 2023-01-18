#include<iostream>

using namespace std;

int main() {
    unsigned short n;

    cout << "Input number of rows: ";
    cin >> n;
    for(unsigned short i=0; i<n; i++) {
        for(unsigned short k=n-i; k>0; k--) cout << " ";
        for(unsigned short j=1; j<=i+1; j++) cout << j;
        for(unsigned short j=i; j>=1; j--) cout << j;
        cout << endl;
    }
}