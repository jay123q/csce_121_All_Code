#include <iostream>
#include <string>
#include <limits>
#include "./string_calculator.h"

using std::cout; 
using std::endl;
using std::cin;
using std::string;

int main() {
    string rhs = "";
    string lhs = "";
    string UserInput;
    int InputSize;
    int LookForPlus= 0;
    int LookForMult= 0;
    int NoQuit = -1;
    bool GateLocking = true; //this will lock once a + is hit or a *

    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    cout << ">> " << endl;

    getline(cin,UserInput);


    NoQuit = UserInput.find("q"); // look for q

    while(NoQuit < 0){

    
    LookForPlus = UserInput.find("+");

    LookForMult = UserInput.find("*");
    InputSize = UserInput.size();

    if (LookForPlus>0){ // this should look for a + statement then I need to seperate the values
        for(int i=0;i<InputSize;i++){
            if ('+'==UserInput[i]){
                GateLocking = false;
            }
            else if(GateLocking && (' '!=UserInput[i])){
                lhs += UserInput[i];
            }
            else if (!GateLocking&& (' '!=UserInput[i])){
                rhs += UserInput[i];
            }
 // close the gate locking and switch to rhs

            }
            
        cout << "ans ="<< endl;
        cout <<endl;
        cout<<"    "<< add(lhs,rhs)<<endl;
        cout <<endl;
        cout<<endl;
        cout<< ">> "<< endl;
        lhs ="";
        rhs = "";
        GateLocking = true; // reset the lock

        }
    if (LookForMult>0){ // this should look for a + statement then I need to seperate the values
        for(int i=0;i<InputSize;i++){
            if ('*'==UserInput[i]){
                GateLocking = false;
            }
            else if(GateLocking && (' '!=UserInput[i])){
                lhs += UserInput[i];
            }
            else if (!GateLocking&& (' '!=UserInput[i])){
                rhs += UserInput[i];
            }
 // close the gate locking and switch to rhs

            }
            
        cout << "ans ="<< endl;
        cout << endl;
        cout<<"    " <<multiply(lhs,rhs)<<endl;
        cout <<endl;
        cout<<endl;
        cout<< ">> "<< endl;
        GateLocking = true; // reset the lock
        lhs = "";
        rhs = "";
        }

    getline(cin,UserInput); //this is where they can enter q to quit
    NoQuit = UserInput.find("q");
    // TODO(student): implement the UI
    }

cout<< "farvel!"<<endl;
cout <<endl;

}
