#include <iostream>
#include <iomanip>
#include <string>
#include <iostream>

using std::string; using std::stod; using std::getline; using namespace std;




// first we will take an input sum and return then use modulus to find each place
int sumFactorial(int SumME)
{
// now I will run a while loop that is going to get each place 's value and then take the factorial of it
 int Multiplier =1;
 int Place1 = 0;
 int RunningTotal =0;

 int SumOf1Place = 1;
 	 while(SumME != 0 ) //  run while it is not zero
	 { //take place 1 increment up after the math is stored
		 Place1 = SumME / Multiplier % 10; 
         SumME /=10;
     }
// now run a while loop that takes place1 multiplies it with the factorial formula, and subtracts one
if(Place1 == 0)
{// this will not run the while loop but the factorial of 1 is 0
RunningTotal +=1;
}
while(Place1 != 1) // bind this to one since the multiplication of 1 changes nothing
{ // this is saying multiply each number in place1 until it is one, and store the multiplcation until SumOf1Place
SumOf1Place *= Place1;
Place1-=1;
}
RunningTotal += SumOf1Place; // 
SumOf1Place = 1; // reset this value to one 
SumME /=10; // increment down
Multiplier *=10; //  increment up and get the next place

return RunningTotal;
}

int main()
{
    int number;
    cout << "Enter a number";
    cin >> number;
    cout << "The factorial of the nubmer is"<< sumFactorial(number)<<endl;
}

