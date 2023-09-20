#ifndef JANITOR_HEADER_H
#define JANITOR_HEADER_H

// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 4/17/2020
// File: school_header.h
// Purpose: Function and class prototypes for the janitor class

#include <iostream>
using namespace std;

// The Janitor() is a constructor that builds a janitor object
// Pre: A valid name and representation for a janitor (otherwise, the
// the default values of "Janitor" and 'J')
// Post: Assigns each private member variable of the Janitor class with an
// assignment based on the type

// The the place_jan() takes in a janitor and its coordinates and places it
// in the school
// Pre: A school, a positive row value (within the size bounds), and a 
// positive column value
// Post: Places the janitor representation character in the school grid

// The rand_walk() takes in a school and generates a random walk direction for
// the janitor
// Pre: A school
// Post: Moves the janitor character one space in an open direction

// The operator<<() overloads the insertion operator for a janitor
// Pre: A valid (not reserved word) output, and a janitor object
// Post: Outputs the statistics of a janitor object


class Janitor
{
  private:
    double m_bac;
    int m_bruises;
    int m_jan_row_coord;
    int m_jan_col_coord;
    string m_jan_name;
    char m_jan_char;
    bool m_sober;
    bool m_alive;
  public:
    Janitor(string name = "Janitor", char janitor = 'J');
    void place_jan(School & sch, int row = -1, int col = -1);
    void rand_walk(School & sch);
    friend ostream & operator<<(ostream & output, const Janitor & jan);
};

#endif
