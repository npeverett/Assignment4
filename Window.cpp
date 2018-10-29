#include <iostream>
#include "Window.h"

using namespace std;

//Class Constructor
Window::Window()
{

}

//Overloaded Constructor
Window::Window(int maxSize)
{
  numWindows = maxSize;
  windows = new Student[maxSize];
  isAvailable = true;
}

//Class Destructor
Window::~Window()
{
  delete[] windows;
  windows = nullptr;
  cout << "Window Array Deleted" << endl;
}

//Method to check if any windows are open for students
bool Window::isFull()
{

}
