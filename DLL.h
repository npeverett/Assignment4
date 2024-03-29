#pragma once
#ifndef DLL_H
#define DLL_H
#include <iostream>

using namespace std;

//ListNode CLASS
template <class T>
class ListNode
{
public:
  ListNode();
  ListNode(T d);
  ~ListNode();

  T data;
  ListNode* next;
  ListNode* prev;
};

template <class T>
ListNode<T>::ListNode()
{

}

template <class T>
ListNode<T>::ListNode(T d)
{
  data = d;
  next = NULL;
  prev = NULL;
}

template <class T>
ListNode<T>::~ListNode()
{

}



//Double LinkedList CLASS
template <class T>
class DoubleLL
{
public:
  //Constructors
  DoubleLL();
  ~DoubleLL();

  //Insert
  void insertFront(T d);
  void insertBack(T d);

  //Delete/Remove
  bool removeFront();
  T removeBack();
  bool remove(T key);
  bool deletePosition(int pos);

  //Other
  int find(T value);
  T getPosData(int pos);
  unsigned int size();
  void printList();


private:
  ListNode<T>* front;
  ListNode<T>* back;
  unsigned int ListSize;
};

//Class Constructor
template <class T>
DoubleLL<T>::DoubleLL()
{
  ListSize = 0;
  front = NULL;
  back = NULL;
}

//Class Destructor
template <class T>
DoubleLL<T>::~DoubleLL()
{
  while (ListSize > 0)
  {
    removeFront();
  }

  cout << "Doubly-Linked List Destroyed" << endl;
}

//Method to insert new node at front of list
template <class T>
void DoubleLL<T>::insertFront(T d)
{
  ListNode<T>* node = new ListNode<T>(d);
  if (ListSize == 0)
  {
    back = node;
  }

  else
  {
    front -> prev = node;
    node -> next = front;
  }

  front = node;
  ListSize++;
}

//Method to insert new node at back of list
template <class T>
void DoubleLL<T>::insertBack(T d)
{
  ListNode<T>* node = new ListNode<T>(d);
  if (ListSize == 0)
  {
    front = node;
  }

  else
  {
    back -> next = node;
    node -> prev = back;
  }

  back = node;
  ListSize++;
}

//Method to remove a node at front of list
template <class T>
bool DoubleLL<T>::removeFront()
{
  if (ListSize == 0)
  {
    cout << "List is empty." << endl;
    return false;
  }

  ListNode<T>* temp = front;
  if (front -> next == NULL)
  {
    back = NULL;
  }

  else
  {
    front -> next -> prev = NULL;
  }

  front = front -> next;
  temp -> next = NULL;

  delete temp;
  ListSize--;
  return true;
}

//Method to remove a node at back of list
template <class T>
T DoubleLL<T>::removeBack()
{
  if (ListSize == 0)
  {
    cout << "List is empty." << endl;
    exit(0);
  }

  ListNode<T>* temp = back;
  if (back -> prev == NULL)
  {
    front = NULL;
  }

  else
  {
    back -> prev -> next = NULL;
  }

  back = back -> prev;

  ListSize--;
  return temp -> data;
}

//Method to remove a node given the data point
template <class T>
bool DoubleLL<T>::remove(T key)
{
  if (ListSize == 0)
  {
    cout << "List is empty." << endl;
    return false;
  }

  ListNode<T>* curr = front;
  while (curr -> data != key)
  {
    curr = curr -> next;

    if (curr == NULL)
    {
      cout << "Data given is not found in list." << endl;
      return false;
    }
  }

  if (curr == front)
  {
    front = curr -> next;
  }

  if (curr == back)
  {
    back = curr -> prev;
  }

  if (curr != front && curr != back)
  {
    curr -> prev -> next = curr -> next;
    curr -> next -> prev = curr -> prev;
  }

  delete curr;
  ListSize--;
  return true;
}

//Method to remove a node given its position
template <class T>
bool DoubleLL<T>::deletePosition(int pos)
{
  if (ListSize == 0)
  {
    cout << "List is empty." << endl;
    return false;
  }

    int idx = 0;
    ListNode<T>* curr = front;
    ListNode<T>* previous = front;

    //If first node in list...
    if (pos == idx)
    {
      removeFront();
      return true;
    }

    //If last node in list...
    if (pos == ListSize -1)
    {
      removeBack();
      return true;
    }

    //If node is in between...
    while (idx != pos)
    {
      previous = curr;
      curr = curr -> next;
      idx++;
    }

    previous -> next = curr -> next;
    curr -> next -> prev = curr -> prev;

    delete curr;
    delete previous;
    ListSize--;
    return true;
}

//Method to find a node given its data
template <class T>
int DoubleLL<T>::find(T value)
{
  if (ListSize == 0)
  {
    cout << "List is empty." << endl;
    return -1;
  }

  int idx = 0;
  ListNode<T>* curr = front;
  while (curr -> data != value)
  {
    curr = curr -> next;
    idx++;

    if (curr == NULL)
    {
      cout << "Data given is not found in list." << endl;
      return -1;
    }
  }

  return idx;
}

//Method to get data at a position
template <class T>
T DoubleLL<T>::getPosData(int pos)
{
  if (ListSize == 0)
  {
    cout << "List is empty." << endl;
    exit(0);
  }

  int idx = 0;
  ListNode<T>* curr = front;
  while (idx != pos)
  {
    curr = curr -> next;
    idx++;

    if (curr == NULL)
    {
      cout << "No node exists at given position." << endl;
      exit(0);
    }
  }

  return curr -> data;
}

//Method to get number of nodes in list
template <class T>
unsigned int DoubleLL<T>::size()
{
  return ListSize;
}

//Method to print all data points in list
template <class T>
void DoubleLL<T>::printList()
{
  if (ListSize == 0)
  {
    cout << "List is empty" << endl;
  }
  else
  {
    ListNode<T>* curr = front;
    while (curr != NULL)
    {
      cout << curr -> data << endl;
      curr = curr -> next;
    }

    delete curr;
  }
}


#endif
