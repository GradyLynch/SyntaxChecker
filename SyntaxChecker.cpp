#include <iostream> //preprocessor directive
#include <fstream>
#include "GenStack.h"

using namespace std;

void SyntaxChecker(string fileName)
{
  string line;
  int lineNumber = 0;
  ifstream myfile(fileName);
  GenStack mystack;

  if (myfile.is_open())
  {
    while (getline(myfile,line))
    {
      lineNumber++;

      for(int i = 0; i < line.length(); i++)
      {
        if(line[i] == '(' || line[i] == '{' || line[i] == '[')
        {
          mystack.push(line[i]);
        }
        else if(line[i] == ')' || line[i] == '}' || line[i] == ']')
        {
          char close = line[i];
          char open = mystack.pop();
          if(!((close == ')' && open == '(') || (close == '}' && open == '{') || (close == ']' && open == '[')))
          {
            cout << "Line " << lineNumber << " expected closure for " << open << " but found " << close << endl;
            exit(1);
          }
        }
      }
    }
    myfile.close();

    // check if there is an open that is never closed
    if(!(mystack.isEmpty()))
    {
      char x = mystack.pop();
      if(x == '(')
        cout << "Reached end of file without )" << endl;
      else if(x == '{')
        cout << "Reached end of file without }" << endl;
      else if(x == '[')
        cout << "Reached end of file without ]" << endl;
      exit(1);
    }
    else
      cout << "Your file has no syntax errors." << endl;
	}
}
