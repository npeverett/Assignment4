#pragma once
#include <iostream>
#include "Student.h"

using namespace std;

class Window
{
public:
  Window();
  Window(int maxSize);
  ~Window();
  Window(const Window& obj);
  void initializeWindow();

  void insertStudent(Student* st);
  void removeStudent(Student* st);
  bool studentExpire(int time);

  int getNumElements();
  int getNumWindows();
  float getTimeIdle();
  void incTimeIdle();

private:
  Student** windows;
  int numWindows;
  int idleCount;
  bool isAvailable;
};
