/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele

Data File Information
name: data.csv
content: The csv file will contain data in the constant form of:
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include "parallel_tracks.h"
#include <fstream>


using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error; using std::stof;

int main()
{
    double timeArray[SIZE];
    string countryArray[SIZE];
    unsigned int numberArray[SIZE];
    string lastnameArray[SIZE];
    unsigned int rankArray[SIZE];


    string UserInput;

    bool OpenFile=true;
    bool KeepLoop = false;

 //   bool DoNotOpen =true;
    // TODO: create arrays needed
    prep_double_array(timeArray);
    prep_string_array(countryArray);
    prep_unsigned_int_array(numberArray);
    prep_string_array(lastnameArray);
  //  prep_unsigned_int_array(RankArray);
    // TOTO: prep all arrays
	
//     // TODO: prompt until both the file and the contained data are valid
do{
    cout << "Enter file name: ";
    getline(cin, UserInput);
    ifstream inputfile;
    inputfile.open((UserInput));
     OpenFile = true;
     KeepLoop = false;
 //  do open
    if (!(inputfile.is_open()))
    {
        cout <<"Invalid File: Cannot open file"<<endl;
 //        throw std::domain_error("File is missing data");
         KeepLoop = true;
    }

// how do I pass through the file name, to then use getline in the get_runner_data?

    //check for invalid inputs
    if ((inputfile.is_open())){
        try{

        
            get_runner_data(UserInput,timeArray,countryArray,numberArray,lastnameArray);
        }
        catch(std::domain_error &) //  catch by value not by reference stackoverflow -
        {
            KeepLoop = true;
            // cout <<"Enter file name"<<endl;
            // getline(cin, UserInput);
        }
        catch (std::invalid_argument &)
        {
            KeepLoop = true;
            // cout <<"Enter file name"<<endl;
            // getline(cin, UserInput);
            
        }

        }// for if the file is bad


    }
while((OpenFile) && KeepLoop);
    
    // TODO: determine ranking, notice the rank array receives the results
if (OpenFile)
{
    get_ranking(timeArray,rankArray);
}
  //  TODO: Output results

    if((OpenFile))
    {
     print_results(timeArray,countryArray,lastnameArray,rankArray);
    }
        

return 0;

}

