#include <iostream>
using std::cout, std::endl;

void displayArray(int* array, int length);

/*
Write a function that receives an array A of n integers (all elements >= 0)
and returns a dynamically allocated array containing all even elements of A
first, then all odd elements of A. 
*/
int* separate_even_odd(int* A, unsigned int length) {

    // declare variables
    int* result = new int[length];
    int marker = 0;
    int number = 0;

    // iterate through even elemnts
    for (int i = 0; i < length; ++i) {
        
        // get current number
        number = A[i];

        // add odd number, if any
        if (number % 2 == 0) {
            result[marker] = number;
            ++marker;
        }
    }

    // iterate through odd elements
    for (int i = 0; i < length; ++i) {
        
        // get current number
        number = A[i];

        // add even number, if any
        if (number % 2 == 1) {
            result[marker] = number;
            ++marker;
        }
    }
    
    return result;
}

void displayArray(int* array, int length) {
    for (int i = 0; i < length; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {

    // allocate evens arrays
    unsigned int length1 = 6;
    int* array1  = new int[length1] {1, 2, 3, 4, 5, 6};
    int* separatedArray1 = separate_even_odd(array1, length1);

    unsigned int length2 = 5;
    int* array2  = new int[length2] {-4, -2, 2, 4, 6};
    int* separatedArray2 = separate_even_odd(array2, length2);

    unsigned int length3 = 5;
    int* array3  = new int[length3] {1, 3, 5, 7, 9};
    int* separatedArray3 = separate_even_odd(array3, length3);

    unsigned int length4 = 0;
    int* array4  = new int[length4];
    int* separatedArray4 = separate_even_odd(array4, length4);

    // display results
    cout << "--- Example #1: Mixed Array ---" << endl;
    cout << "Original:  ";
    displayArray(array1, length1);
    cout << "Separated: ";
    displayArray(separatedArray1, length1);
    cout << endl;

    cout << "--- Example #2: Evens Array ---" << endl;
     cout << "Original:  ";
    displayArray(array2, length2);
    cout << "Separated: ";
    displayArray(separatedArray2, length2);
    cout << endl;

    cout << "--- Example #3: Odds Array ---" << endl;
     cout << "Original:  ";
    displayArray(array3, length3);
    cout << "Separated: ";
    displayArray(separatedArray3, length3);
    cout << endl;

    cout << "--- Example #4: Empty Array ---" << endl;
     cout << "Original:  ";
    displayArray(array4, length4);
    cout << "Separated: ";
    displayArray(separatedArray4, length4);
    cout << endl;

    // deallocate arrays
    delete[] array1;
    delete[] separatedArray1;
    delete[] array2;
    delete[] separatedArray2;
    delete[] array3;
    delete[] separatedArray3;
    delete[] array4;
    delete[] separatedArray4;

    return 0;
}