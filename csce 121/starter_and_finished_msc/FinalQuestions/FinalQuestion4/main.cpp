 #include <iostream>
// #include <string>
// #include <sstream>
// #include "PROBLEM3.h"
// #include <fstream>

 using std::cout;
// using std::string;
// using std::fstream;
// using std::ofstream;
 using std::endl;
int *duplicateEvenNumbers(int *x, int count, int &newCount)
{

    int storage = count;

    for(int index = 0; index < count ; index++)
    {
        if(x[index]%2 == 0)
        {
            storage++;
        }
    }
    newCount = storage;

   int * ReturnThisArray = new int[newCount];


   for(int index = 0 ; index < count ; index++)
   {
       if(x[index]%2 == 0)
       {
           ReturnThisArray[index] = x[index];
           ReturnThisArray[index+1] = x[index];
       }
       else
       {
           ReturnThisArray[index] = x[index];
       }
   }

   return ReturnThisArray;

}
int main()
{
        int x [4] {3,4,8,5};
        int newCount = 4;

        cout << " new thing is " << *duplicateEvenNumbers(x,4,newCount);
        int xy [newCount] {};
        *duplicateEvenNumbers(x,4,newCount);
        cout << " ajf" << xy;



}