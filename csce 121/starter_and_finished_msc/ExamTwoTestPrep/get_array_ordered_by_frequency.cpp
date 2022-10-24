#include <iostream>
using std::cin, std::cout, std::endl;

void displayArray(int* array, int length);

/*
that, given an array a of  size_a elements, it returns a dynamically
allocated array such that the new array contains all elements of a
(without repetition), ordered by how frequently they appear in a.
*/
int* get_array_ordered_by_frequency (int *a, unsigned int size_a, unsigned int& new_array_size) {

    // declare variables
    int length = size_a;
    int numUniques = 0;
    int* uniques = new int[length];
    int* counts = new int[length] {};

    // iterate through input array
    int number;
    int unique;
    bool found;
    for (int i = 0; i < length; ++i) {
        // get current element and set found flag
        number = a[i];
        found = false;

        // iterate through uniques array
        for (int j = 0; j < numUniques; ++j) {
            // get current unique element
            unique = uniques[j];
            if (number == unique) {
                found = true;
                ++counts[j];
                break;
            }
        }

        // if unique is found, update unique array
        if (!found) {
            uniques[numUniques] = number;
            ++numUniques;
        }
    }

    // sort uniques array
    int* sorted = new int[numUniques];
    int max;
    int maxIndex;
    int marker = 0;
    for (int i = 0; i < numUniques; ++i) {

        // find the highest count and corresponding index
        max = -1;
        maxIndex = -1;
        for (int j = 0; j < numUniques; ++j) {
            number = counts[j];
            if (number > max) {
                max = number;
                maxIndex = j;
            }
        }

        // set the next most frequent unique into sorted array
        sorted[marker] = uniques[maxIndex];
        ++marker;              // move the sorted array marker
        counts[maxIndex] = -1; // de-max count at max index
    }

    // wrap up code
    delete[] uniques;               // deallocate uniques array
    delete[] counts;                // deallocate counts array
    new_array_size = numUniques;    // set uniques array length
    return sorted;                  // return sorted array
}

void displayArray(int* array, int length) {
    for (int i = 0; i < length; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void test() {
    cout << "----- RUNNING TEST() -----" << endl;

    // allocate arrays
    unsigned int length1 = 8;
    int* array1 = new int[length1] {-1, 3, -1, 1, 1, 4, 3, 3};
    unsigned int uniquesLength1;
    int* uniques1 = get_array_ordered_by_frequency(array1, length1, uniquesLength1);

    unsigned int length2 = 6;
    int* array2 = new int[length2] {5, 2, 1, 2, 5, 2};
    unsigned int uniquesLength2;
    int* uniques2 = get_array_ordered_by_frequency(array2, length2, uniquesLength2);

    unsigned int length3 = 9;
    int* array3 = new int[length3] {3, 3, 3, 9, 9, 9, 5, 5, 5};
    unsigned int uniquesLength3;
    int* uniques3 = get_array_ordered_by_frequency(array3, length3, uniquesLength3);

    unsigned int length4 = 0;
    int* array4 = new int[length4] {};
    unsigned int uniquesLength4;
    int* uniques4 = get_array_ordered_by_frequency(array4, length4, uniquesLength4);

    // display results
    cout << "--- Example #1: Regular Array ---" << endl;
    cout << "Original: ";
    displayArray(array1, length1);
    cout << "Uniques:  ";
    displayArray(uniques1, uniquesLength1);
    cout << endl;

    cout << "--- Example #2: Simpler Array ---" << endl;
    cout << "Original: ";
    displayArray(array2, length2);
    cout << "Uniques:  ";
    displayArray(uniques2, uniquesLength2);
    cout << endl;

    cout << "--- Example #3: Uniform Array ---" << endl;
    cout << "Original: ";
    displayArray(array3, length3);
    cout << "Uniques:  ";
    displayArray(uniques3, uniquesLength3);
    cout << endl;

    cout << "--- Example #4: Empty Array ---" << endl;
    cout << "Original: ";
    displayArray(array4, length4);
    cout << "Uniques:  ";
    displayArray(uniques4, uniquesLength4);
    cout << endl;


    // deallocate arrays
    delete[] array1;
    delete[] uniques1;
}

int main() {
    test();
    cout << "----- RUNNING MAIN() -----" << endl;

    // get input array and size
    int length;
    cout << "Enter (a) number of values and (b) list of values: ";
    cin >> length;

    int* array = new int[length];
    for (int i = 0; i < length; ++i) {
        cin >> array[i];
    }

    // debug
    unsigned int numUniques;
    int* uniques = get_array_ordered_by_frequency(array, length, numUniques);
    displayArray(uniques, numUniques);

    // deallocate input array
    delete[] array;

    return 0;
}