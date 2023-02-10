#include <iostream>
class Stack;
class Game;


class StackNode {
public:
    StackNode() : prev(nullptr) {}
private:
    unsigned short data;
    StackNode* prev;
    friend Stack;
};


class Stack {
public:
    Stack() : count(0), top(nullptr), m_score(0) {}
    
    StackNode* top;

    void push(const short data);
    short pop();
    void setScore(const unsigned short sorce);
    const unsigned short getScore() const;
    const unsigned short getCount() const;
private:
    unsigned short count; // 스택의 현재 node 개수
    unsigned short m_score; // 세로 칸의 점수 입력
};


class Game {
public:
    void gameStart();
private:
    static const unsigned short stackCount = 5; // 게임에서 사용할 세로 칸(Line) 개수
    Stack* stack = new Stack[stackCount]; // stackCount 개수 만큼 stack 생성

    // const unsigned short MaxCouning() const; // 게임에서 사용할 세로 칸(Line) 스택들 中 가장 많은 count 추출
    const void printAll() const;    
    void pinSet(); // 게임 초기 상태 세팅
    void scoreSet(); // 스택별 초기 점수 세팅
    void pinPush(unsigned short pinNum, unsigned short data);
};
