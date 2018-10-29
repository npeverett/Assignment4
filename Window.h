#pragma once
#include <iostream>
#include "Student.h"

using namespace std;

class Window
{
public:
  Window();
  Window (int maxSize);
  ~Window();

  bool isFull();

private:
  Student* windows;
  int numWindows;
  bool isAvailable;
};
