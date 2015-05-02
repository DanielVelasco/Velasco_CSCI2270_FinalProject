#ifndef FINALPROJECT_H
#define FINALPROJECT_H
#include <iostream>
using namespace std;


class HashTable
{
    public:
        HashTable(int);
        ~HashTable();
        void insertEmployee(string FnameIn,string LnameIn,string reviewsIn,string lastControbutionIn,string positionIn,int ageIn, int yearEmployedIn);
        void findEmployee(string LnameIn);
        void deleteEmployee(string LnameIn);
        void printEmployees();
    protected:
    private:
};
#endif // HASHTABLE_H
