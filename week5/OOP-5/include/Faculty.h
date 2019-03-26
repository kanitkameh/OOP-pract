#ifndef FACULTY_H
#define FACULTY_H
#include "Student.h"

class Faculty
{
    public:
        Faculty();
        Faculty(Faculty& other);
        Faculty& operator=(Faculty& other);

        void addStudent(Student& toAdd);

        int getSize()const;

        Student& operator[](int index);
        const Student& operator[](int index)const;
        void operator +=(Student& other);
        void operator -=(Student& other);
        void resizeUp();
        void resizeDown();
        int getCapacity()const;
        ~Faculty();

    protected:

    private:
        Student * arr;
        int arrSize;
        int capacity;
};

#endif // FACULTY_H
