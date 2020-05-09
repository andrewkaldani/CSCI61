#include "officehours.h"
#include <cassert>
#include <cstdlib>
using namespace std;

bool_source::bool_source(double p)
{
    assert(p >= 0);
    assert(p <= 1);
    probability = p;
}

bool bool_source::query( ) const
{
    return (rand( ) < probability * RAND_MAX);
}

averager::averager( )
{
    count = 0;
    sum = 0;
}

void averager::next_number(double value)
{
    ++count;
    sum += value;
}

double averager::average() const
{
    assert(how_many_numbers( ) > 0);
    return sum/count;
}

officehours::officehours(unsigned int s) {
    seconds_for_teaching = s;
    meet_time_left = 0;
}

void officehours::one_second() {
    if (is_busy()) --meet_time_left;
}

void officehours::start(int next) {
    assert(!is_busy());
    meet_time_left =next;
     seconds_for_teaching=next;
}
