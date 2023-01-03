// 배열을 받아 가장 큰 값을 리턴하는 제네릭 함수 biggest()를 작성하라.
// 또한 main() 함수를 작성하여 biggest()를 호출하는 몇 가지 사례를 보여라.
// biggest()를 호출하는 코드 사레는 다음과 같다.
// int x[] = {1, 10, 100, 5, 4}; cout << biggest(x,5) << endl; // 5는 배열 x의 크기. 100이 출력된다.


template <typename T>
T biggest(T* x, unsigned short size) {

    if(size < 0) return 0; // size error

    T big = x[0];

    for(unsigned short i=0; i<size; i++)
        if(big < x[i]) big = x[i];
    
    return big;
}

#include <iostream>

int main() {
    int x[] = {1, 10, 100, 5, 4};
    std::cout << biggest(x,5) << std::endl; // 5는 배열 x의 크기. 100이 출력된다.

    double y[] = {6.4, 3.3, -200.6, 7.7, 8.8, 20.3};
	std::cout << biggest(y, 6); // 6�� �迭 y�� ũ��
}