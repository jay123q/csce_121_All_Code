#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using std::cout, std::endl, std::string, std::ifstream, std::setw, std::fixed, std::setprecision;

double pathLength(double** distance, int n, int* path, int m) {

    // declare variables
    int length = n;
    int numCities = m;
    double totalDistance = 0;

    // calculate rolling distance sum
    double currentDistance;
    int prevCity, currCity;
    for (int i = 1; i < numCities; ++i) {
    
        // get current and previous cities
        prevCity = path[i - 1];
        currCity = path[i];

        // calculate current and total distances
        currentDistance = distance[prevCity][currCity];
        totalDistance += currentDistance;
    }

    return totalDistance;
}

void displayMatrix(double** matrix, int length, int padding, int precision) {
    
    cout << fixed << setprecision(precision);
    for (int y = 0; y < length; ++y) {
        for (int x = 0; x < length; ++x) {
            cout << setw(padding) << matrix[x][y] << " ";
        }
        cout << endl;
    }
}

void displayArray(int* array, int length) {
    for (int i = 0; i < length; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void displayDistances(double** distance, int length, int* path, int numCities) {

    int prevCity, currCity;
    double currentDistance;
    for (int i = 1; i < numCities; ++i) {
        prevCity = path[i - 1];
        currCity = path[i];

        currentDistance = distance[prevCity][currCity];

        cout << currentDistance << " ";
        if (i < numCities - 1) {
            cout << "+ ";
        }
    }
    cout << endl;
}

int main() {

    // initialize file reader
    string fileName = "path_length.txt";
    ifstream fin(fileName);
    if (!fin.is_open()) {
        cout << "ERROR: cannot open: " << fileName << endl;
        return 1;
    }

    // declare variables
    int length;
    fin >> length;
    double** distance = new double*[length];

    // allocate distance matrix
    for (int x = 0; x < length; ++x) {
        distance[x] = new double[length];
    }

    // set distance matrix
    for (int y = 0; y < length; ++y) {
        for (int x = 0; x < length; ++x) {
            fin >> distance[x][y];
        }
    }

    // calculate result 1
    int numCities1 = 3;
    int *path1 = new int[numCities1] {0, 1, 2};
    int result1 = pathLength(distance, length, path1, numCities1);
    
    // calculate result 2
    int numCities2 = 6;
    int *path2 = new int[numCities2] {0, 1, 0, 3, 2, 0};
    int result2 = pathLength(distance, length, path2, numCities2);

    // display results
    int padding = 6;
    int precision = 1;

    cout << "distance matrix:" << endl;
    displayMatrix(distance, length, padding, precision);
    cout << "path:      ";
    displayArray(path1, numCities1);
    cout << "distances: ";
    displayDistances(distance, length, path1, numCities1);
    cout << "result:    " << result1 << endl;
    cout << endl;

    cout << "distance matrix:" << endl;
    displayMatrix(distance, length, padding, precision);
    cout << "path:      ";
    displayArray(path2, numCities2);
    cout << "distances: ";
    displayDistances(distance, length, path2, numCities2);
    cout << "result:    " << result2 << endl;
    cout << endl;

    // deallocate distance matrix and path array
    delete[] path1;
    delete[] path2;
    for (int x = 0; x < length; ++x) {
        delete[] distance[x];
    }
    delete[] distance;

    return 0;
}