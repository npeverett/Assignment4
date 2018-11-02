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

  void addTotalWait(int studentWait);
  float getMeanWaitTime(int numStudents);
  int getMedianWaitTime(int numStudents);
  int getLongestWaitTime();
  void addWaitOverTen(int count);
  int getStudentWaitOverTen();
  int getMeanWindowIdle();
  int getLongestIdleTime();
  int getIdleWindowOverFive();


private:
  int clock;
  float totalWaitTime;
  int numOverTen;
  int numStud;
  Queue<Student>* studentQueue;
};
