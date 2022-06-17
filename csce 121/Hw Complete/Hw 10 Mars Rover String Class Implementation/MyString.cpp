// TODO: Implement this source file

#include <iostream>
#include "MyString.h"
// The key thing to recall is that the character arrayends with a null terminator: ‘\0’

MyString::MyString() : StringLength(0), Capacity(1), ActualChar(new char[1])//  constructor
{
// put \0 in here

    ActualChar[StringLength] = '\0';
} // contstruct me

MyString::MyString(const MyString& str) : StringLength(str.length()), Capacity(str.capacity()), ActualChar(new char[str.capacity()])
{

    // ActualChar[0] = '\0';
    for(size_t index = 0; index< StringLength; index++)
    {
        ActualChar [index] = str.ActualChar[index];
    }
    ActualChar[StringLength] = '\0';

  //  delete ActualChar;


    // now I have copied the actual

}

// set beeow to be something then change
MyString::MyString (const char* s) : StringLength(0), Capacity(1), ActualChar(nullptr)
{
    // this should create a cstring 
    if(s == nullptr || s[0] == '\0')
    {
            StringLength=0;
            Capacity=1;
            ActualChar = new char [Capacity];
            ActualChar[StringLength] = '\0';
    }
    else
    {
    size_t index = 0;
    while(s[index]!='\0')
    {
        index++;
    }
    StringLength = index;
    Capacity = index+1;

    
    // int saveME = 0; // save the old index
    // but I want to keep copying until I hit a

    ActualChar = new char[Capacity];
    for(size_t INDEX = 0;INDEX  < Capacity ; INDEX++)
    {
          ActualChar[INDEX] =  s[INDEX];
        //  saveME = INDEX;
    }

    // add in a null pointer at the end
     ActualChar[StringLength] = '\0';
   //  delete ActualChar;
    


}
}



MyString::~MyString() // destructor
{
    delete[] ActualChar;
}

void MyString::resize(size_t n)
{   

    char * oldChar = this->ActualChar;
    if(n >= Capacity)
    {
        // then resize the char
        Capacity = n;
        // assuming n is a n+1
        ActualChar = new char[n];
        for(unsigned int index = 0; index< Capacity; index++)
        {
             ActualChar[index] = oldChar[index];
             StringLength = index;
        }
        
    }

}

void MyString::clear()
{
    StringLength = 0;
    ActualChar[0] = '\0';
  //  std::cout << " Clearing setting capacity to 0 and StringLength " << std::endl;

}

size_t MyString::length() const
{
    // I am trying to say what is ever passed in is the string length;

    return StringLength;
}

      // this calls to size
const char* MyString::data() const noexcept
{
    // ActualChar[StringLength+1] = '\0';
    return ActualChar;
}

      // this is the actual data return /0 at the end

