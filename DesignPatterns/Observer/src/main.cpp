#include "Observer.h"

int main() {
    Dog* dog = new Dog;
    Cat* cat = new Cat;
    Owner* o1 = new Owner;

    o1->addAnimal(dog);
    o1->addAnimal(cat);
    o1->work();
}
