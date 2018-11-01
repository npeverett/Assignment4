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
  bool isFull();
  bool isEmpty();

  void getNumElements();
private:
  Student** windows;
  int numWindows;
  bool isAvailable;
};
