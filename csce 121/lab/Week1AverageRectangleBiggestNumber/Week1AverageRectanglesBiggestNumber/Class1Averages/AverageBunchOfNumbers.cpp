#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main ()
{
    // We need to think about the variables we will need in adanvce
    int total = 0, count = 0, number = 0;
    float average;
    cout << "Please enter a number (-1 to quit)"<< endl;
    cin >> number;
    while (number!=-1){
        count++; //count = count +1//
        total += number; //add number to the total//
        cout << "Please enter a number (-1 to quit)"<< endl;
        cin >> number; // This is asking user input >> flow of data//

    }
    average = total / (float(count));
    cout << "The average is " << average << endl;
}