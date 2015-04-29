#include "FinalProject.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>



using namespace std;

int main(int argc, char* argv[])
{

HashTable HashTableInst(10);


  int choice = 0;
    do
    {
        cout
             << "======Main Menu======" << endl



             //<< "1. Find a movie" << endl
             << "1. Insert employee" << endl
             << "2. Delete employee" << endl
             << "3. Find employee" << endl
             << "4. Print directory" << endl
             << "5. Quit" << endl;

        cin >> choice;

        if(choice == 1){


            cin.ignore();

            string fname;
            cout << "Enter First Name:" << endl;
            getline (cin, fname);

            string lname;
            cout << "Enter Last Name:" << endl;
            getline (cin, lname);

            string position;
            cout << "Enter position:" << endl;
            getline (cin, position);

            string reviews;
            cout << "Enter reviews:" << endl;
            getline (cin, reviews);

            string lastCont;
            cout << "Enter last controbution:" << endl;
            getline (cin, lastCont);

            string age;
            cout << "Enter age:" << endl;
            getline (cin, age);

            string ageEmp;
            cout << "Enter age employed:" << endl;
            getline (cin, ageEmp);

           int int_age =  atoi(age.c_str() );
           int int_ageEmp =  atoi(ageEmp.c_str() );



           HashTableInst.insertEmployee(fname,lname,reviews,lastCont,position,int_age,int_ageEmp);





        }if(choice == 2)
        {

            cin.ignore();

            string mystr;
            cout << "Enter last name:" << endl;
            getline (cin, mystr);

            HashTableInst.deleteEmployee(mystr);


        }if(choice == 3)
        {

            cin.ignore();

            string mystr;
            cout << "Enter last name:" << endl;
            getline (cin, mystr);

            HashTableInst.findEmployee(mystr);




        }if(choice == 4)
        {

            HashTableInst.printEmployees();

        }if(choice == 5)
        {


                cout << "Goodbye!" << endl;

                break;

        }


}while(choice != 5);






    return 0;
}
