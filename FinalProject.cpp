#include "FinalProject.h"
#include <vector>
#include <iostream>

using namespace std;

Directory * InitArray;


HashTable::~HashTable()
{
//virtual function
}

HashTable::HashTable(int amountOfEmployees)
{
InitArray = new Directory[amountOfEmployees]; //initializes the movielist array
}


void HashTable::insertEmployee(string FnameIn,string LnameIn,string reviewsIn,string lastControbutionIn,string positionIn,int ageIn, int yearEmployedIn)
{
const char* char_Title = LnameIn.c_str();
int ASCI_Sum = 0;
    for(int i=0;i<LnameIn.length();i++)
    {
        ASCI_Sum += char_Title[i];
    }
int mod50 = ASCI_Sum % 10;
InitArray[mod50].addValue(FnameIn,LnameIn,reviewsIn,lastControbutionIn,positionIn,ageIn,yearEmployedIn);
}





void HashTable::findEmployee(string LnameIn)
{
const char* char_Title = LnameIn.c_str();
int ASCI_Sum = 0;
    for(int i=0;i<LnameIn.length();i++)
    {
        ASCI_Sum += char_Title[i];
    }
int mod50 = ASCI_Sum % 10;
Directory::Employee *root = InitArray[mod50].rootOfList;
InitArray[mod50].IsInDirectory(LnameIn,root,mod50);
}


void HashTable::deleteEmployee(string LnameIn)
{
const char* char_Title = LnameIn.c_str();
int ASCI_Sum = 0;
    for(int i=0;i<LnameIn.length();i++)
    {
        ASCI_Sum += char_Title[i];
    }
int mod50 = ASCI_Sum % 10;
Directory::Employee*root = InitArray[mod50].rootOfList;
InitArray[mod50].deleteSpecifiedEmployee(LnameIn,root);
}




void HashTable::printEmployees()
{
bool isEmpty = true;
    for(int i=0;i<10;i++)
    {
        Directory::Employee *root = InitArray[i].rootOfList;
        bool checkEmpty =  InitArray[i].EmptyList(root);
        if(checkEmpty != true)
        {
            InitArray[i].TraverseDirectory(root);
            isEmpty = false;
        }
    }
    if(isEmpty == true)
    {
        cout << "empty" << endl;
    }
}

