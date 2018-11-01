#include <iostream>
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

  while (studentQueue -> isEmpty() == false)
  {
    //Checks if student needs to be removed and removes at current time
    win.studentExpire(clock);

    Student front = queue -> front();
    while(front.getStudentArrival() == clock)
    {

      win.getNumElements();
      Student temp = queue -> deque();
      Student* currStudent = &temp;
      win.insertStudent(currStudent);

      if (win.isFull() || studentQueue -> isEmpty())
      {
        break;
      }

      front = queue -> front();
    }

    if (win.isFull())
    {
      clock++;
      continue;
    }

    clock++;
  }

  cout << "All students have been helped." << endl;
}


int Simulation::getMeanStudentWait(int studentWait)
{
  while (studentQueue -> isEmpty() == false)
  {
    totalWaitTime += studentWait;
  }

  return (totalWaitTime / numStud);
}
