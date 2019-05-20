#include <iostream>
#include <cmath>
using namespace std;

class Shape{
public:
    virtual double getPerimeter()=0;
    virtual double getArea()=0;
    virtual Shape* clone()=0;
};

class Triangle : public Shape{
private:
    double a,b,c;
public:
    Triangle(double a, double b, double c){
        this->a=a;
        this->b=b;
        this->c=c;
    }
    double getPerimeter(){
        return a+b+c;
    }
    double getArea(){
        double p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
    Triangle* clone(){
        return new Triangle(*this);
    }
};

class Rectangle : public Shape{
private:
    double a, b;
public:
    Rectangle(double a, double b){
        this->a = a;
        this->b = b;
    }
    double getPerimeter(){
        return 2*(a+b);
    }
    double getArea(){
        return a*b;
    }

    Rectangle* clone(){
        return new Rectangle(*this);
    }
};
class Square : public Rectangle{
public:
    Square(double a):Rectangle(a,a){}

    Square* clone(){
        return new Square(*this);
    }
};
class Figures{
    Shape* s[10];
    int currentSize=0;

public:
    void addShape(Shape& other){
        s[currentSize] = &other;
        currentSize++;
    }
    void printBiggestArea(){
        double maxArea = 0;
        for(int i=0;i<currentSize;i++){
            if(s[i]->getArea()>maxArea){
                maxArea = s[i]->getArea();
            }
        }
        cout << maxArea << endl;
    }
    void printBiggestPerimeter(){
        double maxPerimeter = 0;
        for(int i=0;i<currentSize;i++){
            if(s[i]->getPerimeter()>maxPerimeter){
                maxPerimeter = s[i]->getPerimeter();
            }
        }
        cout << maxPerimeter << endl;
    }
    /**
    void copy(){
        Shape** newArr = new Shape*[size];
        for(int i = 0 ; i < size; i++){
            newArr[i] = s[i]->clone();
        }
        // deleting s
    }**/
};

template<class T>
void sortArray(T* arg1, int n){
    int smallestIndex = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arg1[j]<arg1[smallestIndex]){
                smallestIndex = j;
            }
        }
        swap(arg1[smallestIndex],arg1[i]);
    }
}

int main()
{

    int arr[5] = {4 , 1 , 3 , 2, 5};
    sortArray(arr,5);
    for(int i=0;i<5;i++){
        cout << arr[i] << endl;
    }

    /**
    Square mySquare(3);
    Rectangle myRect(4,5);
    Triangle myTriangle(3,2,7);
    Figures container;
    container.addShape(mySquare);
    container.addShape(myRect);
    container.addShape(myTriangle);
    container.printBiggestArea();
    container.printBiggestPerimeter();
    return 0;
    **/
}
