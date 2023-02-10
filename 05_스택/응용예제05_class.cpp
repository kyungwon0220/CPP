#include "응용예제05.h"

void Stack::push(const short data) {
    StackNode* newNode = new StackNode;
    
    newNode->data = data;
    newNode->prev = top;
    top = newNode;
    ++count;
}

short Stack::pop() {
    StackNode* tmp = top;
    short item = tmp->data;
    
    top = top->prev;
    delete tmp;
    --count;

    return item;
}

const unsigned short Stack::getCount() const {
    return count;
}

void Stack::setScore(const unsigned short score) {
    m_score = score;
}

const unsigned short Stack::getScore() const {
    return m_score;
}


void Game::gameStart() {
    unsigned short pinNum, data; // 초기 추가 세팅

    pinSet();
    scoreSet();
    printAll(); // debug
    
    for(unsigned short i=0; i<15; ++i) {
        std::cout << "input : ( 구슬의 값 X ) ( 구슬이 들어갈 번호 Y ) 입력 : ( ex : X Y )";
        std::cin >> pinNum >> data;
        pinPush(pinNum, data);
    }

    printAll(); // debug
}

// const unsigned short Game::MaxCouning() const {
//     unsigned short maxCount =stack[0].getCount(); // 생성된 스택 中 가장 많은 data 가진 개수

//     for (unsigned i=0; i<stackCount; ++i) {
//         if (maxCount < stack[i].getCount()) {
//             maxCount = stack[i].getCount();
//         }                
//     }

//     return maxCount;
// }

const void Game::printAll() const {    
    unsigned short tmp = stack[stackCount - 1].getCount(); // 

    std::cout << std::endl;
    for (unsigned short i=0; i<tmp; ++i) {
        for (unsigned short j=0; j<stackCount; ++j) {
            std::cout << stack[j].pop() << "\t\t";
        }
        std::cout << std::endl;
    }
    for (unsigned short i=0; i<stackCount; ++i){        
        std::cout << "stack[" << i+1 << "]\t";
    }
    std::cout << std::endl;
    for (unsigned short i=0; i<stackCount; ++i){        
        std::cout << "count : " << stack[i%stackCount].getScore() << "\t";
    }
    std::cout << std::endl;
}

void Game::pinSet() {
    short tmp;

    std::cout << "게임 시작 상태 : ";

    for (unsigned short i=0; i<stackCount*3; ++i) {        
        std::cin >> tmp;
        
        stack[i%stackCount].push(tmp);
    } // for end
}

void Game::scoreSet() {
    std::cout << "각 세로 칸의 점수 : ";

    unsigned short scoreTmp;
    for (unsigned short i=0; i<stackCount; ++i) {
        std::cin >> scoreTmp;

        stack[i%stackCount].setScore(scoreTmp);
    } // for end
}

void Game::pinPush(unsigned short pinNum, unsigned short data) {
    stack[pinNum - 1].push(data);
}
