#include <iostream>
#include <sstream>
#include <fstream>
#include "FileReader.h"
#include "LLQueue.h"
#include "Student.h"

using namespace std;

//Class Constructor
FileReader::FileReader()
{
  totalStudents = 0;
}

//Class Destructor
FileReader::~FileReader()
{

}

//Class Copy Constructor
FileReader::FileReader(const FileReader& obj)
{
  totalStudents = 0;
}

//Method to check if file exists/is readable
bool FileReader::fileGood(string filename)
{
  ifstream fin;
  fin.open(filename);

  if (fin.good())
  {
    return true;
  }

  fin.close();
  fin.clear();
  fin.seekg(0, fin.beg);

  return false;
}

//Method to read file contents and put input into respective variables
void FileReader::readFile(string filename)
{
  ifstream fin;
  fin.open(filename);

  queue = new Queue<Student>;

  //First line should be number of open windows
  fin >> openWindows;
  totalWindows = stoi(openWindows);


  //Loops to get number of students at certain time, then will create
  //Students based on following numbers in inputs with the repective arrival/wait times
  while(fin >> arrivalTime >> numStudents)
  {

    //For each student who arrives at the same time
    for (int i = 0; i < stoi(numStudents); ++i)
    {
      fin >> timeNeeded;
      int difference = stoi(arrivalTime) + stoi(timeNeeded);
      Student newStudent(arrivalTime, timeNeeded, difference);
      queue -> enque(newStudent);
      totalStudents++;

      cout << "Student: " << arrivalTime << "," << timeNeeded << endl;
    }
  }
}

//Getter for number of windows to open
int FileReader::getOpenWindows()
{
  return totalWindows;
}

//Getter for total number of students
int FileReader::getTotalNumStudents()
{
  return totalStudents;
}

//Getter for student queue
Queue<Student>* FileReader::getStudentQueue()
{
  return queue;
}
