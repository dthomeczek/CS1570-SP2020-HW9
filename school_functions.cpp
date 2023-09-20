// Programmer: Devin Thomeczek
// MST Username: djtpfr
// Section: 101
// Date: 4/17/2020
// File: school_functions.cpp
// Purpose: Function definitions

#include "school_header.h"
#include "lunch_header.h"
#include "janitor_header.h"

// School Class Functions Start

// Clears the grid
void School::clear()
{
  for (int i = 0; i < MAX; i++)
  {
    for (int j = 0; j < MAX; j++)
    {
      m_grid[i][j] = ' ';
    }
  }
  return;
}

// Builds the school based on set size
void School::build()
{
  const int SUBTRACT = 1; // Used to get the last index of rows/cols
  const int FIRST = 0; // Used for first row/col index
  const int WINDOW = 4; // Used for window spacing on the walls
  int counter_row = 0; // Counter for the rows for windows
  int counter_col = 0; // Counter for the cols for windows

  // Wall construction
  for (int i = FIRST; i < m_school_size; i++)
  {
    for (int j = FIRST; j < m_school_size; j++)
    {
      if (i == FIRST)
      {
        m_grid[i][j] = '+';
      }
      else if (i == m_school_size - SUBTRACT) 
      {
        m_grid[i][j] = '+';
      }
      else if (j == FIRST)
      {
        m_grid[i][j] = '+';
      }
      else if (j == m_school_size - SUBTRACT)
      {
        m_grid[i][j] = '+';
      }
    }
  }

  // Window construction
  for (int i = FIRST; i < m_school_size; i++)
  {
    counter_row = FIRST;
    counter_col++;
    for (int j = FIRST; j < m_school_size; j++)
    {
      counter_row++;
      if (counter_row == WINDOW && i == FIRST && j != (m_school_size - SUBTRACT))
      {
        m_grid[i][j] = '$';
        counter_row = FIRST;
      }
      if (counter_row == WINDOW && i == (m_school_size - SUBTRACT) 
      && j != (m_school_size - SUBTRACT))
      {
        m_grid[i][j] = '$';
        counter_row = FIRST;
      }
      if (counter_col == WINDOW && j == FIRST && i != (m_school_size - SUBTRACT))
      {
        m_grid[i][j] = '$';
      }
      if (counter_col == WINDOW && j == (m_school_size - SUBTRACT)
      && i != (m_school_size - SUBTRACT))
      {
        m_grid[i][j] = '$';
        counter_col = FIRST;
      }
    }
  }
  return;
}

// Constructor for the school class
School::School(const short size) : m_school_size(size)
{
  clear();
  build();
}

// Get function
short School::getSchoolSize()
{
  return m_school_size;
}

// Set function for obtained values
void School::setSchoolSize(const short size)
{
  m_school_size = size;
  return;
}

// Insertion overload for a school
ostream & operator<<(ostream & out, const School & sch)
{
  const int FIRST = 0;
  for (int i = FIRST; i < sch.m_school_size ; i++)
  {
    // Detailing to divide edges of each grid by row
    for (int j = FIRST; j < sch.m_school_size; j++)
    {
      out << '-' << '-';
    }
    out << '-' << endl;

    // Detailing to divide edges of each grid by col
    for (int j = FIRST; j < sch.m_school_size; j++)
    {
      if (j == FIRST)
      {
        out << '|' << sch.m_grid[i][j] << '|';
      }
      else
      {
        out << sch.m_grid[i][j] << '|';
      }      
    }
    out << endl;    
  }

  // Detailing for beneath the bottom wall to match the rest
  for (int j = FIRST; j < sch.m_school_size; j++)
  {
    out << '-' << '-';
  }
  out << '-' << endl;

  return out;
}
// School Class Functions End

// Janitor Class Functions Start

// Janitor class constructor function
Janitor::Janitor(string name, char janitor) : 
m_jan_name(name), m_jan_char(janitor)
{
  m_bac = 0.05;
  m_bruises = 0;
  m_jan_row_coord = -1;
  m_jan_col_coord = -1;
  m_sober = true;
  m_alive = true;
}

// Function to place a janitor in the school
void Janitor::place_jan(School & sch, int row, int col)
{
  int coord; // Starting position

  coord = sch.getSchoolSize() / 2; // Finds the general middle of the school

  if (m_jan_row_coord == -1 && m_jan_col_coord == -1 && 
  sch.m_grid[coord][coord] == ' ')
  {
    coord = sch.getSchoolSize() / 2; // Finds the general middle of the school
    m_jan_row_coord = coord;
    m_jan_col_coord = coord;
  }
  else
  {
    sch.m_grid[m_jan_row_coord][m_jan_col_coord] = ' ';
  }
  
  m_jan_row_coord = row;
  m_jan_col_coord = col;

  sch.m_grid[row][col] = m_jan_char;

  return;
}

