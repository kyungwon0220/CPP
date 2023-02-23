#include "Observer.h"
#include <iostream>

void Dog::update() {
    std::cout << "bark" << std::endl;
}

void Cat::update() {
    std::cout << "meow" << std::endl;
}

void Owner::notity() {
    for (std::vector<Observer*>::iterator iter = animalList.begin(); iter != animalList.end(); ++iter) {
        Observer* tmp = *iter;
        tmp->update();
    }
}

void Owner::addAnimal(Observer* ob) {
        animalList.emplace_back(ob);
}

void Owner::work() {
    std::cout << "work() 작업" << std::endl;
    notity();
}
