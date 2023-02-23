#include <vector>

class Observer {
public:
    virtual void update() = 0;
};

class Dog : public Observer {
public:
    void update() override;
};

class Cat : public Observer {
public:
    void update() override;
};

class Owner {
public:
    void addAnimal(Observer* ob);
    void work();
private:
    std::vector<Observer*> animalList;
    void notity();
};
