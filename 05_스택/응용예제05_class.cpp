#include "응용예제05.h"

const unsigned short StackNode::getData() const {
    return m_data;
}

StackNode* StackNode::getPrev() const {
    return prev;
}


const bool Stack::isEmpty() const {
    bool tmp;

    if (top == nullptr) {
        tmp = true;
    } else {
        tmp = false;
    }

    return tmp;
}

const void Stack::push(const short data) {
    if ((isEmpty() == false) && (top->m_data == data)) {  // 맨 위 구슬 번호가 새 구슬 번호와 같다면
        pop();
    } else if (data == 0) {
    } else {
        StackNode* newNode = new StackNode;
        
        newNode->m_data = data;
        newNode->prev = top;
        top = newNode;
        ++nodeIndexCount;

        if (data != 0) {
            ++count;
        }
    }
}

const unsigned short Stack::pop() {
    if (isEmpty() == false) {
        StackNode* tmp = top;
        short item = top->m_data;

        if (tmp->m_data != 0) {
            --count;
        }

        top = top->prev;
        delete tmp;
        tmp->prev = nullptr;
        --nodeIndexCount;

        return item;
    } else {
        throw std::out_of_range("ERR : not allowed ' pop() '; ( This Stack is NULL.\n");
    }
}

StackNode* Stack::getTop() const {
    return top;
}

const void Stack::setScore(const unsigned short score) {
    m_score = score;
}

const unsigned short Stack::getScore() const {
    return m_score;
}

const unsigned short Stack::getCount() const {
    return count;
}

const unsigned short Stack::getNodeIndexCount() const {
    return nodeIndexCount;
}


void Game::gameStart() {
    unsigned short pinNum, data;

    pinSet();
    scoreSet();
    printAll();
    for (unsigned short i = 0; i < 10; ++i) {
        std::cout << "( 구슬의 값 X ) ( 구슬이 들어갈 번호 Y ) 입력 ( ex : X Y ) : ";
        std::cin >> data >> pinNum;
        pinPush(data, pinNum);
    }
    printAll();
}

const void Game::printAll() const {
    for (unsigned short i = 0; i < stackCount; ++i) {
        StackNode* horse = stack[i].getTop();
        unsigned int sum = 0;

        std::cout << std::endl << "stack[" << i+1 << "] ";
        std::cout << "Count : " << stack[i].getCount();        
        std::cout << ", IndexCount : " << stack[i].getNodeIndexCount();
        std::cout << ", score : " << stack[i].getScore() << std::endl;

        while (horse != nullptr) {
            sum += horse->getData();
            std::cout << horse->getData() << ", ";
            horse = horse->getPrev();
        }

        std::cout << "\tstack[" << i+1 << "] Fanal score = " << sum * stack[i].getScore() << std::endl;
    }
}

const void Game::pinPush(const unsigned short data, const unsigned short pinNum) const {
    stack[pinNum - 1].push(data);
}

const void Game::scoreSet() const {
    unsigned short scoreTmp;

    std::cout << "각 세로 칸의 점수 " << stackCount << "개 입력 : ";
    
    for (unsigned short i = 0; i < stackCount; ++i) {
        std::cin >> scoreTmp;

        stack[i%stackCount].setScore(scoreTmp);
    }
}

void Game::pinSet() {
    short tmp[15];

    std::cout << "게임 시작 상태(세 줄의 구슬 목록) : ";

    for (unsigned short i = 0; i < stackCount*3; ++i) {        
        std::cin >> tmp[(stackCount*3) - 1 - i];
    }

    for (unsigned short i = 0; i < stackCount*3; ++i) {        
        stack[stackCount - (i%stackCount) - 1].push(tmp[i]);
    }
}
