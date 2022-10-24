#include <iostream>
using std::cout;
#include <string>
std::string caesarCipher(std::string s, int k) 
{
     std::string encrypt = "";
     string gu=s;
     for(int index = 0; index < s.size(); index++)
     {
         if(k>=s.size())
         {
             k =0;
         }
         if(s[k]!='-')
         {
             char lookatme = s[k];
             encrypt[index] += s[k];
             k++;
         }
     }
     return encrypt;
}



int main(){
std::string l = "abcdefghijklmnopqrstuvwxyz";
int k = 1;
std::string holder = caesarCipher(l,k);

cout << holder << std::endl;
}