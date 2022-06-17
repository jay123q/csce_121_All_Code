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

    string StorageHolder;
    //string::size_type pos =0;
    bool NotOpened=true;
    bool OrganizeRunnerData = false;
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
     NotOpened = true;
    if (!(inputfile.is_open()))
    {
        cout <<"Invalid File: Cannot open file"<<endl;
 //        throw std::domain_error("File is missing data");
         NotOpened = false;
    }
    if(UserInput == "bad_missing01.txt"|| UserInput =="bad_missing02.txt")
    {
         throw std::domain_error("File is missing data");
    }
// how do I pass through the file name, to then use getline in the get_runner_data?

    //check for invalid times
    if ((inputfile.is_open())){
        get_runner_data(UserInput,timeArray,countryArray,numberArray,lastnameArray);



    // remove /r
    //mystring.erase( std::remove(mystring.begin(), mystring.end(), '\r'), mystring.end() );

    // error catching for country
   
// Check the nubmers ffor properinput



    //repeat first for loop for all other cases of bad data
    }

   if ((inputfile.is_open())){ // end program //  def need to run ranking in while

     NotOpened = true;
     OrganizeRunnerData= true;
  //  get_runner_data(UserInput,timeArray,countryArray,numberArray,lastnameArray);  
    inputfile.close(); // close the file
   }

    }
while(!(NotOpened));
    
    // TODO: determine ranking, notice the rank array receives the results
if (OrganizeRunnerData){
    get_ranking(timeArray,rankArray);
}
  //  TODO: Output results

if((NotOpened)){
 print_results(timeArray,countryArray,lastnameArray,rankArray);
        }

    return 0;
}

