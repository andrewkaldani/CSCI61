#ifndef OFFICEHOURS_H
#define OFFICEHOURS_H
//code is based on washing.h
//from michael main data structures queue chapter
#include <cstdlib>
#include <iostream>
class bool_source
{
public:
  bool_source(double p = 0.5);
  bool query() const;
private:
  double probability;
};
class averager
{
public:
    averager( );
    void next_number(double value);
    std::size_t how_many_numbers( ) const { return count; }
    double average( ) const;
private:
    std::size_t count; // How many numbers have been given to the averager
    double sum;   // Sum of all the numbers given to the averager
};
class officehours{
public:
  officehours(unsigned int s = 60);
  void one_second();
  void start();
  bool is_busy() const {return(teaching_time_left)>0;}
private:
  unsigned int time_for_meeting;
  unsigned int teaching_time_left;
};
#endif
