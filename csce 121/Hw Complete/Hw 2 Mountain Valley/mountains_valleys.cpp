#include <iostream>
#include "functions.h"

using std::cout;
using std::cin; 
using std::endl;

int main() {
	//int number;
	//   cout << "Enter number";
	//   cin >> number;
	//   cout << classify_mv_range_type(number);
	 int a;
	 int b;


	cout << "Enter numbers 10 <= a <= b < 10000: ";
	cin >> a;
	cin >> b;


while (!(is_valid_range(a,b)))
{	
	if (is_valid_range(a,b)== 0){
	cout<< "Invalid Input" << endl;
	cout << "Enter numbers 10 <= a <= b < 10000: ";
	cin >> a;
	cin >> b;	
	is_valid_range(a,b);
	}
	else{

			break;
	}

}


	// TODO(student): print prompt for input
	
	// TODO(student): read the numbers from standard input
//cout << "The valley, mountian, N"<< classify_mv_range_type(number) << endl;
	// TODO(student): validate input (and reprompt on invalid input)

	// TODO(student): compute and display solution
	//count_valid_mv_numbers(a, b); 
count_valid_mv_numbers(a, b);
	return 0;
}
