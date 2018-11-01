#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"
#include "LLQueue.h"
#include "Simulation.h"

using namespace std;

class FileReader
{
public:
  FileReader();
  ~FileReader();
  FileReader(const FileReader& obj);

  bool fileGood(string filename);
  void readFile(string filename);
  void parseData();

  int getOpenWindows();
  int getTotalNumStudents();
  Queue<Student>* getStudentQueue();

private:
  string fileContents;
  string openWindows;
  int totalWindows;
  string arrivalTime;
  string numStudents;
  string timeNeeded;
  int totalStudents;
  Queue<Student>* queue;
};
