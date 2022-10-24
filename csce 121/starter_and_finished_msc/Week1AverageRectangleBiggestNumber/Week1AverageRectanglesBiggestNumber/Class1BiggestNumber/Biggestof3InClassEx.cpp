#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {
    int first,second,third;
    cout << "Please enter three numbers followd by enter after each one";
    cin >> first;
    cin >> second;
    cin >> third;
    if (first>=second &&  first>=third){
        cout << "The biggest is " << first << endl;
    }
    else if (second>=first && second>=third){
        cout << "the biggestis " << second << endl;
    }
    else {
        cout << "The biggest is " << third << endl;
    }
    
}