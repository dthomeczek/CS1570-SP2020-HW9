#ifndef SCHOOL_HEADER_H
#define SCHOOL_HEADER_H

// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 4/17/2020
// File: school_header.h
// Purpose: Function and class prototypes for the school class

#include <iostream>
using namespace std;


// The clear() clears the grid of all variables
// Pre: None
// Post: An empty character array

// The build() builds the walls of the school around the perimeter of the
// school
// Pre: None
// Post: A school with walls on the first and last row and columns

// The School() takes in the school size and runs the clear() and build()
// functions respectively
// Pre: A positive school size less than or equal to 25
// Post: A functional school object is created with the parameters of size

// The getSchoolSize() is used to retrieve the value of m_school_size from 
// the private member variable section of School
// Pre: None
// Post: Returns the size of the school

// The setSchoolSize() assigns the school size with a passed in value from the
// constructor
// Pre: A positive value for size
// Post: Assigns m_school_size with the value passed in from size

// The operator<<() overloads the insertion operator for a school
// Pre: A valid (not reserved word) output, and a school object
// Post: Outputs the grid of a school object

class School
{
  private:
    short m_school_size;
    void clear();
    void build();
  public:
    static const int MAX = 25;
    char m_grid[MAX][MAX];
    School(const short size);
    short getSchoolSize();
    void setSchoolSize(const short size);
    friend ostream & operator<<(ostream & out, const School & sch);
};

#endif