#include <iostream>

using std::cout, std::endl;

int main() {

  int w = 0;
  int x = 0;
  int y = 0;
  int z = 0;

  bool breakNow = false;
  for(w = 0; !breakNow; w++)
  {
    for(x = 0; !breakNow; x++)
    {
      for(y = 0; !breakNow; y++)
      {
        for(z = 0; !breakNow; z++)
        {
         breakNow = ( x && 
         w ) &&  ( y && 
         !w ) &&  !(bool)z && 
         !(bool)y || (bool)z;
        }
      }
    }
  }

cout << "w x y z" << w << x << y << z;

return 0;
}