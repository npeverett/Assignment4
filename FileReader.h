#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class FileReader
{
public:
  FileReader();
  ~FileReader();

  bool fileGood(string filename);
  void readFile(string filename);

private:
  string fileContents;
  int openWindows;
  int arrivalTime;
  int numStudents;
  int timeNeeded;
};
