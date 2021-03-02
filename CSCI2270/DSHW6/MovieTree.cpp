#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;


MovieTree::MovieTree()
{
  root = NULL;
}
MovieTree::~MovieTree()
{
  delete root;
}
void printMovieInventoryHelper(MovieNode* temp)
{

  if (temp->left != NULL)
  {
    printMovieInventoryHelper(temp->left);
  }
  cout << "Movie: " << temp->title << " " << temp->rating << endl;
  if (temp->right != NULL)
  {
    printMovieInventoryHelper(temp->right);
  }

}
void MovieTree::printMovieInventory()
{
   if (root == NULL)
   {
     cout << "Tree is Empty. Cannot print" << endl;
   }
   else
   {
     printMovieInventoryHelper(root);
   }
}
MovieNode* createNode(int ranking, string title, int year, float rating)
{
  MovieNode* newNode = new MovieNode(ranking, title, year, rating);
  newNode->left = NULL;
	newNode->right = NULL;
}
void addMovieNodeHelper(int ranking, string title, int year, float rating, MovieNode* ptr)
{
if (title < ptr->title)
{
  if(ptr->left != NULL)
  {
    addMovieNodeHelper(ranking, title, year, rating, ptr->left);
  }

  else
  {
    ptr->left = createNode(ranking, title, year, rating);
  }

}
else if (title > ptr->title)
{
  if(ptr->right != NULL)
  {
    addMovieNodeHelper(ranking, title, year, rating,ptr->right);
  }

  else
  {
    ptr->right = createNode(ranking, title, year, rating);
  }
}
}
void MovieTree::addMovieNode(int ranking, string title, int year, float rating)
{
  if (root == NULL)
  {
    root = createNode(ranking, title, year, rating);
  }
  else (addMovieNodeHelper(ranking, title, year, rating, root));
}
MovieNode* findMovieHelper(string title, MovieNode* tempT)
{
if (tempT)
{
    if (tempT->title == title)
    {
      return tempT;
    }
    else if (tempT->title > title)
      return findMovieHelper(title, tempT->left);
    else if (tempT->title < title)
      return findMovieHelper(title, tempT->right);
}
else
{
  return NULL;
}

}
void MovieTree::findMovie(string title)
{
  MovieNode* ret = findMovieHelper(title, root);
  if(ret)
  {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << ret->ranking << endl;
    cout << "Title :" << ret->title << endl;
    cout << "Year :" << ret->year << endl;
    cout << "rating :" << ret->rating << endl;
  }
  else
  {
    cout << "Movie not found." << endl;
  }
}
void queryMoviesHelp(float rating, int year, MovieNode* tempQ)
{
  if (tempQ->rating > rating && tempQ->year > year)
  {
    cout << tempQ->title << "(" << tempQ->year << ") " << tempQ->rating << endl;
  }

  if (tempQ->left != NULL)
  {
    queryMoviesHelp(rating, year, tempQ->left);
  }

  if (tempQ->right != NULL)
  {
    queryMoviesHelp(rating, year, tempQ->right);
  }
}
void MovieTree::queryMovies(float rating, int year)
{
  if (root == NULL)
  {
    cout << "Tree is Empty. Cannot query Movies" << endl;
  }
  else
  {
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;

    if (root->rating > rating && root->year > year)
    {
      cout << root->title << "(" << root->year << ") " << root->rating << endl;
    }

    queryMoviesHelp(rating, year, root->left);
    queryMoviesHelp(rating, year, root->right);
  }
}
float sumBT(MovieNode* tempA)
{
    if (tempA == NULL)
    {
    return 0;
    }
    return tempA->rating + sumBT(tempA->right) + sumBT(tempA->left);
}
float countBT(MovieNode* temp)
{
  int count = 1;
  if (temp->left != NULL){
    count += countBT(temp->left);
  }
  if (temp->right != NULL){
    count += countBT(temp->right);
  }
  return count;

}
void MovieTree::averageRating()
{

  if (root == NULL)
  {
  cout << "Average rating:0.0" << endl;
  }

  else
  {
    float average = sumBT(root) / countBT(root);
    cout << "Average rating:" << average << endl;
  }
}
