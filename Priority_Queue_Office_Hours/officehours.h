#ifndef OFFICEHOURS_H
#define OFFICEHOURS_H
#include <cstdlib>

class bool_source
{
public:
    bool_source(double p=0.5);
    bool query( ) const;
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
    std::size_t count;
    double sum;
};

class officehours
{
public:
    officehours(unsigned int s = 60);
    void one_second( );
    void start(int next);
    bool is_busy( ) const { return (meet_time_left > 0); }
private:
    int seconds_for_teaching;
    int meet_time_left;

};
#endif
