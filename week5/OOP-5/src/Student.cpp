#include "Student.h"
#include <cstring>
#include <iostream>
Student::Student()
{
    this->name = nullptr;
}
Student::Student(char * name){
    if(name!=nullptr){
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
    }
}
Student::Student(Student& other){
    setFacultyNumber(other.getFacultyNumber());
    setCourse(other.getCourse());
    char * otherName = other.getName();
    setName(otherName);
    delete[] otherName;
};
char * Student::getName()const{
    char * result = new char[strlen(name)+1];
    strcpy(result,name);
    return result;
};
int Student::getFacultyNumber()const{
    return facultyNumber;
};
int Student::getCourse()const{
    return course;
};
void Student::setName(char * name){
    if(this->name!=nullptr){
        delete[] this->name;
    }
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);

};
void Student::setFacultyNumber(int number){
    this->facultyNumber = number;
};
void Student::setCourse(int course){
    this->course = course;
};
Student& Student::operator=(Student& other){
    if(this!=&other){
        setFacultyNumber(other.getFacultyNumber());
        setCourse(other.getCourse());
        char * otherName = other.getName();
        setName(otherName);
        delete[] otherName;
    }
    return *this;
};
bool Student::operator==(Student& other){
    bool haveEqualNames = false;
    char * otherName = other.getName();
    if(strcmp(name,otherName)==0){
        haveEqualNames = true;
    }
    delete [] otherName;
    return course==other.getCourse() && facultyNumber==other.getFacultyNumber() &&
        haveEqualNames;
};
bool Student::operator!=(Student& other){
    if(*this==other){
        return false;
    }
    return true;
};
Student::~Student()
{
    delete[] this->name;
}
std::istream& operator>>(std::istream& input, Student& other){
    input >> other.course >> other.facultyNumber;
    char name[64];
    input >> name;
    other.setName(name);
    return input;
};
std::ostream& operator<<(std::ostream& output, Student& other){
    output << other.course << " "<< other.facultyNumber << " ";
    char * name = other.getName();
    output << name;
    delete[] name;
    return output;
};
