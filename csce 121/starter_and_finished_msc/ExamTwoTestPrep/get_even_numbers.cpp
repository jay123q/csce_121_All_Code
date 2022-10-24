#include <iostream>
using std::cout, std::endl;

void displayArray(int* array, int length);

/*
Write a function that receives an array A of n integers (all elements >= 0)
and returns a dynamically allocated array containing all the even elements
in A. It also returns in the parameter m the number of elements in the
created array.
*/
int* get_even_numbers(int* A, unsigned int n, unsigned int& m) {

    // declare variables
    unsigned int length = n;
    unsigned int evensLength = 0;
    int number; // intermediary value

    // iterate through array
    for (int i = 0; i < length; ++i) {

        // get current element
        number = A[i];

        // check if number is even to increment evens length
        number = A[i];
        if (number % 2 == 0) {
            ++evensLength;
        }
    }

    // allocate evens array
    int marker = 0;
    int* evensArray = new int[evensLength];
    for (int i = 0; i < length; ++i) {

        // get current element
        number = A[i];

        // check if number is even to add to evens array
        if (number % 2 == 0) {            
            evensArray[marker] = number;
            ++marker;
        }
    }

    // set evens array length and return evens array
    m = evensLength;
    return evensArray;
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
    unsigned int evenLength1;
    int* evensArray1 = get_even_numbers(array1, length1, evenLength1);

    unsigned int length2 = 5;
    int* array2  = new int[length2] {-4, -2, 2, 4, 6};
    unsigned int evenLength2;
    int* evensArray2 = get_even_numbers(array2, length2, evenLength2);

    unsigned int length3 = 5;
    int* array3  = new int[length3] {1, 3, 5, 7, 9};
    unsigned int evenLength3;
    int* evensArray3 = get_even_numbers(array3, length3, evenLength3);

    unsigned int length4 = 0;
    int* array4  = new int[length4];
    unsigned int evenLength4;
    int* evensArray4 = get_even_numbers(array4, length4, evenLength4);

    // display results
    cout << "--- Example #1: Mixed Array ---" << endl;
    cout << "Full:  ";
    displayArray(array1, length1);
    cout << "Evens: ";
    displayArray(evensArray1, evenLength1);
    cout << endl;

    cout << "--- Example #2: Evens Array ---" << endl;
    cout << "Full:  ";
    displayArray(array2, length2);
    cout << "Evens: ";
    displayArray(evensArray2, evenLength2);
    cout << endl;

    cout << "--- Example #3: Odds Array ---" << endl;
    cout << "Full:  ";
    displayArray(array3, length3);
    cout << "Evens: ";
    displayArray(evensArray3, evenLength3);
    cout << endl;

    cout << "--- Example #4: Empty Array ---" << endl;
    cout << "Full:  ";
    displayArray(array4, length4);
    cout << "Evens: ";
    displayArray(evensArray4, evenLength4);
    cout << endl;

    // deallocate arrays
    delete[] array1;
    delete[] evensArray1;
    delete[] array2;
    delete[] evensArray2;
    delete[] array3;
    delete[] evensArray3;
    delete[] array4;
    delete[] evensArray4;

    return 0;
}