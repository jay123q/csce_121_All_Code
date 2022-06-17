#include <iostream>
#include <string>
#include <sstream>
#include "CellDatabase.h"
#include "CellData.h"
#include <fstream>

using std::cout;
using std::string;
using std::fstream;
using std::ofstream;
using std::endl;

// Default constructor/destructor. Modify them if you need to.
CellDatabase::CellDatabase() : records()  {}
CellDatabase::~CellDatabase() {}


void CellDatabase::loadData(const string& filename) 
{
    std::ifstream File(filename);
    string lineHolder;
    string IdHolder;
    double Volume,center_x,center_y,min_x,max_x,min_y,max_y;
    int fovIntHolder;
    /*
id, fov,
volume,center_x,center_y,min_x,max_x,min_y,max_y, 
    */
    // Error, Invalid input:
    if(!(File))
    {
        cout << "Error: Unable to open"; //<< endl;
        //end
        return;

    }
    // throw out first line
    getline(File, lineHolder);

        try
        {
            int counter = 0;
    while(!File.fail())
    {
        counter++;
        getline(File, lineHolder);

        std::stringstream LineOfValues(lineHolder);

        getline(LineOfValues, IdHolder, ',');
        string Storage;
        getline(LineOfValues, Storage, ',');

        // if(LineOfValues.fail())
        // {
        //     cout << "Error, Invalid input:"<<lineHolder << endl;
        // }
        // // check if it is a digit
        for(char const &c : IdHolder)
        {
            if(std::isdigit(c) == 0)
            {
                cout << "Error, Invalid input:"<<lineHolder  << endl;

            }
        }

        fovIntHolder = stoi(Storage);
        getline(LineOfValues,Storage,',');
        Volume = stod(Storage);
        getline(LineOfValues, Storage, ',');
        center_x = stod(Storage);
        getline(LineOfValues, Storage, ',');
        center_y = stod(Storage);
        getline(LineOfValues, Storage, ',');
        min_x = stod(Storage);
        getline(LineOfValues, Storage, ',');
        max_x = stod(Storage);
        getline(LineOfValues, Storage, ',');
        min_y = stod(Storage);
        getline(LineOfValues, Storage, ',');
        max_y = stod(Storage);
        // test for extra values?
        if(Volume < 0)
        {
            cout << "Error, Invalid input:" << lineHolder << std::endl;
        }
        
        records.insert(IdHolder,fovIntHolder,Volume,center_x,center_y,min_x,max_x,min_y,max_y);
    }
        }
        catch(std::invalid_argument)
        {
            // cout << " This broke on line " << counter << std::endl;
        }


    
    }
    
    // Implement this function


// Do not modify
void CellDatabase::outputData(const string& filename) {
    ofstream dataout("sorted." + filename);

    if (!dataout.is_open()) 
    {
        cout << "Error: Unable to open " << filename << endl;
        exit(1);
    }

    dataout << records.print();
}

void CellDatabase::performQuery(const string& filename) 
{
    // Implement this function
    string StringHolder;
    std::ifstream FileOpen(filename);
    if(!(FileOpen))
    {
        cout << " The file is unable to oepn " << std::endl;
    }
    getline(FileOpen,StringHolder);
    while(!FileOpen.fail())
    {
    std::stringstream ss(StringHolder);
    string Picker;
    ss>>Picker;
    if(Picker == "AVG")
    {
        int StoreMe;
 
        ss>>StoreMe;
        if(ss.fail())
        {
            cout << "Error, invalid input: " << StringHolder << std::endl;
        }
        else
        {
            double box =0 ;
            box = records.average(StoreMe);
            cout << StringHolder <<": " << box << endl;
        }
    }

    if(Picker == "VAR")
    {
        int StoreMe;
        ss>>StoreMe;
        if(ss.fail())
        {
            cout << "Error, invalid input: " << StringHolder << std::endl;
        }
        else
        {
            double box;
            box = records.variance(StoreMe);
            cout << StringHolder <<": " << box << endl;
        }
    }

    if(Picker == "COUNT")
    {
        int StoreCounter;
        ss>>StoreCounter;
        if(ss.fail())
        {
            cout << "Error, invalid input: " << StringHolder << std::endl;
        }
        else
        {
            int count;
            count= records.countN(StoreCounter);
            cout << StringHolder <<": " << count << endl;
        }
    }

    if(Picker == "OUTLIER")
    {//(int fov, int k, int N)
        int StoreFov,StoreK,StoreN;
        string Output;
        ss>>StoreFov;
        if(ss.fail())
        {
            cout << "Error, invalid input: " << StringHolder << std::endl;
        }
        ss>>StoreK;
        if(ss.fail())
        {
            cout << "Error, invalid input: " << StringHolder << std::endl;
        }
        ss>>StoreN;
        if(ss.fail())
        {
            cout << "Error, invalid input: " << StringHolder << std::endl;
        }
        else
        {
            Output = records.outliers(StoreFov,StoreK,StoreN);
            cout << StringHolder <<": " << Output << endl;
        }
    }
    getline(FileOpen,StringHolder);
    }
}
// void CellDatabase::removeDeleteThisHei(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
// {
//     records.removeDeleteThis("102664563492900048462363937849459428087",12,825.112,416.767,6086.12,412.441,421.092,6076.72,6095.53);
// }
