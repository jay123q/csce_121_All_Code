#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;
// void PRINTtable(int PrintME,int col)
// {
//   cout << "TABLE\n"; 
//   for(int colPlace = col ;colPlace<height;colPlace++)
//   { // this counts by column
    
//     for(int rowPlace = row; rowPlace < width; rowPlace++)
//     { // perform calculations in here
//       cout << PrintME << " ";
//     }
//     cout << endl;
//   }
// }

// TODO Write this function
int energy(const Pixel *const*image, int col, int row, int width, int height)
{

  int PixelDataX=0;
  int PixelDataY=0;
  int PixelData = 0;

  int colPlace = col; // hardcoding in
  //int a = 0;
  // cout << "Enter a column" <<endl;
  // cin >> colPlace;
  // cout << "Enter a row" << endl;
  // cin >> a;
  // row = a;


     int rowPlaceR= (row+1);
     int rowPlaceL = (row-1);
     if (rowPlaceL < 0)
     {
       rowPlaceL = height-1;
     }

     if (rowPlaceR >= height)
     { // if it is out of bounds (on the right boarder start at)
       rowPlaceR = 0;
     }

    int TCheckR = image[colPlace][rowPlaceL].r;
    int TCheckB = image[colPlace][rowPlaceL].b;
    int TCheckG = image[colPlace][rowPlaceL].g;
    int BCheckR = image[colPlace][rowPlaceR].r;
    int BCheckG = image[colPlace][rowPlaceR].g;
    int BCheckB = image[colPlace][rowPlaceR].b;

    //  cout <<"Top variables " <<TCheckR<<", " <<TCheckG <<", "<< TCheckB <<endl;
    //  cout <<"Bottom variables " <<BCheckR<< ", "<<BCheckG <<", "<< BCheckB <<endl;


     int TandBR = fabs(TCheckR - BCheckR);
     int TandBB = fabs(TCheckB - BCheckB);
     int TandBG = fabs(TCheckG - BCheckG);
     PixelDataY = pow(TandBR,2) + pow(TandBG,2) +pow(TandBB,2);
    
     //energy
     // X axis
     int TcolPlace = colPlace+1;
     int BcolPlace = colPlace -1;
     if (TcolPlace >= width)
     {
       TcolPlace = 0;
     }
     if(BcolPlace < 0 )
     {
       BcolPlace = width-1;
     }



    //Change in X

     int LeftCheckR = image[BcolPlace][row].r;
     int LeftCheckB = image[BcolPlace][row].b;
     int LeftCheckG = image[BcolPlace][row].g;
     int RightCheckR = image[TcolPlace][row].r;
     int RightCheckB = image[TcolPlace][row].b;
     int RightCheckG = image[TcolPlace][row].g;
 //    cout <<"left variables " <<LeftCheckR<<", " <<LeftCheckG <<", "<< LeftCheckB <<endl;
    //  cout <<"right variables " <<RightCheckR<< ", "<<RightCheckG <<", "<< RightCheckB <<endl;

    int Redx = fabs(LeftCheckR - RightCheckR);
    int Bluex = fabs(LeftCheckB - RightCheckB);
    int Greenx = fabs(LeftCheckG - RightCheckG);
     PixelDataX = pow(Redx,2) + pow(Bluex,2) + pow(Greenx,2);

     PixelData = PixelDataX + PixelDataY;

  return PixelData;
}

// TODO Write this function
int getVerticalSeam(const Pixel *const*image, int start_col, int width, int height, int* seam)
{ 
  // start @ zero row
   int energyTotal = energy(image,start_col,0,width,height);
   int energyStart_Col = 0;
   int energyStart_ColShiftLeft = 0;
   int energyStart_ColShiftRight = 0;

   seam[0]= start_col;

  for(int ThisRow = 1; ThisRow < height ; ThisRow++)
  {
    int start_colShiftLeft = start_col -1;
    int start_colShiftRight = start_col +1;
    if (start_colShiftLeft < 0)
    { // if these are out of bounds then run just normal start_col
      start_colShiftLeft = start_col;
    }
    if (start_colShiftRight >= width)
    {
      start_colShiftRight =start_col;
    }

   // calculate the energy of a shift to the right and to the left
    energyStart_Col = energy(image,start_col,ThisRow,width,height);

    energyStart_ColShiftLeft = energy(image,start_colShiftLeft,ThisRow,width,height);

    energyStart_ColShiftRight = energy(image,start_colShiftRight,ThisRow,width,height);

   // picking the easiest path
   // the equals too is used to catch if the values are the same because you set the start_col to equal the right and left shift
   if (energyStart_Col <= energyStart_ColShiftLeft && energyStart_Col <= energyStart_ColShiftRight)

   { // the row right underneath is picekd
     seam[ThisRow] = start_col;
     energyTotal += energyStart_Col;
     start_col = start_col;


   }
// if left and right tie pick the left most value
// left is least
   if (energyStart_ColShiftLeft < energyStart_Col && energyStart_ColShiftLeft < energyStart_ColShiftRight)

   { // the row to the left is picked
     seam[ThisRow] = start_colShiftLeft;
     energyTotal += energyStart_ColShiftLeft; 
     // start_shift
     start_col = start_colShiftLeft;
   }
// right is least
   if (energyStart_ColShiftRight < energyStart_Col && energyStart_ColShiftRight <= energyStart_ColShiftLeft)

   { //  the row to the right is picked
     seam[ThisRow] = start_colShiftRight;
     energyTotal += energyStart_ColShiftRight;// new start is this
     start_col = start_colShiftRight;
   }    

  }
//  cout<<"The Energy Total is "<<energyTotal;
   return energyTotal;

//}
}

