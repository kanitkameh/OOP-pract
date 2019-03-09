#include <iostream>
#include"Person.h"
using namespace std;
void sortArray(Person* arr, int n){
    int smallestIndex=0;
    for(int i=0;i<n;i++){
        smallestIndex = i;
        for(int j=i;j<n;j++){
            if(arr[j].getAge()<arr[smallestIndex].getAge()){
                smallestIndex = j;
            }
        }
        swap(arr[i],arr[smallestIndex]);
    }
}
int main()
{
    int n;
    cin >> n;
    Person * p = new Person[n];
    for(int i=0;i<n;i++){
        int age;
        char name[30];
        cin >> name >> age;
        p[i].setName(name);
        p[i].setAge(age);
    }
    sortArray(p,n);
    for(int i=0;i<n;i++){
        cout << p[i].getName() << p[i].getAge() << endl;
    }
    delete [] p;
    return 0;
}

