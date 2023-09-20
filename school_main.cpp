// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 4/2/2020
// File: school_main.cpp
// Purpose: Displays a map of a school and locations of a janitor and a lunch

#include <cstdlib>

#include "school_header.h"
#include "lunch_header.h"
#include "janitor_header.h"

int main()
{
  const int SET_SIZE = 9; // School size preset

  // Setup random number generation
  srand(time(NULL));

  // Show key
  cout << "Map Key: " << endl;
  cout << "   + = Wall" << endl;
  cout << "   $ = Window" << endl;
  cout << endl;

  // Prints an empty school
  School school(SET_SIZE);
  cout << "Starting School Map:" << endl;
  cout << school << endl << endl;

  // Prints the janitors and their statistics
  Janitor janitor1("Willie");
  Janitor janitor2("Robert", 'R');
  cout << "Initial Janitors:" << endl;
  cout << janitor1 << endl << endl;
  cout << janitor2 << endl << endl;

  // Places the janitors near the center and randomly the lunch
  Lunch lun;
  janitor1.place_jan(school, 4, 4);
  janitor2.place_jan(school, 5, 4);
  lun.random_start(school);
  cout << "School After Placement:" << endl;
  cout << school << endl << endl;

  // Randomly moves the janitors and the lunch
  janitor1.rand_walk(school);
  janitor2.rand_walk(school);
  lun.rand_move(school);
  cout << "School After Random Step:" << endl;
  cout << school << endl << endl;

  return 0;
}