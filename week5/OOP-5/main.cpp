#include <iostream>
#include "Student.h"
#include "Faculty.h"
using namespace std;

int main()
{
    Faculty fmi;
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        Student s;
        cin >> s;
        fmi.addStudent(s);
    }
    Student s;
    cin >> s;
    fmi-=s;
    for(int i=0;i<fmi.getSize();i++){
        cout << fmi[i]<<endl;
    }
    return 0;
}
