// 배열의 원소를 반대 순서로 뒤집는 reverseArray() 함수를 템플릿으로 작성하라.
// reverseArray()의 첫 번째 매개 변수는 배열에 대한 포인터이며 두 번째 매개 변수는 배열의 개수이다.
// reverseArray()의 호출 사례는 다음과 같다.

template <typename T>
void reverseArray(T *x, unsigned short size) {
    for(unsigned short i=0; i<size/2; i++) {
        T tmp = x[i];
        x[i] = x[size-i-1];
        x[size-i-1] = tmp;
    }
}

#include <iostream>

using namespace std;

int main() {
    int x[] = {1, 10, 100, 5, 4};
    reverseArray(x, 5);
    for(int i=0; i<5; i++) cout << x[i] << ' '; // 45 100 10 1이 출력된다.
}