#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout, std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    // TODO(student): implement
if (digit == 48 || digit == 30){
    return 0;
} // this turns char into actual workable numbers
if (digit == 49 || digit == 31){
    return 1;
}
if (digit == 50 || digit == 32){
    return 2;
}
if (digit == 51 || digit == 33){
    return 3;
}
if (digit == 52 || digit == 34){
    return 4;
}
if (digit == 53 || digit == 35){
    return 5;
}
if (digit == 54 || digit == 36){
    return 6;
}
if (digit == 55 || digit == 37){
    return 7;
}
if (digit == 56 || digit == 38){
    return 8;
}
if (digit == 57 || digit == 39){
    return 9;
}
else{
    throw std::invalid_argument("wrong character");
}
}
char decimal_to_digit(unsigned int decimal) {
// this turns char into actual workable numbers
if (decimal == 0){
    return '0';
}
if (decimal == 1){
    return '1';
}
if (decimal == 2){
    return '2';
}
if (decimal == 3){
    return '3';
}
if (decimal == 4){
    return '4';
}
if (decimal == 5){
    return '5';
}
if (decimal == 6){
    return '6';
}
if (decimal == 7){
    return '7';
}
if (decimal == 8){
    return '8';
}
if (decimal == 9){
    return '9';
}
else{
    throw std::invalid_argument("wrong character");
}

}



string trim_leading_zeros(string num) {
    // TODO(student): implement
int zeroCounter = 0; //  this is going to check to see if all inputed numbers are 0
int stringSize = 0;
bool NegativeKeeper = false;
stringSize = num.size();

// if (num[0]!= '-'|| num[0]!='0'){
//     return num;
// }


if(num[0]=='-')
{
    num.erase(0,1);
    if(num[0]=='0'){
        stringSize--; // this accounts for erased digit
    }
    NegativeKeeper = true; // this will add a negative for all bad variables
}
while (num.at(0)=='0')
{
    zeroCounter++;
    if (zeroCounter == stringSize){ // this cathes number is 0 0 0 0 
        num= "0";
        return num; // the string only has zeros thus return 1;
    }
    num = num.substr(1);
}


if(NegativeKeeper==true){
    num.insert(0,"-");
}

return num;


}

