#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <iostream>
using namespace std;
class Directory
{
    public:
        Directory();
        struct Employee
        {
            string Fname;
            string Lname;
            string reviews;
            string lastControbution;
            string position;
            int age;
            int yearEmployed;
            Employee(){};
            Employee(string FnameIn,string LnameIn,string reviewsIn,string lastControbutionIn,string positionIn,int ageIn, int yearEmployedIn)
            {
                Fname = FnameIn;
                Lname =  LnameIn;
                reviews = reviewsIn;
                lastControbution = lastControbutionIn;
                position = positionIn;
                age = ageIn;
                yearEmployed = yearEmployedIn;

                next = NULL;
                previous = NULL;
            }
            Employee *next;
            Employee *previous;
        };
        virtual ~Directory();
        void TraverseDirectory(Employee *head);
        void addValue(string,string,string,string,string,int,int);
        bool EmptyList(Employee *head);
        void deleteSpecifiedEmployee(string LnameIn,Employee *);
        bool IsInDirectory(string,Employee *head,int);
        Employee *rootOfList;
        Employee *head; // this is the private member variable. It is just a pointer to the first Node
        Employee *tail;

    protected:

    private:
};

#endif // DIRECTORY_H
