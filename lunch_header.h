#ifndef LUNCH_HEADER_H
#define LUNCH_HEADER_H

// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 4/17/2020
// File: school_header.h
// Purpose: Function and class prototypes for the lunch class

#include <iostream>
using namespace std;

// The Lunch() is a constructor for the lunch class
// Pre: None
// Post: Creates a lunch class defaulted to (-1, -1) with the display
// character 'L'

// The random_start() generates a random starting position for the lunch
// Pre: A school
// Post: Assigns a starting value for the lunch

// The place_lun() places the lunch into the school grid
// Pre: A school, a row value within the school size (or the default value),
// and a col value within the school size (or the default value)
// Post: Places the lunch character into the grid

// The rand_walk() takes in a school and generates a random walk direction for
// the lunch
// Pre: A school
// Post: Moves the lunch character one space in an open direction

class Lunch
{
  private:
    int m_lun_row_coord;
    int m_lun_col_coord;
    char m_lunch_char;
  public:
    Lunch();
    void random_start(School & sch);
    void place_lun(School & sch, int row = -1, int col = -1);
    void rand_move(School & sch);
};

#endif