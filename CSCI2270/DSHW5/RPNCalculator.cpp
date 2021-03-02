#include "RPNCalculator.hpp"
#include <iostream>

using namespace std;

RPNCalculator::RPNCalculator()
{
  stackHead = NULL;
}

RPNCalculator::~RPNCalculator()
{
  while (!isEmpty())
  {
    pop();
  }
}

bool RPNCalculator::isEmpty()
{
  return (stackHead == NULL);
}

void RPNCalculator::push(float num)
{
  Operand* NewO = new Operand;
  NewO->number = num;
  NewO->next = NULL;
  NewO->next = stackHead;
  stackHead = NewO;
}
void RPNCalculator::pop()
{
  if (!isEmpty())
  {
  Operand* temp;
  temp = stackHead;
  stackHead = stackHead->next;
  delete temp;
  }
  else
  {
    cout << "Stack empty, cannot pop an item."<< endl;
  }
}

Operand* RPNCalculator::peek()
{
    if(!isEmpty())
        return stackHead;
    else
    {
        cout<<"Stack empty, cannot peek."<<endl;
        return NULL;
    }
}

bool RPNCalculator::compute(string symbol)
{
if (symbol == "+" || symbol == "*")
{

  float pop1;
  float pop2;
  float result;

  if(stackHead == NULL || stackHead->next == NULL)
    {
    cout << "err: not enough operands" << endl;
    return false;
    }
  else
    {
    pop1 = stackHead->number;
    pop();
    pop2 = stackHead->number;
    pop();
    }

  if (symbol == "+")
    {
      result = pop1 + pop2;
    }

  if (symbol == "*")
    {
    result = pop1 * pop2;
    }
  push(result);
  return true;
}
else
{
  cout << "err: invalid operation" << endl;
  return false;
}
}
