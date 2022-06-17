#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"
#include <fstream>
#include <sstream>

using std::string; using std::stod; using std::getline; using namespace std;


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the csv file given
//---------------------------------------------------------
void get_runner_data( const std::string& file, double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) 
{


	double time;
	int number;
	string country;
	string lastName;
	string FirstLine;
	bool CapsAllowed=false;




	std::ifstream coeff(file);
	if(!coeff)
	{ //  if the file is not opened
		throw std::invalid_argument("Cannot open file");
	}
	// opening the file
	int x = SIZE;
	
	for (int i = 0; i<x;i++)
		{
		getline(coeff, FirstLine);

		if (FirstLine[0] == '\r' || FirstLine[0] == '\0')
		{
			cout <<"Invalid File: File missing data"<<endl;
			throw std::domain_error("File missing data");
		}

	std::stringstream FileLine(FirstLine);

	FileLine >> time;

	if (FileLine.fail())
	{
		cout <<"Invalid File: File contains invalid data (time)"<<endl;
		throw std::domain_error("File contains invalid data (time)");
	}
	if(time < 0 || !(0 < time && time < INT32_MAX ))
	{
		cout <<"Invalid File: File contains invalid data (time)"<<endl;
		throw std::domain_error("File contains invalid data (time)");
	}
	timeArray[i] = time;

	FileLine >> country;
	if (FileLine.fail())
	{
		cout <<"Invalid File: File contains invalid data (country)"<<endl;
		throw std::domain_error("File contains invalid data (country)");
	}
	if ( country[0] == tolower(country[0])||country[1] == tolower(country[1])||country[2] == tolower(country[2])) // check for caps
	{
		cout <<"Invalid File: File contains invalid data (country)"<<endl;
		throw std::domain_error("File contains invalid data (country)");

	}
	if(country.size()>3)
	{
		cout <<"Invalid File: File contains invalid data (country)"<<endl;
		throw std::domain_error("File contains invalid data (country)");
	}
	countryArray[i]= country;

	FileLine >> number;
	if (FileLine.fail())
	{
		cout <<"Invalid File: File contains invalid data (number)"<<endl;
		throw std::domain_error("File contains invalid data (number)");
	}
	if (!( 0 <= number && number < 100))
	{
		cout <<"Invalid File: File contains invalid data (number)"<<endl;
		throw std::domain_error("File contains invalid data (number)");		
	}
	numberArray[i] = number;

	FileLine >> lastName;
	if (FileLine.fail())
	{
		cout <<"Invalid File: File contains invalid data (name)"<<endl;
		throw std::domain_error("File contains invalid data (name)");
	}
	lastnameArray[i] = lastName;
 
	}
    for (int i =0; i < x; i++){ // Name Checking
                int sizeName = lastnameArray[i].size();
                if (sizeName <=1)
                {
					cout <<"Invalid File: File contains invalid data (name)"<<endl;
                    throw std::domain_error("File contains invalid data (name)");     
                }
        for (int stringName =0;stringName < sizeName; stringName++)
		{
            char firstLetter = lastnameArray[i][stringName];
            int firstLetterAscii = firstLetter;
            if ( lastnameArray[i][stringName-1] == ' ')
            {
                CapsAllowed = true; // this covers if there is a space then a cap is allowed
            }
            if(stringName == 0 && !CapsAllowed)
            {
                int toUpper = toupper(firstLetter); // this checks caps letter
                if (firstLetter != toUpper){
					cout <<"Invalid File: File contains invalid data (name)"<<endl;
      	           throw std::domain_error("File contains invalid data (name)");                    
                }
            }
            else if (!CapsAllowed){
           //     int toLower = tolower(firstLetter);
                if(!( 97<= firstLetterAscii && firstLetterAscii <=122)){ //lowercse a through z
				cout <<"Invalid File: File contains invalid data (name)"<<endl;
                 throw std::domain_error("File contains invalid data (name)");                      
                }
            }

        }


        
    }
  //TODO
 FirstLine = "";
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	int x = SIZE;
	for ( int i = 0;i<x;i++)
	{
	if(ary[i] != 0.0){
		ary[i] = 0.0;

	}	
	}
  //TODO
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	//TODO
	int x = SIZE;
		for ( int i = 0;i<x;i++)
	{
	if(ary[i] != 0){
		ary[i] = 0;

	}	
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	int x = SIZE;
		for ( int i = 0;i<x;i++)
	{
	if(ary[i] != "N/A"){
		ary[i] = "N/A";

	}	
	}	
	//TODO
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{



	int counter =0;
	double StorageArray[SIZE];
	int SizeStorage = SIZE;
for (int i = 0; i < SizeStorage;i++)
{
	StorageArray[i]=timeArray[i]; // put the time into a mutable array
}
while ( counter != 9 )
{
	for(int i=0;i<SizeStorage-1;i++) // sort array
	{
		if(StorageArray[i]>StorageArray[i+1])
		{
			double temp = StorageArray[i];
			StorageArray[i] = StorageArray[i+1];
			StorageArray[i+1]=temp;
		}
	}

	counter++;
}
double timeInt = 0;
int z = 0;
double StorageInt = 0;
for (int a = 0; a < SizeStorage;a++) // look for index
{	
	StorageInt = StorageArray[a];
	for(int i = 0; i<SizeStorage;i++)
	{
		timeInt = timeArray[i];
		if(StorageInt==timeInt)
		{
			z++;
			rankArray[i] = z;
 
		}
	}
}


}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(const std::string word) {
	string ret = word;

	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}