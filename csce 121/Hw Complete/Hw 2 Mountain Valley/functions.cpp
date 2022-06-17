#include <iostream>
#include "functions.h"

using std::cout, std::endl;

 bool is_valid_range(int a, int b) 
 {
// 	// TODO(student): validate input range
	if (((a>9) && (b < 10000)&&(a<b))+(a==b))
	{
		return true;
	}
	else {
		return false;
	}
}

char classify_mv_range_type(int number) {
	
// this will provide the modulus division to the thousands place I am going to use this for lets say 1503 / 1000 = 1.503
//1503/100 = 15.03 //564788291
//	double OneBillionPlace=0;
	/* double HundredMillionPlace = 0;
	double TenMillionPlace =0;
	double OneMillionPlace = 0;
	double HundredThousandsPlace = 0;
	double TenThousandsPlace =0;

	double ThousandPlace =0;
	double HundredPlace = 0;
	double TensPlace = 0;
	double OnePlace =0;
	*/ 
	int Place1 = 0;
	int Place2 = 0;
	int Multiplier = 1;
	int MountainChecker = 0;
	int ValleyChecker = 0;

	
	int DigitCounterFunction = 0;
	int  counter = 0;
	int flag1 = 0;
	int flag2 = 0;

	DigitCounterFunction = number;
/*	

	HundredMillionPlace = number / 100000000 % 10;
	 TenMillionPlace = number / 10000000 %10;
	 OneMillionPlace = number / 1000000 %10;
	 HundredThousandsPlace = number / 100000 %10;
	 TenThousandsPlace =number/10000 %10;
	 ThousandPlace = number / 1000 %10;
	 HundredPlace = number / 100 %10;
	 TensPlace = number / 10 %10;
	 OnePlace =number %10; */

	 //we are going to count the number of digits

	 while (DigitCounterFunction != 0 ){
		counter++;
		DigitCounterFunction /= 10; // this counts digits
	 }
	 
	 for( int i = 1; i < counter+1;i++)
	 {
		 Place1 = number / Multiplier % 10; // this will increment the frist number up when compared to second
		 Multiplier *=10;
		 Place2 = number / Multiplier % 10;
	//	 Multiplier *=10
		// Place3 = number / Multiplier %10;

		 if ( Place2 < Place1 ){
			 flag1++;
			 flag2= 0; // this stops big numbers from triggering 123 stoppers
		 }
		 if ( Place2 > Place1 ){
			 flag2++;
			 flag1=0;
		 }

		if ( ( Place2 == Place1 )|| (flag1 == 2)|| (flag2 == 2)){
		 return 'N';
		

	 }
		 if ( ( i+1 ==  counter ) && (Place2 < Place1) ){ //TensPlace < OnePlace (M) // checks last place
			MountainChecker++;
		 }
		 if ( ( i+1 ==  counter) && (Place2 > Place1) ){ //HundredsPlace > OnePlace (V) checks last palce
			ValleyChecker++;
		 }


		 // add a qualifyier for the first two and bacck two  boolean it to make sure it follows the pattern

	if (MountainChecker == 1){
		return 'M';
	}
	if (ValleyChecker == 1){  // order is important here as mountian being unmutated will casue the N to run
		return 'V';
	}

// potential addd protections to checker statements if the mounntain or valey is unmmtated

	 	if ((( i +1 == counter ) && ((ValleyChecker != 2))) ||((i+1 == counter)&& (MountainChecker != 2))) // if they are not 2 then its neither
		 {
			 return 'N';
		 }

//	Now we will check to find if we need to return a M or V






	 }



	return 'N';

}


void count_valid_mv_numbers(int a, int b) {
	double A=0;
	double number=0;


	int MountainCounter=0;
	int ValleyCounter=0;
	int NeitherCounter=0;
	


	A = a; // a will be iterated over

	for ( int i = a; a <=b;i++){
	number = a;	
	a++;
	if ( classify_mv_range_type( number) == 'M'){
		MountainCounter++;
	}
	if ( classify_mv_range_type( number) == 'V'){
		ValleyCounter++;
	}
	if ( classify_mv_range_type( number) == 'N'){
		NeitherCounter++;
	}	
	}


	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the rnge [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt
cout << "There are "<< MountainCounter << " mountain ranges and " << ValleyCounter << " valley ranges between " << A << " and " << b << "."<<endl;

}