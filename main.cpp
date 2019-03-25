#include <iostream> //preprocessor directive
#include <fstream>
#include "GenStack.h"

using namespace std;

int main ()
{
  cout << endl;
  cout << "Please enter the location of the source code file that you would like to be checked." << endl;
  string input;
  getline(cin, input);
  cout << endl;

  string line;
  int lineNumber = 0;
  ifstream myfile(input);
  GenStack mystack(1);

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
          cout << "added " << line[i] << endl;
        }
        else if(line[i] == ')' || line[i] == '}' || line[i] == ']')
        {
          char close = line[i];
          char open = mystack.pop();
          cout << "removed " << open << " and compared to " << close << endl;
          if(!((close == ')' && open == '(') || (close == '}' && open == '{') || (close == ']' && open == '[')))
          {
            cout << "Line " << lineNumber << " expected closure for " << open << " but found " << close << endl;
            exit(1);
          }
        }
      }
    }
    myfile.close();

    if(!(mystack.isEmpty()))
    {
      char x = mystack.pop();
      if(x == '(')
        cout << "Reached end of file without )" << endl;
      else if(x == '{')
        cout << "Reached end of file without }" << endl;
      else if(x == '[')
        cout << "Reached end of file without ]" << endl;
    }
    else
      cout << "good" << endl;
	}
}
