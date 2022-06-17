/*
 * CellData.h
 *
 *  Created on: Nov 9, 2021
 *      Author: student
 */

#include <iostream>
#include <string>
#include "CellData.h"

using std::cout;
using std::string;
using std::endl;

CellData::CellData() : id("-1"), fov(-1), volume(-1) , center_x(-1), center_y(-1), min_x(-1), min_y(-1), max_x(-1), max_y(-1) //initialize everything
{
}

CellData::CellData(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y) : id(id), fov(fov), volume(volume) , center_x(center_x), center_y(center_y), min_x(min_x), min_y(min_y), max_x(max_x), max_y(max_y) //initialize everything
{

}


CellData::~CellData() {} // You should not need to implement this
/*
An overloaded operator< for the class: bool operator<(const CellData&
b);
▪First ordered by FOV number
▪Then by id
*/
bool CellData::operator<(const CellData& b) {
	// Implement this
    // comparing this-> to b

    if(this->fov < b.fov)
    {
        return true;
    }
    else if(this->fov > b.fov)
    {
        return false;
    }
    if((this->id) < (b.id))
    {
        return true;
    }
    else
    {
        return false;
    }
        
    

}
/*

An overloaded operator== for the class: bool operator==(const
CellData& b);
▪returns true if and only if two objects are memberwise identical

    std::string id;
    int fov;
    double volume;
    double center_x;
    double center_y;
    double min_x;
    double min_y;
    double max_x;
    double max_y;

*/

bool CellData::operator==(const CellData& b)
{
    if(((this->id) == (b.id))||(this->fov == b.fov) || (this->volume == b.volume) || (this->center_x == b.center_x))
    {
        cout << " the size of id are equal line 64 celldata " << std::endl;
        return true;
    }
    else
    {
        return false;
    }
    if((this->center_y == b.center_y)||(this->min_x == b.min_x)||(this->min_y == b.min_y) || (this->max_x == b.max_x)|| (this->max_y == b.max_y))
    {
        cout << " Something is true " << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}

