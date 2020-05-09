# CSCI61
# CSCI61
To run this simulation g++ main.cpp officehours.cpp
1) [10 points] Write a C++ program that simulates an office hour visit.

Assumptions:

Students arrive at the professor's office one at a time and are served one at a time in the order of arrival. Use the STL <queue> class. No need to create your own queue class/implementation.
The Professor plans to not be in his office for more than 1 hour but if there are students still waiting then he will continue the office hour until no more students are waiting. Model an hour as a minute in your program.
The arrival rate is a random number but no new arrivals occur after 1 hour (1 minute in the program) has passed.
The service rate is a random number within minutes (seconds in your program). You can assume this number is the data value in each student (queue item) which pauses the professor from popping the next student from the queue for that duration.
-------------------------------------------------------------------------------

