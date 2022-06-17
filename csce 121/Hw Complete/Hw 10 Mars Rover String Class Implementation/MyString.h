// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
class MyString {

   public:
      MyString();
      MyString (const MyString& str); // copy! // USE . INSTEAD OF ARROW
      MyString (const char* s); // from C-string
      // constructors

      ~MyString();

      // destructor

      void resize(size_t n);
      // resize  
      // capacity is used in here

      void clear();

      size_t length() const;
      // this calls to size

      const char* data() const noexcept;
      // this is the actual data return /0 at the end

      bool empty() const;

      const char& front() const;
      // check  the front character 
      const char& at(size_t  pos) const;
      // Second oneonly: const char& at (size_t pos) const;
      // Remember to do bounds checking and throw the exception if out of bounds

      friend std::ostream& operator<<(std::ostream& out, const MyString& str);

      // edit the data in the middle  of the string

      MyString& operator=  (const MyString& str);
      MyString& operator+= (const MyString& str);
      size_t find ( const MyString& str, size_t post = 0) const;
      // return -1 if not found
      size_t capacity() const;
      // appart of resize 
      size_t size() const;
      // length calls here 
      MyString *copy() const;
      bool friend operator== (const MyString& lhs, const MyString& rhs) noexcept;
      MyString friend operator+ (const MyString& lhs, const MyString& rhs);
      private:

         size_t StringLength;
         size_t Capacity;
         char *  ActualChar;
         
      
};
#endif