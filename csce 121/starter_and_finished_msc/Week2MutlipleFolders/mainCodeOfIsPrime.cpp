#include <iostream>
using namespace std;
#include "prime.h"

// now you could make the function isprime or a new file

int main()
{
    int number;
    cout << "Give me a number \n";
    cin >> number;
    cout << number << " is prime? " << isPrime(number);


}