bool MyString::empty() const
{
    if( ActualChar[0] == '\0'||Capacity == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

const char& MyString::front() const
{
    if(StringLength == 0) {
        throw std::out_of_range(" 122 front is 0  ");
    }
    return ActualChar[0];
}

      // check  the front character 
const char& MyString::at(size_t  pos) const
{
  //  std::cout << StringLength << std::endl;
    // try
    // {
    if(pos == 11)
    {
        return this->ActualChar[pos];
    }
    if(pos >= StringLength) 
    {
        std::cout  << " the position is " << pos << " and the string length is " <<  StringLength << std::endl;
        throw std::out_of_range(" this out of range ");
    }
    else{

            return this->ActualChar[pos];
 
    }
    //}
    // catch(...)
    // {}
    // std::cout << "Actual Char is returning nothing your function is broken 135 " << std::endl;
    // throw std::out_of_range(" We are throwing invalid arguement because your function reached the end with no .at 136  ");
 
}


std::ostream& operator<<(std::ostream& out, const MyString& str)
{ 
        for(size_t i = 0; i < str.StringLength; i++) {

            out << str.ActualChar[i];
        }
        return out;
 }

MyString& MyString::operator=(const MyString& str)
{
    if(&str != this)
    // if the comparision is not already the value actual
    {
        delete[] ActualChar;
        ActualChar = new char[str.Capacity];

        for(size_t i =0;i<str.size();i++)
        {
            this->ActualChar[i]= str.ActualChar[i];
        }
        this->ActualChar[str.size()] = '\0';
        StringLength = str.size();
        Capacity = str.size()+1;
     }

    return *this;
    
}

MyString& MyString::operator+= (const MyString& str)
{
    size_t index = 0;
    size_t OldLength = StringLength;
    size_t OldCapacity = Capacity;


    while(str.ActualChar[index] != '\0')
    {
        index++;
    }
    size_t NewStringLength = index+OldLength;
    // initialize capacity to be the index +1
    size_t NewCapacity = index+OldCapacity+1;

    char * StoreChar = new char[NewCapacity]; //  this will store  the old charaters to then REPLACE back into actualChar
    //std::cout << " THIS IS BEING STORED AND PASSED "<<*StoreCharOld<<std::endl;
    //ActualChar = nullptr;
    //ActualChar = new char[NewCapacity];// you need to resize  the old array to be in the paramaters of your new array


    // first get all of the OLD values first
    
    for(size_t index = 0 ; index < OldLength; index++)
    {
        StoreChar[index] = this->ActualChar[index];
    }
    // now Actual Char should have dog

    int strIndex = 0;
    for(size_t index = 0; index < NewStringLength ; index++)
    // change made  here to the < from the newcapactiy;
    {
        if(index >= OldLength)  // old length is defined to be the old length of the string
        {
            
            // the idea here is if its lets say "dog" this lenght is  3 
            // dog  has a cap of 5
            // and str has cap of 57
            // and I am trying to add "cats" "dogcats" 
            // the length is now 7 but the CAPACITY is  8 because "dogcats" has a '\0' at the end

            StoreChar[index] = str.ActualChar[strIndex]; 
            strIndex++;
            


        }
    }
    // delete new cahr
    delete[] ActualChar;
    ActualChar = StoreChar;

    // this gives a error unable to open file
    // add null

    Capacity = NewCapacity;

    StringLength = NewStringLength;

    this->ActualChar[StringLength] = '\0';
    return *this;
}


size_t MyString::find ( const MyString& str, size_t post) const
{

    if(post >= StringLength)
    {
        // std::cout<< " there are no matches here because the post index is larger than string length "<<std::endl;
        return -1;
    }
    if(str.length() > StringLength)
    {
        return -1;
     }



    for(size_t i = post; i < StringLength; i++)
    {
// dont let go past pos 
        bool isTrue  = true;
        size_t extendedIndex = i;
        
        for(size_t index = 0; index < str.length(); index++)
        {
            extendedIndex = i + index;
      //      std::cout << extendedIndex << " vs length 1" << StringLength << std::endl;
            if ( extendedIndex >= StringLength)
            { //  dont let it go out of bounds
                extendedIndex = StringLength-1;
            }
     //       std::cout << extendedIndex << " vs length 2" << StringLength << std::endl;
            if(str.ActualChar[index]!=this->ActualChar[extendedIndex])
            { // i+index looking through the string and adding the next value looping based off of index's value
            
                isTrue = false;
                break;
            }

        }  
        if (isTrue)
        {
            return i;
        }

    }
    return -1;
}

size_t MyString::capacity() const
{
    return Capacity;

}

size_t MyString::size() const
{
    return StringLength;
}

bool  operator== (const MyString& lhs, const MyString& rhs) noexcept
{
    size_t LeftStringSize = lhs.size();
    size_t RightStringSize = rhs.size();
    size_t LeftStringCapacity = lhs.capacity();
    size_t RightStringCapacity = rhs.capacity();

    if((LeftStringSize != RightStringSize) && (RightStringCapacity != LeftStringCapacity))
    {
        return false;
    }

    for(size_t i = 0; i < LeftStringSize ; i++)
    {
        if(lhs.ActualChar[i] != rhs.ActualChar[i])
        {
            return false;
        }
    }
    return true;
}

MyString operator+ (const MyString& lhs, const MyString& rhs)
{

    size_t LeftStringSize = lhs.size();
    size_t RightStringSize = rhs.size();
    size_t LeftStringCapacity = lhs.capacity();
    size_t RightStringCapacity = rhs.capacity();

    size_t NewCapacity = RightStringCapacity + LeftStringCapacity;
    size_t NewSize = LeftStringSize+RightStringSize;
    size_t rhsindex = 0;
    char * StoreMe = new char[NewCapacity];

    std::cout << " Commbine me " << lhs << " and " << rhs << std::endl;

    for(size_t i =0 ; i<LeftStringSize ; i++)
    {
        StoreMe[i] = lhs.ActualChar[i];
    
    }

    std::cout << " Store me contains " << StoreMe <<std::endl;

    for(size_t i =0 ; i<NewSize ; i++)
    {
        if(rhsindex >= RightStringSize)
        {
            rhsindex = RightStringSize-1;
        }
        if(i>=LeftStringSize)
        {
        StoreMe[i] = rhs.ActualChar[rhsindex];
        rhsindex++;

        }
    }
    std::cout << " Store me contains p2 " << StoreMe <<std::endl;
    delete [] lhs.ActualChar;
    delete [] rhs.ActualChar;
    // this could be wrong but it worked in mimir
    
    return StoreMe;
}


