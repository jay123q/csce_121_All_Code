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
    // catch multiple periods, catch multiple commas, catch too much data and too little data, catch spaces in the middle of words/ numbers
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
        cout << "Error: Unable to open"<< endl;
        //end
        return;

    }
    // throw out first line
    getline(File, lineHolder);


    while(!File.fail())
    {
        bool NoError = true;
        getline(File, lineHolder);
        size_t found = lineHolder.find(' ');
        // if it is a newline
        if(lineHolder.empty())
        {
            //hi you are caught
            // end of list
            //continue;
        }
        else if(File.eof())
        {
            break;
        }
        else if (found == -1)
        {
            std::stringstream LineOfValues(lineHolder);

            getline(LineOfValues, IdHolder, ',');
 
            // if(LineOfValues.fail())
            // {
            //     cout << "Error, Invalid input:"<<lineHolder << endl;
            // }
            // // check if it is a digit

            for(char const &c : IdHolder)
            {
                if(std::isdigit(c) == 0 &&  NoError)
                {
                    cout << "Error, Invalid input: "<<lineHolder  << endl;
                    NoError = false;
                    break;

                }
           }

            if(NoError)
            {
                try
                {      
                    string Storage;
                    bool CheckChar = false;
                    getline(LineOfValues, Storage, ',');
                    if(LineOfValues.fail())
                    {
                        NoError = false;
                    }
                    CheckChar = CountInString(Storage);
                    if(!CheckChar)
                    {
                        NoError = false;
                    }
                    fovIntHolder = stoi(Storage);

                    getline(LineOfValues,Storage,',');
                    if(LineOfValues.fail())
                    {
                        NoError = false;
                    }
                    CheckChar = CountInString(Storage);
                    if(!CheckChar)
                    {
                        NoError = false;
                    }
                    Volume = stod(Storage);
                    getline(LineOfValues, Storage, ',');
                    if(LineOfValues.fail())
                    {
                        NoError = false;
                    }
                    CheckChar = CountInString(Storage);
                    if(!CheckChar)
                    {
                        NoError = false;
                    }
                    center_x = stod(Storage);
                    getline(LineOfValues, Storage, ',');
                    if(LineOfValues.fail())
                    {
                        NoError = false;
                    }
                    CheckChar = CountInString(Storage);
                    if(!CheckChar)
                    {
                        NoError = false;
                    }
                    center_y = stod(Storage);
                    getline(LineOfValues, Storage, ',');
                    if(LineOfValues.fail())
                    {
                        NoError = false;
                    }
                    min_x = stod(Storage);
                    getline(LineOfValues, Storage, ',');
                    if(LineOfValues.fail())
                    {
                        NoError = false;
                    }
                    CheckChar = CountInString(Storage);
                    if(!CheckChar)
                    {
                        NoError = false;
                    }
                    max_x = stod(Storage);
                    getline(LineOfValues, Storage, ',');
                    if(LineOfValues.fail())
                    {
                        NoError = false;
                    }
                    min_y = stod(Storage);
                    getline(LineOfValues, Storage, ',');
                    // dont check if it fails since it should
                    if(LineOfValues.fail())
                    {
                        NoError = false;
                    }
                    CheckChar = CountInString(Storage);
                    if(!CheckChar)
                    {
                        NoError = false;
                    }
                    max_y = stod(Storage);
                    if(!NoError)
                    {
                      cout << "Error, Invalid input: " << lineHolder << std::endl;
                    }

                }
                catch(...)
                {
                    cout << "Error, Invalid input: " << lineHolder << std::endl; 
                    NoError=false;

                }
                string testExtra = "123124";
                getline(LineOfValues, testExtra, ',');
                if((testExtra!="123124")&& NoError)
                {
                    cout << "Error, Invalid input: " << lineHolder << std::endl; 
                    NoError = false;

                }
            }

            // test for extra values?
            if(Volume < 0 && NoError)
            {
                cout << "Error, Invalid input: " << lineHolder << std::endl;
                NoError = false;
            }
            
            if(NoError)
            {
            records.insert(IdHolder,fovIntHolder,Volume,center_x,center_y,min_x,max_x,min_y,max_y);
            }
        }
        else
        {
            cout << "Error, Invalid input: " << lineHolder << std::endl;
            NoError=false;

        }

        
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
/*
    string filename("tmp.txt");
    ofstream file_out;

    file_out.open(filename, std::ios_base::app);
*/
    string StringHolder;
    std::ifstream FileOpen(filename);

    ofstream FileResult("result.data");
    // FileResult.open("result1241.txt");
 //   FileResult.open("result142.data");
    if(!FileResult.is_open())
    {
        cout << "Error: Unable to open"<< endl;
        return;
    }
    // if(!(FileOpen))
    // {
    //     cout << " The file is unable to oepn " << std::endl;
    // }
    getline(FileOpen,StringHolder);

    while(!FileOpen.fail())
    {
        if(StringHolder.empty())
        {
          // getline(FileOpen,StringHolder);
         // continue;
  //       FileResult << "Error, Invalid input: " << StringHolder << std::endl;

        }
        else if(FileOpen.eof())
        {
            break;
        }
        else
        {
            std::stringstream ss(StringHolder);
            string Picker;
            string MessageError;
            string MessageComplete;
            ss>>Picker;
            size_t foundDECIMAL = StringHolder.find('.');
            size_t findNEG = StringHolder.find('-');
            if(foundDECIMAL != -1 || findNEG != -1)
            { // catch doubles
                FileResult << "Error, Invalid input: " << StringHolder << std::endl;

            }

            else if(Picker == "AVG")
            {
                int StoreMe;
        
                ss>>StoreMe;
                if(ss.fail() || StoreMe <= 0)
                {
                       FileResult << "Error, Invalid input: " << StringHolder << std::endl;

                }
                else
                {
                    double box =0 ;
                    box = records.average(StoreMe);
            //        box = roundme((float) box,3);
                    FileResult << StringHolder <<": " << box << endl;
            //        MessageComplete = StringHolder+": " + std::to_string(box) + "\n";

 
                }
            }

            else if(Picker == "VAR")
            {
                int StoreMe;
                ss>>StoreMe;
                if(ss.fail()||StoreMe <= 0)
                {
                        FileResult << "Error, Invalid input: " << StringHolder << std::endl;

                        
                }
                else
                {
                    double box;
                    box = records.variance(StoreMe);
                    FileResult << StringHolder <<": " << box << endl;


                }
            }

            else if(Picker == "COUNT")
            {
                int StoreCounter;
                ss>>StoreCounter;
                if(ss.fail() || StoreCounter <= 0)
                {
                        FileResult << "Error, Invalid input: " << StringHolder << std::endl;
                        // MessageError ="Error, Invalid input: "+StringHolder+"\n";
                        // FileResult << MessageError;


                }
                else
                {
                    int count;
                    count= records.countN(StoreCounter);
                    FileResult << StringHolder <<": " << count << endl;
                    // MessageComplete = StringHolder+": " + std::to_string(count) + "\n";
                    // FileResult << MessageComplete;                    
                }
            }

           else if(Picker == "OUTLIER")
            {//(int fov, int k, int N)
                int StoreFov,StoreK,StoreN;
                string Output;
                ss>>StoreFov;
                if(ss.fail()||StoreFov <= 0)
                {
                        FileResult << "Error, Invalid input: " << StringHolder << std::endl;


                }
                else
                {
                    ss>>StoreK;
                    if (ss.fail()||StoreK<=0)
                    {
                        FileResult << "Error, Invalid input: " << StringHolder << std::endl;

                    }
                    else
                    {
                        ss>>StoreN;
                        if (ss.fail()||StoreN<=0)
                        {
                        FileResult << "Error, Invalid input: " << StringHolder << std::endl;

                        }
                        else
                        {
                            Output = records.outliers(StoreFov,StoreK,StoreN);

                            FileResult << StringHolder <<": " << Output << endl;


                        }
                    }
                }
             }
             else
             {
                 // if it is no other input
             FileResult << "Error, Invalid input: " << StringHolder << std::endl;


             }
        }
      getline(FileOpen,StringHolder);
    }
    FileResult.close();

}
// void CellDatabase::removeDeleteThisHei(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
// {
//     records.removeDeleteThis("102664563492900048462363937849459428087",12,825.112,416.767,6086.12,412.441,421.092,6076.72,6095.53);
// }
bool CellDatabase::CountInString(string s)
{
    char ch = '.';
 
    int count =0;
    for(size_t index = 0; index < s.size(); index++)
    {
        char compareMe = s.at(index);
        if(ch == compareMe)
        {
            count++;
        }
    }
    if (count >1)
    {
        return false;
    }
    return true;
}