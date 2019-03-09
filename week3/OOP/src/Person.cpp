#include "Person.h"
#include "cstring"
Person::Person(){
    name = nullptr;
    age = 0;
};
Person::Person(char * name, int age = 0){
    if(name!=nullptr){
        this->name = new char[strlen(name)];
        strcpy(this->name,name);
    }else{
        this->name = nullptr;
    }
    this->age = age;
}
int Person::getAge() const{
    return age;
};
void Person::setAge(int age){
    this->age = age;
};
char * Person::getName(){
    return name;
};
void Person::setName(char * name){
    if(name!=nullptr){
        delete[] this->name;
        this->name = new char[strlen(name)];
        strcpy(this->name,name);
    }
};
Person::~Person()
{
    delete [] name;
}
