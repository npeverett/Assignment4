#include <iostream>
#include "Student.h"

using namespace std;

Student::Student()
{

}

Student::Student(int arrivePos, int wait)
{
  arriveTime = arrivePos;
  waitTime = wait;
}

Student::~Student()
{

}
