#include <iostream>
#include <string>
#include <stdexcept>
#include "problem1.h"
using std::string; using std::stod; using std::getline; using namespace std;
void add_to_waitlist(Waitlist& waitlist, std::string student)
{
    size_t sizeOfPassed = waitlist.size;
    size_t capOfPassed = waitlist.capacity;
    size_t newSize = sizeOfPassed+1;
    size_t newCap = capOfPassed*2;
    if(newSize >= capOfPassed)
    { //  if the old size +1 is >= capacity old then resize
        std::string* newArray = new std::string [newCap];
        for(int i =0 ; i< capOfPassed; i++)
        {
            newArray[i] = waitlist.array[i];
        }
        newArray[newSize] = student;
        // add the student after all other values are copied
        delete [] waitlist.array;
        waitlist.array = newArray;
        waitlist.size = newSize;
        waitlist.capacity = newCap;
    }
    else
    { //  if the new size is not equal to the old capacity and thus okay to just add to the end
        waitlist.array[waitlist.size] = student;
        waitlist.size = newSize;
    }
}

std::string remove_from_waitlist(Waitlist& waitlist)
{ // remove from waitlist
    // throw expection if there are no students
    // otherwise remove first position and then move all other students up one
    std::string StudentHolder;
    int moveIndex = 0;
    if(waitlist.size == 0)
    {
        throw std::out_of_range(" No students to pop ");
    }
    StudentHolder = waitlist.array[0];
    for(int i = 1; i < waitlist.size ; i++)
    {
        waitlist.array[moveIndex] = waitlist.array[i];
        moveIndex++;
    }
    waitlist.size--;
    return StudentHolder;
}

Waitlist split(Waitlist& waitlist)
{
    size_t sizeUpdater;
    Waitlist newArray;
    newArray.array = new std::string[waitlist.capacity];
    // createa  new waitlist

// I interpeted this as create a nwe waitlist BUT DO NOT REDECLARE over the old

    for( int i = 0 ; i < waitlist.capacity ; i ++)
    {
        if(i %2 == 1)
        { //  every other student
            sizeUpdater++;
            newArray.array[i] = waitlist.array[i];
        }
    }

        newArray.size = sizeUpdater+1;// add one more
        newArray.capacity = waitlist.capacity;
        // add the size and capacity to new waitlist
    return newArray;
    


}
int main()
{

}