// TODO Write this function
void removeVerticalSeam(Pixel **image, int& width, int height, int *verticalSeam)
{
   // increment width down
      width -- ;
      for (int ThisRow = 0 ; ThisRow < height ; ThisRow++)
      {
        // this is calling the column in get verticalseam and running for each column in verticalseam
        for ( int deleteME = verticalSeam[ThisRow];deleteME<width;deleteME++)
        {
         //deleteME is the column and redeclare the old column over the current
         image[deleteME][ThisRow] =  image[deleteME+1][ThisRow];
        }
        //now the image file has been edited
        // on the seam delete this by incrementing to the left
      }
     // incredment width down

}

// TODO Write this function for extra credit
int getHorizontalSeam(const Pixel *const*image, int start_row, int width, int height, int* seam)
{
  // start @ zero row
   int energyTotal = energy(image,0,start_row,width,height);
   int energyStart_Col = 0;
   int energyStart_ColShiftLeft = 0;
   int energyStart_ColShiftRight = 0;

   seam[0]= start_row;

  for(int ThisCol = 1; ThisCol < height ; ThisCol++)
  {
    int start_colShiftLeft = start_row -1;
    int start_colShiftRight = start_row +1;
    if (start_colShiftLeft < 0)
    { // if these are out of bounds then run just normal start_col
      start_colShiftLeft = start_row;
    }
    if (start_colShiftRight >= width)
    {
      start_colShiftRight =start_row;
    }

   // calculate the energy of a shift to the right and to the left
    energyStart_Col = energy(image,ThisCol,start_row,width,height);

    energyStart_ColShiftLeft = energy(image,ThisCol,start_colShiftLeft,width,height);

    energyStart_ColShiftRight = energy(image,ThisCol,start_colShiftRight,width,height);

   // picking the easiest path
   // the equals too is used to catch if the values are the same because you set the start_col to equal the right and left shift
   if (energyStart_Col <= energyStart_ColShiftLeft && energyStart_Col <= energyStart_ColShiftRight)

   { // the row right underneath is picekd
     seam[ThisCol] = start_row;
     energyTotal += energyStart_Col;
     start_row = start_row;


   }
// if left and right tie pick the left most value
// left is least
   if (energyStart_ColShiftLeft < energyStart_Col && energyStart_ColShiftLeft < energyStart_ColShiftRight)

   { // the row to the left is picked
     seam[ThisCol] = start_colShiftLeft;
     energyTotal += energyStart_ColShiftLeft; 
     // start_shift
     start_row = start_colShiftLeft;
   }
// right is least
   if (energyStart_ColShiftRight < energyStart_Col && energyStart_ColShiftRight <= energyStart_ColShiftLeft)

   { //  the row to the right is picked
     seam[ThisCol] = start_colShiftRight;
     energyTotal += energyStart_ColShiftRight;// new start is this
     start_row = start_colShiftRight;
   }    

  }
//  cout<<"The Energy Total is "<<energyTotal;
   return energyTotal;
  
}

// TODO Write this function for extra credit
void removeHorizontalSeam(Pixel **image, int width, int& height, int *horizontalSeam)
{
     // increment height down
      height -- ;
      for (int ThisCol = 0 ; ThisCol < width ; ThisCol++)
      {
        // this is calling the column in get verticalseam and running for each column in verticalseam
        for ( int deleteME = horizontalSeam[ThisCol];deleteME<height;deleteME++)
        {
         //deleteME is the column and redeclare the old column over the current
         image[deleteME][ThisCol] =  image[deleteME+1][ThisCol];
        }
        //now the image file has been edited
        // on the seam delete this by incrementing to the left
      }
     // incredment width down
}

