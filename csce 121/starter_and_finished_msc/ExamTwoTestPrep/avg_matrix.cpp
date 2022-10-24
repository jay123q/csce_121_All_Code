#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::cout, std::endl, std::string, std::ifstream, std::setw, std::fixed, std::setprecision;

void avgMatrix(double** inArray, int m, int n, double** outArray) {

    // check parameter values for minimum size
    if (m < 1 || n < 1) {
        throw std::invalid_argument("ERROR: not enough rows or columns");
    }

    // declare variables
    int width = m;
    int height = n;
    double sum;
    int count;
    double value;
    double average;

    // iterate through input matrix
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {

            // declare variables
            sum = 0;
            count = 0;

            // iterate through neighbors
            for (int i = x - 1; i <= x + 1; ++i) {
                
                // skip if index is outside horizontal bounds
                if (i < 0 || i >= width) { continue; }

                for (int j = y - 1; j <= y + 1; ++j) {
                    
                    // skip if index is outside vertical bounds
                    if (j < 0 || j >= height) { continue; }

                    // skip if index is also current element
                    if (i == x && j == y) { continue; }

                    // update variables
                    value = inArray[i][j];
                    sum += value;
                    ++count;
                }
            }

            // calculate and store average
            average = sum / count;
            outArray[x][y] = average;
        }
    }
}

void displayMatrix(double** matrix, int width, int height, int padding, int precision) {
    
    cout << fixed << setprecision(precision);
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            cout << setw(padding) << matrix[x][y] << " ";
        }
        cout << endl;
    }
}

int main() {

    // create file reader
    string fileName = "avg_matrix.txt";
    ifstream fin(fileName);
    if (!fin.is_open()) {
        cout << "ERROR: Could not open: " << fileName << endl;
        return 1;
    }
    
    // initialize variables
    int width, height;
    fin >> width >> height;

    // allocate input array
    double** inputArray = new double*[width];
    for (int x = 0; x < width; ++x) {
        inputArray[x] = new double[height];
    }

    // allocate output array
    double** outputArray = new double*[width];
    for (int x = 0; x < width; ++x) {
        outputArray[x] = new double[height] {};
    }

    // set input array
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            fin >> inputArray[x][y];
        }
    }

    // calculate average matrix
    avgMatrix(inputArray, width, height, outputArray);

    // display results
    int padding = 5;
    int precision = 2;

    cout << "input matrix:" << endl;
    displayMatrix(inputArray, width, height, padding, precision);
    cout << endl;

    cout << "output matrix:" << endl;
    displayMatrix(outputArray, width, height, padding, precision);

    // deallocate input array
    for (int x = 0; x < width; ++x) {
        delete[] inputArray[x];
        delete[] outputArray[x];
    }
    delete[] inputArray;
    delete[] outputArray;

    return 0;
}
