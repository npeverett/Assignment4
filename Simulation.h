#pragma once
#include <iostream>
#include "Student.h"
#include "LLQueue.h"

using namespace std;

class Simulation
{
public:
  Simulation();
  ~Simulation();
  Simulation(const Simulation& obj);

  void beginSimulation(int numStuds, Queue<Student>* queue, int arraySize);

  int getMeanStudentWait(int studentWait);

private:
  int clock;
  int totalWaitTime;
  int numStud;
  Queue<Student>* studentQueue;
};
