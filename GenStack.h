#include <iostream>

using namespace std;

class GenStack
{
  public:
    GenStack(); //constructor
    GenStack(int maxSize); //overloaded constructor
    ~GenStack(); //destructor

    void push(char d);
    char pop();
    char peek(); //aka top()

    int getSize();
    bool isEmpty();
    bool isFull();

    int size;
    int top;

    char *myArray;
};
