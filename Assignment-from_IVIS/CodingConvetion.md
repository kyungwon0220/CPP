- main.cpp ( main 구문이 있는 파일
> 큰 프로젝트에서는 main 구문이 있는 쪽을 일일이 찾아야 함을 방지


- .h, .cpp 파일의 명칭을 똑같이 저장
> 파일을 일일이 찾아야 함을 방지


- 헤더에 using namespace std; 금.
> namespace 취지가, 다른 함수들의 충돌을 막기 위해 만들어진 원래 의미가 퇴색됨
> 가급적 using namespace 지양


- 헤더에는 최소한의 include 포함
> 헤더에서 헤더를 차봊하지 않기 위해, '전방선언' 이용하기도 함


- 헤더 파일 중복 방지를 위해 #ifndef, #define, #endif 선언 필요


- 최종 push시에는, 개발시의 주석 삭제 ( README.md 제작 가능


- make시, 빌드시 존재하는 모든 warning 제거 後 push

- delete tP;
  tP = nullptr;
> new 키워드로 포인터에 메모리를 동적 할당 받을시 heep 영역에 생성될건데, 할당을 제거하려면 delete 구문이 필요. 메모리 할당을 해제하려면 주소가 필요하여 先 delete


- 예외 처리


- 임계값 체킹


- class Test {
  public:
      Test() {}
      Test(int x) : m_x(x) {} // Test(int x) {this->m_x = x) {}
      virtual ~Test() = default; // virtual ~Test() {}
> 가상 소멸자 작성
      void testX(int y); // void testX(int &y);
> int 초과부터는 call by reference
> bool, int 자료형은 reference의 이점이 없어서 ' & ' 참조를 일부러 붙이지는 않는다 ( call by reference 시, 어차피 int의 주소가 불림. 즉, 32비트 시스템의 주소  4byte == int 값의 크기와 같아지기 때문
  private:
      ..
  }
> 멤버 변수와 argument 변수명이 겹치지 않길 선호
> 멤버 변수에는 'm' 이나 'm_' prefix 붙임
> 생성자 함수 내부보다, 초기화 리스트 선호


- const 값이나, define 정해진 값만 대문자로 쓰는 것을 기본 정책으로 합니다


- ERR Log


- int main() { return 0; }
> return 중간에 없는 것을 지향 ( return 많아지면 가독성이 떨어지기 때문.


- for (int ex = 0; ex > 0; --ex) {
      ..
  }


- if ((ex1 != false) && (ex2 == true)) {
      ..
  } else if (ex3) {
      ..
  }


- 
