#include "Faculty.h"

Faculty::Faculty()
{
    arrSize=0;
    capacity=8;
    arr = new Student[capacity];
}
Faculty::Faculty(Faculty& other){
    delete[] arr;
    arr = new Student[other.getCapacity()];
    int otherSize = other.getSize();
    for(int i=0;i<otherSize;i++){
        arr[i] = other[i];
    }
};
void Faculty::resizeUp(){
    Student * old = arr;
    arr = new Student[capacity*2];
    for(int i=0;i<arrSize;i++){
        arr[i]=old[i];
    }
    delete [] old;
    capacity = capacity * 2;
};
void Faculty::resizeDown(){
    Student * old = arr;
    arr = new Student[capacity/2];
    for(int i=0;i<arrSize;i++){
        arr[i]=old[i];
    }
    delete[] old;
    capacity = capacity/2;
};
int Faculty::getCapacity()const{
    return capacity;
};
Faculty& Faculty::operator=(Faculty& other){
    if(&other!=this){
        delete[] arr;
        arr = new Student[other.getCapacity()];
        int otherSize = other.getSize();
        for(int i=0;i<otherSize;i++){
            arr[i] = other[i];
        }
    }
    return *this;
};

void Faculty::addStudent(Student& toAdd){
    if(capacity==arrSize){
        resizeUp();
    }
    arr[arrSize]=toAdd;
    arrSize++;
};
int Faculty::getSize()const{
    return arrSize;
};
Student& Faculty::operator[](int index){
    return arr[index];
};
const Student& Faculty::operator[](int index)const{
    return arr[index];
};
void Faculty::operator+=(Student& other){
    addStudent(other);
};
void Faculty::operator-=(Student& other){
    int i=0; bool hasFound=false;
    for(;!hasFound && i<arrSize;i++){
        if(arr[i]==other){
            hasFound = true;
        }
    }
    if(!hasFound) return;
    for(;i<arrSize-1;i++){
        arr[i]=arr[i+1];
    }
    delete &(arr[arrSize-1]);
    arrSize--;
};
Faculty::~Faculty()
{
    delete[] arr;
}