string add(string lhs, string rhs) {
    // TODO(student): implement

int sizeLHS =0;
int sizeRHS = 0;
bool GateCarry = true;
bool NegativeSign = false;
string FinalAnswer = "";
string CarryNumberFirstSpot = "";
string CarryNumberSecondSpot = "";
int StorageLhs=0;
int StorageRhs=0;
int StorageUnit =0; //this will be used for passing addition
int carry1 = 0;
 //  this will be used for passing carry 10s
int NumberOfDigits = 0;
int MultL = 1; // this will determine if there needs to be adition or subtration
int MultR = 1;
// first we trim the numbers down

lhs = trim_leading_zeros(lhs);
rhs = trim_leading_zeros(rhs);

// I am going to compare btwn the sizes of the lengths so I need to check and remove -


if (lhs[0] == '-' ){
    MultL = -1;
    lhs.erase(0,1); // remove the leading -
}
if (rhs[0] == '-' ){
    MultR = -1;
    rhs.erase(0,1); // remove the leading -
}
if (rhs[0] == '-' && lhs[0] == '-' ){
    lhs.erase(0,1);
    rhs.erase(0,1);
    MultR = -1;
    MultL = -1; //  remove both leading - and then set the number back to add
}





sizeLHS = lhs.size(); // Now I want to be able to find which number is bigger and then sort it into repsetive if then statements
sizeRHS = rhs.size();








while (sizeLHS !=sizeRHS ){

if(sizeLHS > sizeRHS){
    rhs = rhs.insert(0,"0");
    sizeRHS = rhs.size();
}
if(sizeRHS > sizeLHS){
    lhs = lhs.insert(0,"0");
    sizeLHS = lhs.size(); 
}

}


NumberOfDigits = sizeRHS;
int VariablePlace = NumberOfDigits - 1; // trying to get it to work from backward to forward
int counter = 0;
for (int i = NumberOfDigits; i>0;i--){
    counter = 0;
if (VariablePlace < 0 ) //  stopping invalid arguement
{
    return FinalAnswer;
}    
    StorageLhs = digit_to_decimal(lhs[VariablePlace]);
    StorageRhs = digit_to_decimal(rhs[VariablePlace]);
    VariablePlace--; //decrease the variable place by 1
//Look ahead for storageLHS and RHS if it is

    StorageUnit = MultL * StorageLhs + 1*MultR*StorageRhs + carry1;
    carry1 = 0; //reset value
    if (StorageUnit <0){ // catching negatives
        StorageUnit = abs(StorageUnit);
        NegativeSign = true;
    }
    if(StorageUnit > 9){
        if(i==1){ //  the last value of i and storage is >
        StorageUnit-=10;
        CarryNumberFirstSpot = decimal_to_digit(StorageUnit);
        FinalAnswer.insert(counter,CarryNumberFirstSpot);
  //      counter++;
        carry1 = 1;

        CarryNumberFirstSpot = decimal_to_digit(carry1);
        FinalAnswer.insert(0,CarryNumberFirstSpot);
        if(NegativeSign){
            carry1 = -1;// if theres a negative sign add a negative 1 must be after its printed to Final Answer or this will cause an error

        }

 //       counter++;
        GateCarry = false; 
        }
    // now if its not the last value of i just a normal carry
    else if(i!=1){
        StorageUnit-=10;
        CarryNumberFirstSpot = decimal_to_digit(StorageUnit); //print remainer carry 1
        FinalAnswer.insert(counter,CarryNumberFirstSpot);
       // counter++;
       
        carry1 = 1;
        if (NegativeSign){
            carry1 = -1;
        }

    }
    GateCarry = false; //close the gate stop double printing


    }


    if(i == 1 && GateCarry){ // I only want this running if carry has not activated and i==1 (last print)
        CarryNumberFirstSpot = decimal_to_digit(StorageUnit);
        FinalAnswer.insert(counter,CarryNumberFirstSpot);
    //    counter++;
        // CarryNumberFirstSpot = decimal_to_digit(carry1);
        // FinalAnswer.insert(counter,CarryNumberFirstSpot);
        // counter++;
        GateCarry = false; // dont print out the active digit
  //      FinalAnswer = trim_leading_zeros(FinalAnswer);
        if (NegativeSign){
            FinalAnswer.insert(0,"-");
        }
        return FinalAnswer;

    }
if (GateCarry){
    CarryNumberFirstSpot = decimal_to_digit(StorageUnit);

    FinalAnswer.insert(counter,CarryNumberFirstSpot);
   // counter++;
    

    }
GateCarry = true; //reset carry value
}
FinalAnswer = trim_leading_zeros(FinalAnswer);

if (NegativeSign){ // check for negative sign
            FinalAnswer.insert(0,"-");
        }


    return FinalAnswer;
}

