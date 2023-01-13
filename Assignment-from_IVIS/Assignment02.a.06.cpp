// 지정된 지름의 콘솔에 원을 그리는 프로그램을 만듭니다.
// 다음을 수행할 수 있습니다.
// 원하는 ASCII 문자를 사용하십시오.
// 지름 단위 정의
// 채워지거나 비어 있는 원 그리기
// 출력 예(정확히 다음과 같을 필요는 없음):

#include <iostream>

using namespace std;

int main() {
    int x = 10;

    for(int i=-x; i<=x; i++) {
        for(int j=-x; j<=x; j++) {
            if(i*i + j*j <= x*x) cout << "**";
            else cout << "  ";
        }
        cout << endl;
    }
}