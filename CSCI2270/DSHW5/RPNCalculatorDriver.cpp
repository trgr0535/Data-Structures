#include "RPNCalculator.hpp"
#include <iostream>


using namespace std;

bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  RPNCalculator object;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;

  float temp;

  while(true)
  {
    cout << "#> ";
    string input;
    getline(cin,input);



    if (input == "=")
    {

      if(object.isEmpty())
      {
          cout << "No operands: Nothing to evaluate" << endl;
          break;
      }

      temp = object.getStackHead()->number;
      object.pop();

      if(object.isEmpty())
      {
        object.push(temp);
        cout << object.getStackHead()->number << endl;
      }
      else
      {
        cout << "Invalid expression" << endl;
      }
      break;
    }


    if(isNumber(input))
    {
      object.push(stof(input));
    }
    else
    {
      object.compute(input);
    }
  }

  return 0;
}
