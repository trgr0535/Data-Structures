#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


int insertIntoSortedArray(int myArray[], int numEntries, int newValue);
#define filename "numbers.txt";

int main(int argc, char* argv[])
{

	string file = "";
	if (argc < 2) {
		cout << "Not enough arguments!\n";
	}
	else if (argc > 2) {
		cout << "Too many arguments\n";
	}
	else {
		file = argv[1];
	}

	ifstream fs;
	fs.open(file);
		if (fs.fail())
		{
			cout << "Failed to open the file.";
		}

	int myArray[99];
	int numEntries = 0;
	string newLine;
	int intNewLine;

	while (getline(fs, newLine))
	{
	intNewLine = stoi(newLine);
	insertIntoSortedArray(myArray,numEntries,intNewLine);
	numEntries++;
	for (int n=0; n<numEntries; n++)
	{
	    if (n == (numEntries-1))
	    {
	        cout << myArray[n] << endl;
	    }

		 else {
		     cout << myArray[n] <<",";
                }
    }}
}
int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
	myArray[numEntries] = newValue;

	for (int i = numEntries; i > 0; i--)
	{
		for (int k = (i - 1); k > (-1); k--)
		{
			if (myArray[i] < myArray[k])
			{
				int temp;
				temp = myArray[i];
				myArray[i] = myArray[k];
				myArray[k] = temp;
			}
		}
	}

	numEntries++;
	return numEntries;
}
