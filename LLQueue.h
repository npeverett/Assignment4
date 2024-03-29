#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "DLL.h"
#include "Student.h"

using namespace std;

//Doubly-Linked List Based Queue
template <class T>
class Queue{
public:
  Queue();
  ~Queue();
  Queue(const Queue& obj);

  void enque(T);
  T deque();
  T front();
  unsigned int size();

  bool isEmpty();

private:
  DoubleLL<Student> myQueue;
  int frontM;
  int rearM;
  unsigned int numElements;
};

//Class Constructor
template <class T>
Queue<T>::Queue()
{
  frontM = 0;
  rearM = -1;
  numElements = 0;
}

template <class T>
Queue<T>::Queue(const Queue& obj)
{
  frontM = 0;
  rearM = -1;
  numElements = 0;
}

//Class Destructor
template <class T>
Queue<T>::~Queue()
{
  //No memory allocated in Queue header,
  //DLL destructor takes care of nodes in list

  cout << "Queue Destroyed" << endl;
}

//Method to insert new data into queue
template <class T>
void Queue<T>::enque(T data)
{
  myQueue.insertFront(data);
  rearM++;
  numElements++;
}

//Method to remove data from queue
template <class T>
T Queue<T>::deque()
{
  if (isEmpty())
  {
    cout << "Queue is empty" << endl;
    exit(0);
  }

  T temp = myQueue.removeBack();
  frontM++;
  rearM--;
  numElements--;
  return temp;
}

//Method to get data at front of queue
template <class T>
T Queue<T>::front()
{
  if (isEmpty())
  {
    cout << "Queue is empty" << endl;
    exit(0);
  }
  T result = myQueue.getPosData(rearM);
  return result;

}

//Method to get size of queue
template <class T>
unsigned int Queue<T>::size()
{
  return numElements;
}

//Array-Based Queues would normally have an isFull() method,
//however given its is implemented with DLL, list can never be full

//Method to check is list/queue is empty
template <class T>
bool Queue<T>::isEmpty()
{
  return (numElements == 0);
}

#endif
