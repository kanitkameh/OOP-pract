#ifndef PERSON_H
#define PERSON_H

class Person
{
    public:
        Person();
        Person(char * name, int age);
        ~Person();
        int getAge() const;
        void setAge(int age);
        char * getName();
        void setName(char * name);

    protected:

    private:
    char * name;
    int age;
};

#endif // PERSON_H
