#include "ProducerConsumer.hpp"
#include <iostream>

using namespace std;

ProducerConsumer::ProducerConsumer()
{
  queueFront = 0;
  queueEnd = 0;
}
bool ProducerConsumer::isEmpty()
{
  return (counter == 0);
}
bool ProducerConsumer::isFull()
{
  return (counter >= SIZE);
}
void ProducerConsumer::enqueue(std::string item)
{
  if(isFull())
  {
      cout<< "Queue full, cannot add new item"<<endl;
  }
  else
  {
  queue[counter] = item;
  counter++
  queueEnd++;
  }

}
void ProducerConsumer::dequeue()
{
  if(isEmpty())
  {
    cout<<"Queue empty, cannot dequeue an item"<<endl;
  }
  else
  {
    for (int i = 1; i<counter; i++)
    {
    queue[i-1] = queue[i];
    }
    counter--;
    queueFront++;
  }
}
string ProducerConsumer::peek()
{
  if(isEmpty())
  {
    cout << "Queue empty, cannot peek" << endl;
    return "";
  }
  else
  {
    return (queue[0]);
  }
}
int ProducerConsumer::queueSize()
{
  return (counter);
}
