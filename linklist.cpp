#include <iostream>
#include <iomanip> 
#include "linklist.h"
using namespace std;

LinkList::LinkList()
{
    tail = new PieCake_struct;
    tail -> id = 0;
    tail -> lname = "";
    tail -> fname = "";
    tail -> mi = '\0';
    tail -> sex = '\0';
    tail -> pORc = '\0';
    tail -> prev = nullptr;
    tail -> next = nullptr;

    head = tail;
    current = nullptr;
    count = 0;
}

// **********************************************************
// Function Name: LinkList()                                *
// Description: Default constructor for the class that      *
// creates the empty list with a dummy tail and             *
// sets count to 0. head points to tail.                    *
// Author: Matthew Gomez                                    *
// Date: 04/9/25                                            *
// **********************************************************

LinkList::~LinkList()
{
    PieCake_struct *temp = head;
    while (temp != nullptr)
    {
        PieCake_struct *nextnode = temp -> next;
        delete temp;
        temp = nextnode;
    }

    head = nullptr;
    tail = nullptr;
    current = nullptr;
    count = 0;
}

// ***********************************************************
// Function Name: ~LinkList()                                *
// Description: Destructor for the class that deletes the    *
// list and sets count to 0.                                 *
// Author: Matthew Gomez                                     *
// Date: 04/9/25                                             *
// ***********************************************************

bool LinkList::Find (const int idnumber)
{
    if (Empty())
    {
        current = nullptr;
        return false;
    }

    PieCake_struct *temp = head;

    while (temp != tail)
    {
        if (temp -> id == idnumber)
        {
            current = temp;
            return true;
        }
        temp = temp -> next;
    }

    current = nullptr;
    return false;
}

// **********************************************************
// Function Name: Find(const int idnumber)                  *
// Description: Member function searching for a matching    *
// id number. If list is empty, returns false and sets it   *
// to nullptr.                                              *
// Author: Matthew Gomez                                    *
// Date: 04/9/25                                            *
// **********************************************************

bool LinkList::Empty()
{
    return (head == tail);
}

// **********************************************************
// Function Name: Empty()                                   *
// Description: returns true if the head->next of the list  *
// points to the tail or the size is zero                   *                  
// Author: Matthew Gomez                                    *
// Date: 04/9/25                                            *
// **********************************************************

int LinkList::Size()
{
    return count;
}

// **********************************************************
// Function Name: Size()                                    *
// Description: Returns count variable which is # of records*
// Author: Matthew Gomez                                    *
// Date: 04/10/25                                           *
// **********************************************************

void LinkList::Push_Back(PieCake_struct *p)
{
    p -> next = tail; // new pointer set to the tail
    p -> prev = tail -> prev; //previous pointer set to what the last record was

    if (tail -> prev != nullptr)
        tail -> prev -> next = p;
    else
        head = p;

    tail -> prev = p;
    count++;
}

// **********************************************************
// Function Name: Push_Back (PieCake_struct *p)             *
// Description: Member function that inserts the record     *
// before the tail. If list is empty, points the head       *
// to it instead.                                           *
// Author: Matthew Gomez                                    *
// Date: 04/10/25                                           *
// **********************************************************

bool LinkList::Delete()
{
    if (current == nullptr)
        return false;

    if (current -> next != nullptr)
        current -> next -> prev = current -> prev;

    if (current -> prev != nullptr)
        current -> prev -> next = current -> next;
    else
        head = current -> next;
    
    delete current;
    current = nullptr;
    count--;
    return true;
}

// **********************************************************
// Function Name: Delete()                                  *
// Description: Member function deleting the current pointer*
// Author: Matthew Gomez                                    *
// Date: 04/10/25                                           *
// **********************************************************

void LinkList::List()
{
    if (Empty())
    {
        cout << "There are no records in this list." << endl;
        return;
    }

    PieCake_struct *temp = head;
    cout << "Here are the records in this list: " << endl;
    while (temp != tail)
    {
        cout << "ID: " << temp -> id << "Name: " << temp -> lname << ", " << temp -> fname << " " << temp -> mi << "." << "Sex: " << temp -> sex
             << "Choice: " << temp -> pORc << endl;
        temp = temp -> next;
    }
}

// *************************************************************
// Function Name: List()                                       *
// Description: Member function that lists the current record  *
// Author: Matthew Gomez                                       *
// Date: 04/10/25                                              *
// *************************************************************

void LinkList::Print()
{
    List();

    int mcake = 0, mpie = 0;
    int fcake = 0, fpie = 0;
    int othercake = 0, otherpie = 0;

    PieCake_struct * temp = head;
    while(temp != tail)
    {
        if(temp->sex == 'M')
        {
            if(temp->pORc == 'C')
                mcake++;
            else if(temp->pORc == 'P')
                mpie++;
        }
        else if(temp->sex == 'F')
        {
            if(temp->pORc == 'C')
                fcake++;
            else if(temp->pORc == 'P')
                fpie++;
        }
        else if(temp->sex == 'O')
        {
            if(temp->pORc == 'C')
                othercake++;
            else if(temp->pORc == 'P')
                otherpie++;
        }
        temp = temp->next;
    }

    cout << "Men who believe that Cheesecake is Pie: " << mpie << endl;
    cout << "Men who believe that Cheesecake is Cake: " << mcake << endl;
    cout << "Women who believe that Cheesecake is Pie: " << fpie << endl;
    cout << "Women who believe that Cheesecake is Cake: " << fcake << endl;
    cout << "Other who believe that Cheesecake is Pie: " << othercake << endl;
    cout << "Other who believe that Cheesecake is Cake: " << otherpie << endl;
    cout << "Total: " << (mpie + mcake + fpie + fcake + othercake + otherpie);
}

// **************************************************************
// Function Name: Print()                                       *
// Description: Member function that prints the record using    *
// List() and counts for each output.                           *
// Author: Matthew Gomez                                        *
// Date: 04/10/25                                               *
// **************************************************************


