#include "GenStack.h"
#include <iostream>

using namespace std;

GenStack::GenStack( ) //default constructor
{
  //initialize variable to default values
  myArray = new char[1];
  size = 1;
  top = -1;
}

GenStack::GenStack(int maxSize) //overloaded constructor
{
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}

GenStack::~GenStack() //destructor
{
  if (myArray) delete [] myArray;
}

void GenStack::push(char d)
{
  //if stack is full, make it bigger
  if(isFull())
  {
    char* temp;
    temp = new char[size];

    for(int i = 0; i < size; i++)
    {
      temp[i] = myArray[i];
    }

    size++;
    delete [] myArray;
    myArray = temp;
    myArray[++top] = d;
  }
  else
  {
    myArray[++top] = d;
  }
}

char GenStack::pop()
{
  //error checking
  if(isEmpty())
  {
    cout << "Stack is empty." << endl;
    return 0;
  }
  else
  {
    char temp = myArray[top--];
    return temp;
  }
}

char GenStack::peek()
{
  //error checking
  if(isEmpty())
  {
    cout << "Stack is empty" << endl;
    return 0;
  }
  else
  {
    return myArray[top];
  }
}

bool GenStack::isFull()
{
  return (top == size-1);
}

bool GenStack::isEmpty()
{
  return (top == -1);
}

int GenStack::getSize()
{
  return top+1;
}
