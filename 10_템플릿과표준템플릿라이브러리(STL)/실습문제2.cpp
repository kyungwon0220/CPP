// 두 개의 배열을 비교하여 같으면 true를, 아니면 false를 리턴하는 제네릭 함수 equalArrays()를 작성하라.
// 또한 main() 함수를 작성하여 equalArrays()를 호출 하는 몇 가지 사례를 보여라.
// equalArrays()를 호출하는 코드 사례는 다음과 같다.

#include <iostream>

using namespace std;

template <typename T>
bool equalArrays(T* x, T* y, unsigned short size) {
    for(unsigned short i=0; i<size; i++) {
        if(x[i] != y[i]) return false;
    }
    
    return true;
}

int main() {
    int x[] = {1, 10, 100, 5, 4};
    int y[] = {1, 10, 100, 5, 4};
    if(equalArrays(x, y, 5)) cout << "같다"; // 배열 x, y가 같으므로 "같다" 출력
    else cout << "다르다";
}