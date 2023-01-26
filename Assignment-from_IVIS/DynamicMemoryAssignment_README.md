// 문자열 클래스를 구현합니다. std::string과 같은 방식으로 이 클래스를 사용할 수 있어야 합니다. 클래스는 다음 기능을 제공해야 합니다(이에 국한되지 않음).
// ASCII로 작업(유니코드 지원이 필요하지 않음)
// 값 길이를 얻습니다.
// 값 가져오기/설정;
// 지정된 위치에 새 값 삽입;
// 명확한 문자열;
// 개별 캐릭터를 얻으십시오.
// 화면에 값 표시;
// std::cout을 사용하여 값 인쇄;
// 역 문자열;
// 문자열 추가(함수 사용 및 + 연산자 사용)
// 하위 문자열을 다른 값으로 교체합니다.
// 지정된 위치에서 하위 문자열을 가져옵니다.
// 할당, 복사, 이동, 비교 작업이 지원되어야 합니다.
// 구현 요구 사항:
// std::string API를 참조로 사용할 수 있습니다(하지만 자유롭게 디자인할 수 있습니다).
// 2가지 버전을 제출해야 합니다.
// 일반 포인터 사용;
// 스마트 포인터를 사용합니다.
// main.cpp는 모든 기능에 대한 간단한 단위 테스트를 포함해야 합니다.




다양한 인자를 받아, 편하게 사용하기 위해 추가로 구현해 보았습니다.
- void MyString::insert(const unsigned short index, const char c);

- void append(const char *str, const unsigned short index, const unsigned short count);

- void assign(const unsigned short count, const char c);

- void assign(const char* str, const unsigned short index, const unsigned short count);

- void assign(const MyString& str, const unsigned short index, const unsigned short count);

-

// 전체 미완성. 
