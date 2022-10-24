#include <iostream>
using namespace std;







void swap(int &x, int &y) { 
    int z;
    // needs to be void because  I dont want the function to return anything
    // no & we swap copies this is the new method use &
    z=x;
    x=y;
    y=z;

}
// this is the correct way

void swap2(int *x, int *y) { // the star means I want where x is stored NOT the copy
    int z;
    z=*x;
    *x =*y;
    *y=z;


}


int main() { // I can pass these function copys all I want but it wont print or swap. I need to tell c++ where the values are!
    int x =3;
    int y =4;
    //swap(x,y);
    swap2(&x,&y); //use & to say this value will be reacessed
    cout << x << endl << y<<endl;



}