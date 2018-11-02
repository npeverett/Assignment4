#include <iostream>
#include <string>
#include <sstream>
#include "Simulation.h"
#include "DLL.h"
#include "LLQueue.h"
#include "Window.h"
#include "Student.h"
#include "FileReader.h"

using namespace std;

//Class Constructor
Simulation::Simulation()
{
  totalWaitTime = 0;
}

//Class Destructor
Simulation::~Simulation()
{

}

//Copy Constructor
Simulation::Simulation(const Simulation& obj)
{

}

void Simulation::beginSimulation(int numStuds, Queue<Student>* queue, int arraySize)
{
  Window win(arraySize);
  win.initializeWindow();

  this -> numStud = numStuds;
  studentQueue = queue;

  //This program assumes 1 clock tick is equivalent to 1 minute
  clock = 0;

  while (true)
  {
    //Checks if student needs to be removed and removes at current time
    win.studentExpire(clock);
    win.incTimeIdle();

    //If the student queue is empty.. no more students waiting
    if (studentQueue -> isEmpty() == true)
    {
      //Only exit is both queue and windows are finished
      if (win.getNumElements() == 0)
      {
        break;
      }

      //Otherwise, increase time until all students removed
      clock++;
      continue;
    }

    //If Window array is full... increase time until one removed
    if (win.getNumElements() == win.getNumWindows())
    {
      clock++;
      continue;
    }

    //Send new student to array
    Student front = queue -> front();
    if(front.getStudentArrival() == clock)
    {
      Student temp = queue -> deque();
      Student* currStudent = &temp;
      win.insertStudent(currStudent);
      cout << "Student with arrival time of " << currStudent -> arriveTime << " entered office" << '\n' << endl;

      /*
      The STOI function does not allow for mathematical operations and given
      that my student class was already set up as arrival time as a string
      I could not complete the mean calculations, however the commented code below
      would provide the correct number if the stoi function would allow such operations

      addTotalWait(stoi(currStudent -> arriveTime) - time)

      if (stoi(currStudent -> arriveTime - time) > 10)
      {
        addWaitOverTen();
      }
      */

      continue;
    }

    clock++;
  }


  cout << "All students have been helped." << endl;
  cout << '\n' << '\n' << '\n' << endl;
  cout << "Mean Wait Time:   " << getMeanWaitTime(numStud) << endl;
  cout << "Median Wait Time: " << getMedianWaitTime(numStud) << endl;
  cout << "Longest Wait Time: "<< getLongestWaitTime() << endl;
  cout << "Wait Times Above Ten Minutes: " << getStudentWaitOverTen() << endl;
  cout << "Mean Idle Window Time: " << (win.getTimeIdle() / float(clock)) << endl;
  cout << "Longest Idle Window Time: " << getLongestIdleTime() << endl;
  cout << "Number of Windows Idle Over Five Minutes: " << getIdleWindowOverFive() << endl;
  cout << endl;

}

//Method to get the total wait times of all the students
void Simulation::addTotalWait(int studentWait)
{
  totalWaitTime += float(studentWait);
}


//Method to get the mean wait time of students
float Simulation::getMeanWaitTime(int numStudents)
{
  float mean = totalWaitTime / float(numStudents);
  return mean;
}

//Method to get the median wait time
int Simulation::getMedianWaitTime(int numStudents)
{

  int isEven = numStudents % 2;
  if (isEven == 0)
  {
    //Middle Num
  }

  else
  {
    //Middle2 / 2
  }

  return isEven;
}


//Method to get the number of students waiting more than ten minutes
void Simulation::addWaitOverTen(int count)
{
  numOverTen++;
}

//Method to print number of students over ten
int Simulation::getStudentWaitOverTen()
{
  return numOverTen;
}

int Simulation::getLongestWaitTime()
{
  return 0;
}

int Simulation::getMeanWindowIdle()
{
  return 0;
}

int Simulation::getLongestIdleTime()
{
  return 0;
}

int Simulation::getIdleWindowOverFive()
{
  return 0;
}
