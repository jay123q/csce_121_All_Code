#include <iostream>
#include <string>

#include  <service.html>
#include  <resume.html>
#include  <technicalSkills.html>
#include  <refernces.js>




















std::string caesarCipher(std::string s, int k) 
{
     std::string encrypt = "";
    std::string l = "abcdefghijklmnopqrstuvwxyz";
     for(int index = 0; index < s.size(); index++)
     {
         if(k>=s.size())
         {
             k =0;
         }
         if(s[k]!='-')
         {
             char lookatme = s[k];
             encrypt += s[k];

         }

         k++;
     }
   //  return encrypt;
   // for loop
}



int main()
{
std::string l = "abcdefghijklmnopqrstuvwxyz";
int k = 2;
std::string holder = caesarCipher(l,k);

std::cout << holder << std::endl;
}