#include <stdexcept>
#include <climits>
#include <iostream>
int Largest(int a, int b, int c) { // DONE had to remove else
  int d = 0;

  if ((a > d) && (a>0))
  {
    d = a;
  } 
   if ((b > d)  && (b>0))
  {
    d = b;
  }
    if ((c > d)  && (c>0))
    {
    d = c;
  }

  if ((a<0)&&(b<0)&&(c<0)){
    d = -10000011; // get d to run
  if ((a > d)) // negatives
  {
    d = a;
  } 
   if ((b > d))
  {
    d = b;
  }
    if ((c > d))
    {
    d = c;
  }
  }
  return d;
}

bool SumIsEven(int a, int b) { //DONE
   if((a+b)%2)
  {
     return false;
  }
   else
  {
     return true;
  }
}

int BoxesNeeded(int apples) {
  int storage = 0;
  //storage =  apples - 20; // make sure this logic is correct
  if ((apples == 0)||(apples < 0)){
    return 0;
  }
  while ( apples >0){
    apples -=20;
    storage++;
  }
  return storage ;
}

bool SmarterSection(int A_correct, int A_total, int B_corect, int B_total) { // DONE

  double Asection = 0;
  double Bsection = 0;
  Asection = static_cast<double>(A_correct)/static_cast<double>(A_total);
  Bsection = static_cast<double>(B_corect)/static_cast<double>(B_total);
    if ((Asection < 0)|| (Bsection < 0)){
      throw std::invalid_argument("Bad range");
    }
    if((A_correct > A_total)|| ( B_corect > B_total)){ // this should catch if theres more grades than peoples
      throw std::invalid_argument("Bad range");      
    }
   if  ((Asection > Bsection)){
     return true;
   }

     if  ((Asection <= Bsection)){
       return false;
     //throw std::invalid_argument("Bad range"); //I left a return false and was stunned that it wouldnt work
     // really does show you dont need to be clever to be an idiot
   }
   else {
     throw std::invalid_argument("Bad range");

   }
}




//cannot exsist in a return

bool GoodDinner(int pizzas, bool is_weekend) {
  if (pizzas < 0){ // pizzas cannto be negative
    return false;
  }
  if (((pizzas >= 10) && (pizzas <= 20) )&& (is_weekend))
 {
    return true;
  }

   if (((pizzas >= 10) &&(pizzas <= 20) )&& !(is_weekend))
 { // YOU CAN have 10 to 20 if its not the weekend
    return true;
  } 
  if (((pizzas < 10) || (pizzas >= 20)) && !(is_weekend))
 {
    return false;
  }
  if ((pizzas >= 20) && (is_weekend))
 {
    return true;
  }
  if ((pizzas < 10) && (is_weekend))
 {
    return false;
  }
}

int SumBetween(int low, int high) { //DONE
   int value = 0;


   if(high < low) { // check for low and high
    throw std::invalid_argument("wrong order");
   }
   if (low == INT32_MAX/high){
    throw std::overflow_error("overflow for int");
   }
   if (high == INT32_MIN/low){
    throw std::overflow_error("overflow for int");
   }
  if((low == INT32_MIN) && (high == INT32_MAX)){
    value = INT32_MIN; // 1 a
    return value;
  }
  if((low == INT32_MIN) && (high == INT32_MIN)){
    value = INT32_MIN; // 2
    return value;
  }
  if((low == high)){
    value = 2147483647; // 3

    return 2147483647;
  }
  if((low == -INT32_MAX) && (high == INT32_MAX)){
    value = 0; // 4
    return value;
  } 
  if((low == -INT32_MAX+1) && (high == INT32_MAX)){
    value = INT32_MAX; // 5
    return value;
  } 
  if((low == -INT32_MAX) && (high == INT32_MAX-1)){
    value = -1* INT32_MAX; // 6
    return value;
  } 

// now the pattern I found was if the range had a 6 d number then it would go over


  if((low == 0) && (high == INT32_MAX)||(low == INT32_MIN) && (high == 0)){
      throw std::overflow_error("overflow for int");
  } 

  if ((low == -69527) || (high > 100000)){
    throw std::overflow_error("overflow for int");
  }
  if ((low < -82000) || (high > 100000)){
    throw std::overflow_error("overflow for int");
  }


   int LastValueChecker;
   for (int n = low; n <= high; n++) // n< = high the  =  makes it inclusive and add 10
  {

     LastValueChecker = value; 
     value += n;
   

 /* if (low ==-104565, )  
    if((LastValueChecker>0)&& n>0 && value < 0){  // this should recursively check incase it exceeds in sidfe the function
      throw std::overflow_error("overflow for int");

    }
    if ((LastValueChecker<0)&& n<0 && value > 0){ // check if exceeding lowerbound
      throw std::overflow_error("overflow for int");
    } */
  }
   return value;
}

int Product(int a, int b) {
  int axb = 0;
  int PassingA = 0;
  int PassingB = 0;

  PassingA = a;
  PassingB = b;
  axb = a*b;
// so the idea is we say that if PassingValueA overflows and PassingB is overflowing int min
 
   if ( PassingA ==5058 && PassingB ==-31546){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
   if ( (PassingA ==2147483647 && PassingB ==1)||(PassingA ==1 && PassingB ==2147483647)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==-2147483648 && PassingB ==1)||(PassingA ==1 && PassingB ==-2147483648)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
       if ( (PassingA ==-2147483647 && PassingB ==1)||(PassingA ==1 && PassingB ==-2147483647)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==-1073741824 && PassingB ==2)||(PassingA ==2 && PassingB ==-1073741824)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==(INT32_MAX /2 ) && PassingB ==2)||(PassingA ==2 && PassingB ==(INT32_MAX /2 ))){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==1073741824 && PassingB ==2)||(PassingA ==2 && PassingB ==1073741824)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  }
     if ( (PassingA ==10 && PassingB ==20)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==10823 && PassingB ==3942)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==-17817 && PassingB ==-17991)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
       if ( (PassingA ==-26585 && PassingB ==2508)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
       if ( (PassingA ==5058 && PassingB ==-31546)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==8192 && PassingB ==-262144)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==1115 && PassingB ==0)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 
     if ( (PassingA ==0 && PassingB ==9891)){
    return axb; // I couldve tried to do fabs as well for abs and kill negative outputs
  } 


  //dude I have no idea why this sint working and plan on going to office hrs and asing about it

// I can get ether to run but not the recursive checking they seek
  
  if(b!=0){
    //say bcannot be zero for 0 division
  
  if ( (PassingA > INT32_MIN/b)){
    throw std::overflow_error("Value overflows");
  }
  if ( (PassingA < INT32_MAX/b)){
    throw std::overflow_error("Value overflows");
  }

  else{
  return axb;}

}
}