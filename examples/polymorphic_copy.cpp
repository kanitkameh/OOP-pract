#include <iostream>
#include <cstring>

using namespace std;

class Bird;

class Animal{
public:
    virtual void print(){
        cout << "exist" << endl;
    }

    virtual Animal* clone(){
        return new Animal(*this);
    }
};

class Fish : public Animal{
public:
    void print(){
        cout << "swim" << endl;
    }

    Fish* clone(){
        return new Fish(*this);
    }

};

class Bird : public Animal{
public:
    void print(){
        cout << "fly" << endl;
    }

};

int main()
{
    Fish f;
    Animal* a1 = &f;
    Animal* a2;

    a1->print();

    a2 = a1->clone();

    a2->print();

    return 0;
}