// Function to declare a random direction for a janitor to walk in
void Janitor::rand_walk(School & sch)
{
  const int CARDINAL = 4; // 4 cardinal directions (0-3)
  const int ADDER = 1; // Either adds +1 or -1 to row or col

  int direction; // Direction value (0-3)
  int row_direction = 0; // Row direction to go in
  int col_direction = 0; // Col direction to go in
  int new_row; // New value after adding row direction
  int new_col; // New value after adding col direction

  do
  {
    direction = rand() % CARDINAL;

    switch (direction)
    {
      // North direction
      case 0:
        row_direction -= ADDER;
        break;
      // East direction
      case 1:
        col_direction += ADDER;
        break;
      // South direction
      case 2:
        row_direction += ADDER;
        break;
      // West direction
      case 3:
        col_direction -= ADDER;
        break;
    }
    new_row = m_jan_row_coord + row_direction;
    new_col = m_jan_col_coord + col_direction;

    row_direction = 0;
    col_direction = 0;
  } while (sch.m_grid[new_row][new_col] != ' ');
  
  place_jan(sch, new_row, new_col);

  return;
}

// Insertion overload for a janitor
ostream & operator<<(ostream & out, const Janitor & jan)
{
  out << "Name: " << jan.m_jan_name << endl;
  out << "Representation: " << jan.m_jan_char << endl;
  out << "Blood Alcohol Content: " << jan.m_bac << endl;
  out << "Bruises: " << jan.m_bruises << endl;
  out << "Location: (" << jan.m_jan_row_coord << ", " << jan.m_jan_col_coord
  << ")" << endl;
  out << "Sober: ";
  if (jan.m_sober == true)
  {
    out << "True" << endl;
  }
  else
  {
    out << "False" << endl;
  }
  out << "Alive: ";
  if (jan.m_alive == true)
  {
    out << "True" << endl;
  }
  else
  {
    out << "False" << endl;
  }

  return out;
}
// Janitor Class Functions End

// Lunch Class Functions Start

// Lunch class constructor function
Lunch::Lunch()
{
  m_lun_row_coord = -1; // Default starting value for lunch row
  m_lun_col_coord = -1; // Default starting value for lunch col
  m_lunch_char = 'L'; // Character to represent lunch
}

// Lunch class randomized starting value
void Lunch::random_start(School & sch)
{
  int row;
  int col;

  if (m_lun_row_coord >= 0 && m_lun_col_coord >= 0)
  {
    sch.m_grid[m_lun_row_coord][m_lun_col_coord] = ' ';
  }
  
  do
  {
    row = rand() % sch.getSchoolSize();
    col = rand() % sch.getSchoolSize();
  } while (sch.m_grid[row][col] != ' ');

  m_lun_row_coord = row;
  m_lun_col_coord = col;

  sch.m_grid[row][col] = m_lunch_char;

  return;
}

// Lunch class placement function
void Lunch::place_lun(School & sch, int row, int col)
{
  if (m_lun_row_coord >= 0 && m_lun_col_coord >= 0)
  {
    sch.m_grid[m_lun_row_coord][m_lun_col_coord] = ' ';
  }
  
  m_lun_row_coord = row;
  m_lun_col_coord = col;

  sch.m_grid[row][col] = m_lunch_char;

  return;
}

// Function to declare a random direction for a lunch to walk in
void Lunch::rand_move(School & sch)
{
  const int CARDINAL = 4; // 4 cardinal directions (0-3)
  const int ADDER = 1; // Either adds +1 or -1 to row or col

  int direction; // Direction value (0-3)
  int row_direction = 0; // Row direction to go in
  int col_direction = 0; // Col direction to go in
  int new_row; // New value after adding row direction
  int new_col; // New value after adding col direction

  do
  {
    direction = rand() % CARDINAL;

    switch (direction)
    {
      // North direction
      case 0:
        row_direction -= ADDER;
        break;
      // East direction
      case 1:
        col_direction += ADDER;
        break;
      // South direction
      case 2:
        row_direction += ADDER;
        break;
      // West direction
      case 3:
        col_direction -= ADDER;
        break;
    }
    new_row = m_lun_row_coord + row_direction;
    new_col = m_lun_col_coord + col_direction;

    row_direction = 0;
    col_direction = 0;
  } while (sch.m_grid[new_row][new_col] != ' ');
  
  place_lun(sch, new_row, new_col);

  return;
}