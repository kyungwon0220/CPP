#include <iostream>
class Stack;
class Game;


class StackNode {
public:
    StackNode() : prev(nullptr), m_data('\0') {}
    const unsigned short getData() const;
    StackNode* getPrev() const;
private:
    unsigned short m_data;
    StackNode* prev;
    friend Stack;
};


class Stack {
public:
    Stack() : top(nullptr), count(0), nodeIndexCount(0), m_score(0) {}  

    const bool isEmpty() const;
    const void push(const short data);
    const unsigned short pop();
    StackNode* getTop() const;
    const void setScore(const unsigned short sorce);
    const unsigned short getScore() const;
    
    const unsigned short getCount() const;  // debug
    const unsigned short getNodeIndexCount() const;  // debug
private:
    StackNode* top;
    unsigned short count;  // 0이 아닌 값을 가진 node 개수
    unsigned short nodeIndexCount;  // 스택에, 0값 node 포함 개수
    unsigned short m_score;  // 세로 칸의 점수 입력
};


class Game {
public:
    void gameStart();
private:
    static const unsigned short stackCount = 5;  // 게임에서 사용할 세로 칸(Line) 개수 (MyStack)
    Stack* stack = new Stack[stackCount];  // stackCount 개수 만큼 stack 생성

    const void printAll() const;
    const void pinPush(const unsigned short data, const unsigned short pinNum) const;
    const void scoreSet() const;  // 스택별(세로 칸) 초기 점수 세팅
    void pinSet();  // 핀볼의 시작 상태(세 줄의 구슬 목록) 세팅
};