string multiply(string lhs, string rhs) {
    // TODO(student): implement
int sizeLHS =0;
int sizeRHS = 0;
 bool GateCarry = true;
bool NegativeSign = false;
string FinalAnswer = "";
string CarryNumberFirstSpot = "";
string CarryNumberSecondSpot = "";

int StorageRhs=0;
int StorageUnit =0; //this will be used for passing addition
int carry1 = 0;




 //  this will be used for passing carry 10s
int NumberOfDigits = 0;
int MultL = 1; // this will determine if there needs to be adition or subtration
int MultR = 1;
MultL = MultR;
MultR = MultL;

// first we trim the numbers down

lhs = trim_leading_zeros(lhs);
rhs = trim_leading_zeros(rhs);

// I am going to compare btwn the sizes of the lengths so I need to check and remove -
if (rhs[0] == '-' && lhs[0] == '-' ){
    lhs.erase(0,1);
    rhs.erase(0,1);
    NegativeSign = false;
    MultR = -1;
    MultL = -1; //  remove both leading - and then set the number back to add
}

if (lhs[0] == '-' ){
    MultL = -1;
    NegativeSign = true;
    lhs.erase(0,1); // remove the leading -
}
if (rhs[0] == '-' ){
    MultR = -1;
    NegativeSign = true;
    rhs.erase(0,1); // remove the leading -
}






sizeLHS = lhs.size(); // Now I want to be able to find which number is bigger and then sort it into repsetive if then statements
sizeRHS = rhs.size();



if (sizeLHS < sizeRHS){
    //RHS = LHS
    CarryNumberFirstSpot = lhs;
    lhs = rhs;
    rhs = CarryNumberFirstSpot;

}
CarryNumberFirstSpot = "";



while (sizeLHS !=sizeRHS ){

if(sizeLHS > sizeRHS){ // setting sizes equal
    rhs = rhs.insert(0,"0");
    sizeRHS = rhs.size();
}
if(sizeRHS > sizeLHS){
    lhs = lhs.insert(0,"0");
    sizeLHS = lhs.size(); 
}

}

NumberOfDigits = rhs.size();

int VariablePlace = NumberOfDigits - 1; // trying to get it to work from backward to forward

int VariableRhs = NumberOfDigits -1;
//int StorageCompiler = 0; //takes all the values in storage unit


int Output= 0;

int Multiplier = 1;
int StorageLhs = 0;

string StorageUnitString ="";
string StorageUnitString2 = "";
string StorageUnitAdd = "";
string AddZeros = "";
int counterGateAdder = 0;
bool GateKeeperNoRereun = false;

// if (sizeRHS == 1 && sizeLHS==1 && rhs.at(0)*lhs.at(0))
// {
    

for (int a = NumberOfDigits; a>=0;a--){ //FIX ME
     // this will be controling the left hand side
// the idea up here will be run another loop that adds the ones, tens and hundreds place of Final Answer

if(a != NumberOfDigits-1 && a != NumberOfDigits){
    
     // dont run zeroth time OR the first time
    if(counterGateAdder > 0){
        StorageUnitString2 = StorageUnitString;
        StorageUnitAdd = add(StorageUnitAdd,StorageUnitString2);
        counterGateAdder++;
 

    }
    if(counterGateAdder == 0){
        StorageUnitAdd = add(StorageUnitString2,StorageUnitString);
        counterGateAdder++;

    }


    GateKeeperNoRereun = true;
}

if (VariableRhs >= 0){
StorageUnitString2 = StorageUnitString;
StorageRhs = digit_to_decimal(rhs[VariableRhs]);
VariableRhs--;
VariablePlace = NumberOfDigits -1; //this needs to rerun


StorageUnitString = "";


if(a !=NumberOfDigits ){
AddZeros += "0";
StorageUnitString +=AddZeros; // clearing since it will be redeclared as the tens place
}

carry1 = 0;

for(int i =NumberOfDigits;i>0;i-- ){
    

    StorageLhs = digit_to_decimal(lhs[VariablePlace]);

    VariablePlace--; //decrease the variable place by 1

    
    StorageUnit = Multiplier*(StorageLhs*StorageRhs+carry1);

    
     // set back to equal 0
    carry1 = StorageUnit/ (10) %10;

// this is the hundreds place
    Output=StorageUnit %10; // this is the ones place? // now it will be tens
 // StorageUnit /= (Multiplier); // the current place

if ( i == 1){ // last time multipling the place your in
    if(a == 1){// true last time running

        CarryNumberFirstSpot = decimal_to_digit(Output);
        StorageUnitString.insert(0, CarryNumberFirstSpot);
        CarryNumberFirstSpot = decimal_to_digit(carry1);
        StorageUnitString.insert(0, CarryNumberFirstSpot);

    }
    else if (a!=1){// last time multipling the place your in
    CarryNumberFirstSpot = decimal_to_digit(Output);
    StorageUnitString.insert(0, CarryNumberFirstSpot);
    CarryNumberFirstSpot = decimal_to_digit(carry1);
    StorageUnitString.insert(0, CarryNumberFirstSpot);}
    GateCarry = false;

}
if (GateCarry){
    CarryNumberFirstSpot = decimal_to_digit(Output);
    StorageUnitString.insert(0, CarryNumberFirstSpot);

}
GateCarry =true;//reset
    
}
}
}
if(!(GateKeeperNoRereun)){ // handles if theres a 1s placer


FinalAnswer = StorageUnitString;
FinalAnswer = trim_leading_zeros(FinalAnswer);
if (NegativeSign)
{
    FinalAnswer.insert(0,"-");
    return FinalAnswer;
}
return FinalAnswer;
}

if (FinalAnswer == "")
{
    FinalAnswer = StorageUnitString;
}
// if(StorageUnitString != ""){ // check fi there is one more additon to do
// StorageUnitString2 = StorageUnitString;
// StorageUnitAdd = add(StorageUnitAdd,StorageUnitString2);}




FinalAnswer = StorageUnitAdd;
FinalAnswer = trim_leading_zeros(FinalAnswer);


if (NegativeSign){
    FinalAnswer.insert(0,"-");
    return FinalAnswer;
}
else if (!(NegativeSign)){
    FinalAnswer = FinalAnswer;
}
    
    
    


return FinalAnswer;
    }
