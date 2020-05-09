#include "officehours.h"
#include <cstdlib>
#include <iostream>
//code is based on washing.h
//from michael main data structures queue chapter
bool_source::bool_source(double p){
  assert(p>=0);
  assert(p<=1);
  probability = p;
}
bool bool_source::query() const{
  return (rand()<probability*RAND_MAX);
}
averager::averager(){
  count =0;
  sum = 0;

}
void averager::next_number(double value){
  ++count;
  sum+=value;
}
double averager::average() const{
  assert(how_many_numbers()>0);
  return sum/count;
}
officehours::officehours(unsigned int s){
  time_for_meeting = s;
  teaching_time_left = 0;
}
void officehours::one_second() {
    if (is_busy()) --teaching_time_left;
}

void officehours::start() {
    assert(!is_busy());
    teaching_time_left = time_for_meeting;
}
