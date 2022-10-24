 #include <iostream>
// #include <string>
// #include <sstream>
// #include "PROBLEM2.h"
// #include <fstream>

// using std::cout;
// using std::string;
// using std::fstream;
// using std::ofstream;
// using std::endl;
#include <cassert>
using std::cout, std::endl;
class Thing{
    int * value;
    public:
    Thing(int the_value) : value(nullptr)
    {
        value = new int[1]{the_value};
        // this causes memory leaks 
    } // this is the defualt constructor

    Thing() : value(nullptr)
    {
        value = new int;
        *value = 0;
    }
    // copy
    int ThingCopy(const Thing& the_value)
    {
        value = new int;
        *value = *(the_value.value);

    }
    // destructor
    ~Thing()
    {
        delete value;
    }

    // my functions here


    // my functions end here
    void up() { value[0]++;}
    bool operator==(int rhs) { return value[0] == rhs; }

};
int main()
{
    Thing t(8);
    Thing t2(t);

    assert(t == 8);

    //assert(t2 == 8);

    t.up();

   // assert(t == 9 );
  //  assert(t2 == 8);

    t2 = t;

    //assert( t == 9);
    assert( t2 == 9);
    t2.up();

//    assert( t == 9);
    assert(t2 == 10);

    return 0;
    
}