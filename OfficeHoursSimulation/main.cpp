#include <iostream>   // Provides cout
#include <cstdlib>    // Provides EXIT_SUCCESS
#include <queue>
//code is based on washing.h
//from michael main data structures queue chapter
#include "officehours.h"
using namespace std;
void office_hour_simulate(unsigned int office_time, double arrival_prob, unsigned int total_time){
  queue<unsigned int> arrival_time;
  unsigned int next;
  bool_source arrival(arrival_prob);
  officehours prof(office_time);
  averager wait_times;
  unsigned int current_second;
  cout<<"seconds to teach one student: "<<office_time<<endl;
  cout<<"probability of a student arriving: "<<arrival_prob<<endl;
  cout<<"total simulation seconds: "<<total_time<<endl;
  while(current_second <=60 || !arrival_time.empty())
  {
      if(current_second < 60){
        if (arrival.query( ))
          arrival_time.push(current_second);
        }
    if(!prof.is_busy() && !arrival_time.empty()){
      next = arrival_time.front();
      arrival_time.pop();
      wait_times.next_number(current_second-next);
      prof.start();
    }
    prof.one_second();
    current_second++;
  }
  cout<<"Student visited: "<<wait_times.how_many_numbers()<<endl;
  if(wait_times.how_many_numbers()>0){
    cout<<"average wait: "<<wait_times.average()<<" sec"<<endl;
    cout<<"time beyond 1 hr: "<<(current_second-60)<<" sec"<<endl;

  }
}
int main(){
  srand(time(0));
  unsigned int totalTime = rand()%15 +1;
  double probability = rand()%15 +15;
  office_hour_simulate(totalTime,probability/100,60);
  return 0;
}
