// 배열에서 원소를 검색하는 search() 함수를 템플릿으로 작성하라.
// search()의 첫 번째 매개 변수는 검색하고자 하는 원소 값이고, 두 번째 매개 변수는 배열이며, 세 번째 매개 변수는 배열의 개수이다.
// search() 함수가 검색에 성공하면 true를, 아니면 false를 리턴한다.
// search()의 호출 사례는 다음과 같다.

#include <iostream>

using namespace std;

template <typename T>
bool search(T index, T* x, unsigned short size) {
    for(unsigned short i=0; i<size; i++) {
        if(x[i] == index) return true;
    }

    return false;
}

int main() {
    int x[] = {1, 10, 100, 5, 4};
    if(search(100, x,5)) cout << "100이 배열 x에 포함되어 있다"; // 이 cout 실행
    else cout << "100이 배열 x에 포함되어 있지 않다";
}