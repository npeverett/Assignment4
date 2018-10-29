#include <iostream>
#include <sstream>
#include <fstream>
#include "FileReader.h"

using namespace std;

//Class Constructor
FileReader::FileReader()
{

}

//Class Destructor
FileReader::~FileReader()
{

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

void FileReader::readFile(string filename)
{
  string line = "";

  ifstream fin;
  fin.open(filename);

  string temp((istreambuf_iterator<char>(fin)), istreambuf_iterator<char>());
  fileContents = temp;
}
