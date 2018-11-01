#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{

}

Student::Student(string arrivePos, string wait, int finish)
{
  arriveTime = arrivePos;
  waitTime = wait;
  finishTime = stoi(arriveTime) + stoi(waitTime);
}

Student::~Student()
{

}

int Student::getStudentArrival()
{
  return stoi(arriveTime);
}

int Student::getStudentWait()
{
  return stoi(waitTime);
}

int Student::getFinishTime()
{
  return finishTime;
}
