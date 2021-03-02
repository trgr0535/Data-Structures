#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

MovieTree::MovieTree(){
  root = NULL;
}

void deleteLL(LLMovieNode* ptr)
{
  MovieNode* temp;
  while (ptr->next != NULL)
  {
    temp = ptr->next;
    delete ptr;
    ptr = temp;
  }
  delete ptr->next
  delete ptr;
}

void removeSubTree(TreeNode* ptr)
{
  if (ptr != NULL)
  {
    if (ptr->leftChild != NULL)
    {
      removeSubTree(ptr-leftChild);
    }
    if (ptr-rightChild != NULL)
    {
      removeSubTree(ptr->rightChild)
    }
    deleteLL(ptr->head)
    delete ptr;
  }
}
MovieTree::~MovieTree()
{
  removeSubTree(root);
}
void addLLNode(int ranking, string title, int year, float rating, TreeNode* Tree)
{
  LLMovieNode* LLNode = new LLMovieNode(ranking, title, year, rating);
  LLMovieNode* temp = Tree->head;
  LLMovieNode* LList = Tree->head;

  if (title < Tree->head->title)
  {
      LLNode->next = temp;
      Tree->head = LLNode;
  }
  else
  {
    while(temp != NULL)
      {
      if (temp->next == NULL)
        {
        temp->next = LLNode;
        break;
        }
      if (title < temp->next->title)
        {
        LLNode->next = temp->next;
        temp->next = LLNode;
        break;
        }
      temp = temp->next;
      }
    }
  }
TreeNode* createNode(int ranking, string title, int year, float rating, TreeNode* parent)
{
  TreeNode* NewTreeNode = new TreeNode;

  LLMovieNode* NewLLNode = new LLMovieNode(ranking, title, year, rating);

  NewTreeNode->head = NewLLNode;    // Pointer to the head node of a LL
  NewTreeNode->titleChar = title.at(0);              // Starting character of the titles stored in the linked list
  NewTreeNode->parent = parent;     // Pointer to its parent node in BST
  NewTreeNode->leftChild = NULL;  // Pointer to its leftChild in BST
  NewTreeNode->rightChild = NULL; // Pointer to its rightChild in BST

  return NewTreeNode;
}
void addMovieHelper(int ranking, string title, int year, float rating, TreeNode* ptr)
{
    if (title.at(0) == ptr->titleChar)
    {
      addLLNode(ranking, title, year, rating, ptr);
    }

    else if (title.at(0) < ptr->titleChar)
    {
      if(ptr->leftChild != NULL)
      {
        addMovieHelper(ranking, title, year, rating, ptr->leftChild);
      }
      else
      {
        ptr->leftChild = createNode(ranking, title, year, rating, ptr);
      }
    }
    else if (title.at(0) > ptr->titleChar)
    {
      if (ptr->rightChild != NULL)
      {
        addMovieHelper(ranking, title, year, rating, ptr->rightChild);
      }
      else
      {
        ptr->rightChild = createNode(ranking, title, year, rating, ptr);
      }
    }
}
void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
    if (root == NULL)
    {
      root = createNode(ranking, title, year, rating, NULL);
    }
    else
    {
    addMovieHelper(ranking, title, year, rating, root);
    }
  }
void printLL(LLMovieNode* m)
{
      LLMovieNode* temp = m;
      while (temp != NULL)
      {
        cout << " >> " << temp->title << " " << temp->rating << endl;
        temp = temp->next;
      }
    }
void PMIHelper(TreeNode* t)
{
    if (t->leftChild != NULL)
    {
      PMIHelper(t->leftChild);
    }
    cout << "Movies starting with letter: " << t->titleChar << endl;
    printLL(t->head);

    if (t->rightChild != NULL)
    {
      PMIHelper(t->rightChild);
    }
  }
void MovieTree::printMovieInventory()
{
    if (root != NULL)
    {
    PMIHelper(root);
    }
  }
void deleteLLNode(string title, LLMovieNode* LLhead, TreeNode* root)
{

  LLMovieNode* temp = LLhead;

  while (temp->next != NULL)
    {
      if (temp->next->title == title)
      {
        temp->next = temp->next->next;
        delete temp->next;
      }
      else
      {
        cout << "Movie: "<< title << " not found!, cannot delete." << endl;
      }
      temp = temp->next;
    }
}
TreeNode* minNode(TreeNode* ptr)
{
  if (ptr->leftChild != NULL)
  {
    minNode(ptr->leftChild);
  }
  else
  {
  return ptr;
  }
}
void deleteMovieHelper(string title, TreeNode* ptr)
{
    if (ptr == NULL)
    {
      cout << "item not found" << endl;
    }
    else if (title.at(0) < ptr->titleChar)
    {
      deleteMovieHelper(title, ptr->leftChild);
    }
    else if (title.at(0) > ptr->titleChar)
    {
      deleteMovieHelper(title, ptr->rightChild);
    }
    else
    {
    deleteLLNode(title, ptr->head, root);

    if (ptr->head != NULL)
    {
      if (ptr->rightChild == ptr-> leftChild)
        {
          delete ptr;
          ptr == NULL;
        }
      else if (ptr->rightChild == NULL)
        {
          if (ptr->parent->leftChild ==  ptr)
          {
            ptr->parent->leftChild = ptr->leftChild;
            delete ptr;
          }
          else
          {
            ptr->parent->rightChild = ptr->leftChild;
            delete ptr;
          }
        }
      else if (ptr->leftChild == NULL)
        {
          if (ptr->parent->rightChild ==  ptr)
          {
            ptr->parent->rightChild = ptr->rightChild;
            delete ptr;
          }
          else
          {
            ptr->parent->leftChild = ptr->rightChild;
            delete ptr;
          }
        }
        else
        {
        TreeNode* min = minNode(ptr->rightChild);

        LLMovieNode* tempLL = min->head;
        char tempChar = min->head->title.at(0);

        ptr->head = tempLL;

        deleteMovieHelper(min->head->title, ptr);

        ptr->titleChar = tempChar;


        }
      }
      }
}
void MovieTree::deleteMovie(std::string title)
{
  if (root == NULL)
  {
    cout << "Movie: " << title <<" not found, cannot delete." << endl;
  }
  else
  {
    deleteMovieHelper(title, root);
  }
}
