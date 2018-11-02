#include <iostream>
#include "Window.h"
#include "FileReader.h"

using namespace std;

//Class Constructor
Window::Window()
{

}

//Overloaded Constructor
Window::Window(int maxSize)
{
  numWindows = maxSize;
  windows = new Student*[numWindows];
}

//Class Copy Constructor
Window::Window(const Window& obj)
{

}

//Class Destructor
Window::~Window()
{
  for (int i = 0; i < numWindows; ++i)
  {
    windows[i] = nullptr;
  }

  delete[] windows;
  windows = nullptr;
  cout << "Window Array Deleted" << endl;
}

//Method To initialize window to null
void Window::initializeWindow()
{
  for (int i = 0; i < numWindows; ++i)
  {
    windows[i] = NULL;
  }
}


//Method to add new student to the window
void Window::insertStudent(Student* st)
{
  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i] == NULL)
    {
      Student* newStudent = new Student(st);
      windows[i] = newStudent;
      break;
    }
  }
}


//Method to remove student when time has expired
void Window::removeStudent(Student* st)
{
  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i] == st)
    {
      cout << "Student who began at time " << windows[i] -> arriveTime;
      windows[i] = NULL;
      cout << " has become NULL";
      return;
    }
  }
}


//Method to check if a student is ready to leave
bool Window::studentExpire(int time)
{
  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i] != NULL)
    {
      if (time == windows[i] -> finishTime)
      {
        removeStudent(windows[i]);
        cout << " at time " << time << '\n' << endl;
      }
    }
  }
  return false;
}

//Method to get the number of elements in the array
int Window::getNumElements()
{
  int count = 0;
  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i] != NULL)
    {
      count++;
    }
  }

  return count;
}

//Method to get size of array
int Window::getNumWindows()
{
  return numWindows;
}

void Window::incTimeIdle()
{
  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i] == NULL)
    {
      idleCount++;
    }
  }
}

float Window::getTimeIdle()
{
  return float(idleCount) / float(numWindows);
}
