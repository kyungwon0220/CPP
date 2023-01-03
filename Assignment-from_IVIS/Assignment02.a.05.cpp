// 삼각형 패턴을 표시하는 프로그램을 C++로 작성하세요.
// 각 행에는 홀수의 숫자가 포함됩니다.
// 각 행의 처음과 마지막 번호는 1이 되고 가운데 열은 행 번호가 됩니다.

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