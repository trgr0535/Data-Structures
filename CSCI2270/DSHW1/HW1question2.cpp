#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

#define inputFile "park.csv";
#define outputFile "outputfile.csv";

struct Park {
	string parkname;
	string state;
	int area;
};

void addPark(Park parks[], string parkname, string state, int area, int length);
void printList(const Park parks[], int length);

int main(int argc, const char *argv[])
{
    int minArea = 0;
    string iFile = "";
    string oFile = "";

	if (argc < 4) {
		cout << "Not enough arguments!\n";
	}
	else if (argc > 4) {
		cout << "Too many arguments\n";
	}
	else {
		iFile = argv[1];
        oFile = argv[2];
        minArea = stoi(argv[3]);
	}

    Park parksArray[99];
    int length = 0;

    string fullLine;

    ifstream fs;
    fs.open(iFile);
    ofstream os;
    os.open(oFile);

    while (getline(fs,fullLine,'\n'))
    {
    string parkName;
    string parkState;
    string parkSize;
    int intparkSize;
    stringstream st(fullLine);

    getline(st,parkName,',');
    getline(st,parkState,',');
    getline(st,parkSize,'\r');

    intparkSize = stoi(parkSize);

    addPark(parksArray,parkName,parkState,intparkSize,length);
    length++;

    if (intparkSize > minArea)
        {
        os << fullLine << endl;
        }

    }
    printList(parksArray,length);

}

void addPark(Park parks[], string parkname, string state, int area, int length) {

	Park newPark;
	newPark.parkname = parkname;
	newPark.state = state;
	newPark.area = area;

	parks[length] = newPark;
}
void printList(const Park parks[], int length)
{
	for (int i = 0; i < length; i++)
	{
		Park park;
		park = parks[i];
		cout << park.parkname << " [" << park.state << "] area: " << park.area << endl;
	}
}
