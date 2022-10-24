#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::cout, std::endl, std::string, std::ifstream, std::fixed, std::setprecision, std::setw;

void minusOddColumn(int** mat, int n) {

    // declare variables
    int length = n;
    int maxCol = -1;
    int maxOdds = -1;
    int numOdds;

    // iterate through matrix
    int element;
    for (int x = 0; x < length; ++x) {

        // count number of odds for current column
        numOdds = 0;
        for (int y = 0; y < length; ++y) {

            // check if current element is odd, and increment if so
            element = mat[x][y];
            if (element % 2 == 1) {
                ++numOdds;
            }
        }

        // check if current column has most odds
        if (numOdds > maxOdds) {
            maxOdds = numOdds;
            maxCol = x;
        }
    }

    // update column with most odds
    for (int y = 0; y < length; ++y) {
        mat[maxCol][y] = -1;
    }
}

void displayMatrix(int** matrix, int length, int padding, int precision) {
    
    cout << fixed << setprecision(precision);
    for (int y = 0; y < length; ++y) {
        for (int x = 0; x < length; ++x) {
            cout << setw(padding) << matrix[x][y] << " ";
        }
        cout << endl;
    }
}

int main() {

    // initialize file reader
    string fileName = "minus_odd_column.txt";
    ifstream fin(fileName);
    if (!fin.is_open()) {
        cout << "ERROR: cannot open: " << fileName << endl;
        return 1;
    }

    // declare variables
    int length;
    fin >> length;
    int** matrix = new int*[length];

    // allocate matrix
    for (int x = 0; x < length; ++x) {
        matrix[x] = new int[length];
    }

    // set matrix
    for (int y = 0; y < length; ++y) {
        for (int x = 0; x < length; ++x) {
            fin >> matrix[x][y];
        }
    }

    // output results
    int padding = 4;
    int precision = 0;
    
    cout << "--- Before: ---" << endl;
    displayMatrix(matrix, length, padding, precision);
    cout << endl;

    minusOddColumn(matrix, length);

    cout << "--- After: ---" << endl;
    displayMatrix(matrix, length, padding, precision);

    return 0;
}