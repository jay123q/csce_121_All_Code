#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using std::cout, std::endl, std::string, std::ifstream, std::fixed, std::setprecision, std::setw;

void displayMatrix(int** matrix, int width, int height);

int** remove_allzeros_rows(int** matrix, int nrows, int ncolumns, int& new_nrows) {

    // check parameter values for minimum size
    if (nrows < 1 || ncolumns < 1) {
        throw std::invalid_argument("ERROR: not enough rows or columns");
    }

    // declare variables
    int width = ncolumns;
    int height = nrows;
    int newHeight = 0;
    int number;
    bool hasNonzero;

    // count non-zero rows
    for (int y = 0; y < height; ++y) {

        hasNonzero = false;
        for (int x = 0; x < width; ++x) {
            number = matrix[x][y];
            if (number != 0) {
                hasNonzero = true;
                ++newHeight;
                break;
            }
        }
    }

    // create output matrix
    int** outputMatrix = new int*[width];
    for (int x = 0; x < width; ++x) {
        outputMatrix[x] = new int[newHeight] {};
    }

    // iterate through input matrix
    int marker = 0; // used to iterate through output matrix 
    for (int y = 0; y < height; ++y) {

        // check if input matrix's current row is zeroes
        hasNonzero = false;
        for (int x = 0; x < width; ++x) {
            number = matrix[x][y];

            // if row has non-zeroes, mark flag and leave loops
            if (number != 0) {
                hasNonzero = true;
                break;
            }
        }

        // if input matrix's current row is zeroes, skip to next loop
        if (!hasNonzero) { continue; }

        // copy input matrix's non-zero row to output matrix's current row
        for (int x = 0; x < width; ++x) {
            number = matrix[x][y];
            outputMatrix[x][marker] = number;
        }

        // move marker to output matrix's next row index
        ++marker;
    }

    // update output height
    new_nrows = newHeight;

    return outputMatrix;
}

void displayMatrix(int** matrix, int width, int height) {
    
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cout << matrix[x][y] << " ";
        }
        cout << endl;
    }
}

int main() {
    // create file reader
    string fileName = "remove_allzeros_ordered_rows.txt";
    ifstream fin(fileName);
    if (!fin.is_open()) {
        cout << "ERROR: Could not open: " << fileName << endl;
        return 1;
    }
    
    // initialize variables
    int width, height;
    fin >> width >> height;

    // allocate input array
    int** inputArray = new int*[width];
    for (int x = 0; x < width; ++x) {
        inputArray[x] = new int[height] {};
    }

    // set input array
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            fin >> inputArray[x][y];
        }
    }

    // get output array with all non-zero rows 
    int outputHeight;
    int** outputArray = remove_allzeros_rows(inputArray, height, width, outputHeight);

    // display results
    cout << "--- INPUT ARRAY ---" << endl;
    displayMatrix(inputArray, width, height);
    cout << "--- OUTPUT ARRAY ---" << endl;
    displayMatrix(outputArray, width, outputHeight);

    // deallocate arrays
    for (int x = 0; x < width; ++x) {
        delete[] inputArray[x];
        delete[] outputArray[x];
    }
    delete[] inputArray;
    delete[] outputArray;
    
    return 0;
}