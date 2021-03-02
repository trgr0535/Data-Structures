/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
  cout << "1. Producer (Produce items into the queue)" << endl;
	cout << "2. Consumer (Consume items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{

ProducerConsumer object;

while(1)
{

menu();
int option;
cin >> option;



if (option == 1)
{
	cout << "Enter the number of items to be produced:" << endl;
	int numItem;
	cin >>  numItem;


	for (int i = 1; i<=numItem; i++)
	{
	cout << "Item" << i << ":" << endl;
	string input;
	cin >> input;
	object.enqueue(input);
	}
}

if (option == 2)
{
	cout << "Enter the number of items to be consumed:" << endl;
	int consume;
	cin >> consume;

	if(object.queueSize() < consume)
		{
			for (int i = 0; i<=object.queueSize(); i++)
			{
				cout << "Consumed: " << object.peek() << endl;
				object.dequeue();
			}

			cout << "Consumed: " << object.peek() << endl;
			object.dequeue();

			cout<< "No more items to consume from queue" << endl;
		}
	else
	{
		for (int i = 0; i<consume; i++)
		{
			cout << "Consumed: " << object.peek() << endl;
			object.dequeue();
		}

	}
}
	if (option == 3)
	{
		cout << "Number of items in the queue:" << object.queueSize() << endl;
		exit(0);
	}
}

    return 0;
}
