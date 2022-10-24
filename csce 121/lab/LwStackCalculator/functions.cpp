#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack

   // if the stack is full then
  if(stack.capacity <= stack.count)
  {

    // now I know I need to resize the array, create a resized array

    int* arrDELETEME = new int[stack.capacity*2];
    // now copy the elements over
    for (int i =0; i<stack.count;i++)
    {
      arrDELETEME[i] = stack.numbers[i];
      
    }
      delete[] stack.numbers;
    stack.numbers = arrDELETEME;
    stack.capacity*=2;
    // stop a seg fault
    // stack.capacity *=2;

  }

    // cout << stack.count << "THIS IS THE STACK COUNT"<< endl;
    stack.numbers[stack.count] = number;
    stack.count++;
  
  
  // INFO_STRUCT(stack);
  // INFO(number);
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  INFO_STRUCT(stack);
  // return the nnumber they want


  if (stack.count == 0)
  {
    return INT32_MAX;

  }
  stack.count--;
  return stack.numbers[stack.count];
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO (optional): implement peek function for stack
  //INFO_STRUCT(stack);

  return stack.numbers[stack.count-1];
}
