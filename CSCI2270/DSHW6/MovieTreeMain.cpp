#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{

MovieTree Tree;

ifstream fs;
fs.open(argv[1]);
string newWord;

string Sranking;
string title;
string Syear;
string Srating;

int ranking;
int year;
float rating;

while (getline(fs, newWord))
{
  stringstream s(newWord);
  getline(s, Sranking,',');
  getline(s, title,',');
  getline(s, Syear,',');
  getline(s, Srating,',');

  ranking = stoi(Sranking);
  year = stoi(Syear);
  rating = stof(Srating);

  Tree.addMovieNode(ranking, title, year, rating);
}

while(1){
int input;
displayMenu();
cin >> input;

if (input == 1)
{
  string titleT;
  cout << "Enter title:" << endl;
  getline(cin, titleT);
  cout << titleT << endl;
  Tree.findMovie(titleT);
}
if (input == 2)
{
  float rating;
  int year;
  cout << "Enter minimum rating:" << endl;
  cin >> rating;
  cout << "Enter minimum year:" << endl;
  cin >> year;
  Tree.queryMovies(rating, year);
}
if (input == 3)
{
  Tree.printMovieInventory();
}
if (input == 4)
{
  Tree.averageRating();
}
if (input == 5)
{
  cout << "Goodbye!" << endl;
  break;
}
}



  return 0;
}
void displayMenu()
{
cout << "======Main Menu======" << endl;
cout << "1. Find a movie" << endl;
cout << "2. Query movies" << endl;
cout << "3. Print the inventory" << endl;
cout << "4. Average Rating of movies" << endl;
cout << "5. Quit" << endl;
}
