#pragma once
#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(string arrivePos, string wait, int finish);
  Student(const Student* other);
  ~Student();

  int getStudentArrival();
  int getStudentWait();
  int getFinishTime();


  string arriveTime;
  int finishTime;
  string waitTime;

};
