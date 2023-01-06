// 다음 프로그램은 컴파일 오류가 발생한다.
// 소스의 어디에서 왜 컴파일 오류가 발생하는가?
// 아래 결과와 같이 출력되도록 프로그램을 수정하라.


#include <iostream>

using namespace std;

class Circle {
    int radius;

    public:
    Circle(int radius = 1) {this->radius = radius;}
    int getRadius() {return radius;}
};

Circle bigger(Circle& c1, Circle& c2) { if(c1.getRadius() > c2.getRadius()) return c1; else return c2;}


template <class T>
T bigger(T a, T b) { // 두개의 매개 변수를 비교하여 큰 값을 리턴
if(a > b) return a;
else return b;
}


int main() {
    int a=20, b=50, c;
    c = bigger(a, b);
    cout << "20과 50중 큰 값은 " << c << endl;
    Circle waffle(10), pizza(20), y;
    y = bigger(waffle, pizza);
    cout << "waffle과 pizza 중 큰 것의 반지름은 " << y.getRadius() << endl;
}