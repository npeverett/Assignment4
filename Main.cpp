#include <iostream>
#include "DLL.h"
#include "LLQueue.h"
#include "Student.h"
#include "FileReader.h"

using namespace std;

int main(int argc, char **argv)
{
  int clockTimer = 0;
  Queue<int> myLLQueue;
  FileReader fr;

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

  return 1;
}
