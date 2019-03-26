#ifndef STUDENT_H
#define STUDENT_H
#include<iostream>

class Student
{
    public:
        Student();
        Student(char * name);
        Student(Student& other);
        char * getName()const;
        int getFacultyNumber()const;
        int getCourse()const;
        void setName(char * name);
        void setFacultyNumber(int number);
        void setCourse(int course);
        Student& operator=(Student& other);
        bool operator==(Student& other);
        bool operator!=(Student& other);
        friend std::istream& operator>>(std::istream& input, Student& other);
        friend std::ostream& operator<<(std::ostream& output, Student& other);
        ~Student();

    protected:

    private:
        char* name;
        int facultyNumber;
        int course;
};

#endif // STUDENT_H
