#include <iostream>
#include "Student.h"

using namespace std;

//Class Constructor
Student::Student()
{

}

//Overloaded Constructor
Student::Student(string arrivePos, string wait, int finish)
{
  arriveTime = arrivePos;
  waitTime = wait;
  finishTime = stoi(arriveTime) + stoi(waitTime);
}

//Copy Constructor For Student (Used When Inserting To Window Array)
Student::Student(const Student* other)
{
  arriveTime = other -> arriveTime;
  waitTime = other -> waitTime;
  finishTime = other -> finishTime;
}

//Class Destructor
Student::~Student()
{

}

//Getter For Student Arrival
int Student::getStudentArrival()
{
  return stoi(arriveTime);
}

//Getter For Student Wait Time
int Student::getStudentWait()
{
  return stoi(waitTime);
}

//Getter For Student Finish Time
int Student::getFinishTime()
{
  return finishTime;
}
