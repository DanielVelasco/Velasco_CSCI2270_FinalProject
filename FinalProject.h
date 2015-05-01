#ifndef FINALPROJECT_H
#define FINALPROJECT_H
#include <iostream>
using namespace std;

class Directory {
public:
    // constructor
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

    void addValue(string FnameIn,string LnameIn,string reviewsIn,string lastControbutionIn,string positionIn,int ageIn, int yearEmployedIn)
       {
        Employee *n = new Employee(FnameIn,LnameIn,reviewsIn,lastControbutionIn,positionIn,ageIn,yearEmployedIn);   // create new Node
        n->Fname = FnameIn;
        n->Lname = LnameIn;
        n->reviews = reviewsIn;
        n->lastControbution = lastControbutionIn;
        n->position = positionIn;
        n->age = ageIn;
        n->yearEmployed = yearEmployedIn;

        bool IsBefore;
        if(head != NULL)
        {
            n->next= head;
            Employee *root = head;
            while(root != NULL)
            {
                int compare = root->Lname.compare(n->Lname);
               // cout << compare << endl;
                if(compare > 0)
                {
                    IsBefore = true;
                    if(root == head)
                    {
                        head->previous = n;
                        rootOfList = n;
                        head = n;  // last but not least, make the head point at the new node.
                        break;
                    } else
                    {
                        root->previous->next = n;
                        n->previous = root->previous;
                        n->next = root;
                        root->previous = n;
                        break;
                    }
                }
            root = root->next;
            }
        }
        if(IsBefore == false && head!=NULL)
        {
            n->next = tail->next;
            tail->next = n;
            n->previous = tail;
            tail = n;
        }if(head == NULL)
        {
            head = n;
            rootOfList = n;
            tail = n;
        }
    }

    void TraverseDirectory(Employee *head)
    {
    Employee *cur = head;
        while(cur!=NULL)
            {
                if(cur->Lname != "headDel")
                {
                    cout << cur->Lname << endl;
                }
                  cur = cur->next;
            }
    }


    bool EmptyList(Employee *head)
        {
            if(head == NULL || head->Lname == "headDel")
            {
                return true;
            }else
            {
                return false;
            }
        }

        void deleteSpecifiedEmployee(string LnameIn,Employee *head)
        {
        Employee *cur = head;
        if(head != NULL)
        {
            while(cur!=NULL)
            {
                if(cur->Lname == LnameIn)
                {

               
                    if(cur->next == NULL && cur->previous == NULL)
                    {
                        head = cur;
                        tail = cur;
                    }
                    if(cur == head && cur != tail)
                    {
                        

                        Employee *temp = new Employee(cur->next->Fname,cur->next->Lname,cur->next->reviews,cur->next->lastControbution,cur->next->position,cur->next->age,cur->next->yearEmployed);
                        Employee *NodeDel = head->next;

                        head->Fname = temp->Fname;
                        head->Lname = temp->Lname;
                        head->reviews = temp->reviews;
                        head->lastControbution = temp->lastControbution;
                        head->position = temp->position;
                        head->age = temp->age;
                        head->yearEmployed = temp->yearEmployed;

                        head->previous = NULL;
                        cout << head->next->next->Lname << endl;

                        head->next = head->next->next;
                        head->next->previous = head;
                        delete NodeDel;


                    }
                    else if(cur != head && cur != tail)
                    {
                       
                        Employee *NodeDel = cur;
                        cur->previous->next = cur->next;
                        cur->next->previous = cur->previous;
                        delete NodeDel;
                    }
                    else if(cur == tail && cur != head)
                    {
                        Employee *NodeDel = cur;
                      
                        cur->previous->next = NULL;
                        tail = cur->previous;
                        delete NodeDel;

                    }
                    else if(cur == head && cur == tail)
                    {
                   
                        cur->Lname = "headDel";
                        head = NULL;
                        tail = NULL;
                    }
                    break;
                }
                cur = cur->next;
            }
        }
    }

        bool IsInDirectory(string LnameIn,Employee *head,int index)
        {
        Employee *cur = head;
        bool IsIn = false;
            while(cur!=NULL)
            {
                if(cur->Lname == LnameIn)
                {
                    IsIn = true;
                     cout << index << ":" << cur->Lname
                    << ":" << cur->Fname << endl;
                    return true;
                }
                cur = cur->next;
            }
            if(IsIn == false)
            {
                cout << "not found" << endl;
                return false;
            }
        }
    Employee *rootOfList;
    private:
    Employee *head; // this is the private member variable. It is just a pointer to the first Node
    Employee *tail;
};



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
