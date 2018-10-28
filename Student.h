#include <iostream>

using namespace std;

class Student
{
public:
  Student();
  Student(int arrivePos, int wait);
  ~Student();

private:
  int arriveTime;
  int waitTime;
};

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
