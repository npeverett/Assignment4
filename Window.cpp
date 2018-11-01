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
  if (!isFull())
  {
    for (int i = 0; i < numWindows; ++i)
    {
      if (windows[i] == NULL)
      {
        windows[i] = st;
        cout << "Student arrived at: " << windows[i] -> arriveTime << endl;
        break;
      }
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
      windows[i] = NULL;
      break;
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
      if (windows[i] -> finishTime == time)
      {
        cout << "Student left at: " << time << endl;
        removeStudent(windows[i]);
        return true;
      }
    }
  }
  return false;
}


void Window::getNumElements()
{
  int count = 0;
  if (!isEmpty())
  {
    for (int i = 0; i < numWindows; ++i)
    {
      if (windows[i] != NULL)
      {
        count++;
      }
    }
  }
}


//Method to check if any windows are open for students
bool Window::isFull()
{

  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i] == NULL)
    {
      return false;
    }
  }

  return true;
}

//Method to check if all windows are available
bool Window::isEmpty()
{
  for (int i = 0; i < numWindows; ++i)
  {
    if (windows[i] != NULL)
    {
      return false;
    }
  }

  return true;
}
