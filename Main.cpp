#include <iostream>
#include "DLL.h"
#include "LLQueue.h"
#include "Student.h"
#include "FileReader.h"
#include "Window.h"
#include "Simulation.h"

using namespace std;

int main(int argc, char **argv)
{
  FileReader fr;
  Simulation sim;

  //If User Does Not Provide A File Name In Argument
  if (argv[1] == NULL)
  {
    cout << "Please attach a file name when compiling." << endl;
    return 1;
  }

  //Check If File Is Readable and Exists
  if(fr.fileGood(argv[1]) == false)
  {
    cout << "Could not locate given file. Please try again." << endl;
    return 1;
  }

  fr.readFile(argv[1]);
  sim.beginSimulation(fr.getTotalNumStudents(), fr.getStudentQueue(), fr.getOpenWindows());

  return 1;
}

//NEED TO CHECK ABOUT STUDENT TIMES LEAVING ARRAY, FINISHTIME != TIME THEY LEAVE
//NEED TO GET SUMMARY STATISTICS
