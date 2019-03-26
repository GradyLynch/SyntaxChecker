#include <iostream> //preprocessor directive
#include <fstream>
#include "GenStack.h"
#include "SyntaxChecker.h"

using namespace std;

int main ()
{
  cout << endl;
  cout << "Please enter the name of the source code file that you would like to be checked." << endl;
  string fileName;
  getline(cin, fileName);
  cout << endl;

  SyntaxChecker(fileName);

  cout << endl;
  cout << "Would you like to check another file (please enter either 'yes' or 'no')." << endl;
  string input;
  getline(cin, input);
  cout << endl;

  // loop for checking multiple files
  while(input == "yes")
  {
    cout << "Please enter the name of the source code file that you would like to be checked." << endl;
    getline(cin, fileName);
    cout << endl;

    SyntaxChecker(fileName);

    cout << endl;
    cout << "Would you like to check another file (please enter either 'yes' or 'no')." << endl;
    getline(cin, input);
    cout << endl;
  }
  cout << "Goodbye" << endl;
}