int *findMinVerticalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first col (index 0)
  int *minSeam = new int[height]{0};
  int minDist = getVerticalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[height]{0};
  int candidateDistance = -1; // invalid distance

  // start at second col (index 1) since we initialized with first col (index 0)
  for (int col = 1; col < width; ++col)
  {
    candidateDistance = getVerticalSeam(image, col, width, height, candidateSeam);

    if (candidateDistance < minDist)
    { // new min
      //  swap min & candidate
      minDist = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

  // clean up 
  delete [] candidateSeam;

  return minSeam;
}

int *findMinHorizontalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first row (index 0)
  int *minSeam = new int[width]{0};
  int minDistance = getHorizontalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[width]{0};
  int candidateDistance = -1; // invalid distance

  // start at second row (index 1) since we initialized with first row (index 0)
  for (int row = 1; row < height; ++row)
  {
    candidateDistance = getHorizontalSeam(image, row, width, height, candidateSeam);

    if (candidateDistance < minDistance)
    { // new minimum
      //  swap min and candidate seams
      minDistance = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

    // clean up 
  delete [] candidateSeam;

  return minSeam;
}

Pixel **createImage(int width, int height)
{
  cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel **image = new Pixel *[width] {}; // initializes to nullptr

  for (int col = 0; col < width; ++col)
  { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    try
    {
      image[col] = new Pixel[height];
    }
    catch (std::bad_alloc &e)
    {
      // clean up already allocated arrays
      for (int i = 0; i < col; ++i)
      {
        delete[] image[i];
      }
      delete[] image;
      // rethrow
      throw e;
    }
  }

  // initialize cells
  // cout << "Initializing cells..." << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = {0, 0, 0};
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel **image, int width)
{
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i = 0; i < width; ++i)
  {
    delete[] image[i];
  }
  delete[] image;
  image = nullptr;
  cout << "End deleteImage..." << endl;
}

bool isValidColor(int colorVal)
{
  if (colorVal < 0 || colorVal > 255)
  {
    return false;
  }
  return true;
}

Pixel ** loadImage(string filename, int &width, int &height)
{
  cout << "Start loadImage..." << endl;
  // remove
  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    throw std::invalid_argument("Failed to open input file (" + filename + ")");
  }

  string type;
  ifs >> type; // should be P3
  if (toupper(type.at(0)) != 'P' || type.at(1) != '3')
  {
    throw std::domain_error("Not PPM type P3 (" + type + ")");
  }
  ifs >> width;
  // cout << "w and h: " << w << " " << h << endl;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for width");
  }
  if (width <= 0)
  {
    ostringstream oss;
    oss << "Width in file must be greater than 0 (" << width << ")";
    throw std::domain_error(oss.str());
  }

  ifs >> height;
  if (ifs.fail())
  {
    cout << "Read non-integer value for height" << endl;
  }
  if (height <= 0)
  {
    ostringstream oss;
    oss << "Height in file must be greater than 0 (" << height << ")";
    throw std::domain_error(oss.str());
  }

  int colorMax = 0;
  ifs >> colorMax;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for max color value");
  }
  if (colorMax != 255)
  {
    ostringstream oss;
    oss << "Max color value must be 255 (" << colorMax << ")";
    throw std::domain_error(oss.str());
  }

  // load image throws exceptions but we will let them pass through
  Pixel **image = createImage(width, height);

  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "Pixel(" << col << ", " << row << ")" << endl;
      ifs >> image[col][row].r;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for red");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for red (" << image[col][row].r << ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].g;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for green");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for green (" << image[col][row].r + ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].b;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for blue");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for blue (" << image[col][row].r + ")";
        throw std::domain_error(oss.str());
      }
    }
  }
  cout << "End loadImage..." << endl;
  return image;
}

void outputImage(string filename, const Pixel *const *image, int width, int height)
{
  cout << "Start outputImage..." << endl;
  // remove code
  // declare/define and open output file stream with filename
  ofstream ofs(filename);
  // ensure file is open
  if (!ofs.is_open())
  {
    throw std::invalid_argument("Error: failed to open output file - " + filename);
  }
  ofs << "P3" << endl;
  ofs << width << " " << height << endl;
  ofs << 255 << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      ofs << image[col][row].r << " ";
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
    ofs << endl;
  }
  cout << "End outputImage..." << endl;
}