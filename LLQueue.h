#pragma once
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include "DLL.h"

using namespace std;

//Doubly-Linked List Based Queue
template <class T>
class Queue{
public:
  Queue();
  ~Queue();

  void enque(T);
  bool deque();
  T front();
  unsigned int size();

  bool isFull();
  bool isEmpty();

private:
  DoubleLL<T> myQueue;
  ListNode<T>* frontM;
  ListNode<T>* rearM;
  unsigned int numElements;
};

//Class Constructor
template <class T>
Queue<T>::Queue()
{
  //frontM = myQueue.getFront();
//  rearM = myQueue.getBack();
  numElements = 0;
}

//Class Destructor
template <class T>
Queue<T>::~Queue()
{
  while (!isEmpty())
  {
    myQueue.removeFront();
  }

  cout << "Queue Destroyed" << endl;
}

//Method to insert new data into queue
template <class T>
void Queue<T>::enque(T data)
{
  myQueue.insertFront(data);
  //frontM = frontM -> next;
  numElements++;
}

//Method to remove data from queue
template <class T>
bool Queue<T>::deque()
{
  if (isEmpty())
  {
    cout << "Queue is empty" << endl;
    return false;
  }

  myQueue.removeBack();
  numElements--;
  return true;
}

//Method to get data at front of queue
template <class T>
T Queue<T>::front()
{
  if (isEmpty())
  {
    cout << "Queue is empty" << endl;
    return;
  }

  return frontM -> data;

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
