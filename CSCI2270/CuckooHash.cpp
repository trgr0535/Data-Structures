#include<iostream>
#include<vector>
#include<cmath>

// g++ CuckooHash.cpp -o CuckooHash.exe

using namespace std;

static const int M = 17;

int hash1(int k, int size){
	return k % size;
}

int hash2(int k, int size){
  int hash = floor(k / size);
  return hash % size;
}

class cuckooHash
{
private:
  int tableOne[M];
  int tableTwo[M];

public:
cuckooHash();
void hash(int k);
bool lookup(int k);
void deleteItem(int k);
void printListOne();
void printListTwo();
};

int main(){
  cuckooHash object;

  object.hash(0);
  object.hash(1);
  object.hash(2);
  object.hash(3);
  object.hash(4);
  object.hash(5);
  object.hash(6);
  object.hash(7);
  object.hash(8);
  object.hash(9);
  object.hash(10);
  object.hash(15);
  object.hash(18);
  object.hash(225);


  object.printListOne();
  object.printListTwo();

  return 0;
}

cuckooHash::cuckooHash()
{
  for(int i=0; i<M; i++){
    tableOne[i] = -1;
  }
  for(int i=0; i<M; i++){
    tableTwo[i] = -1;
  }
}
void cuckooHash::hash(int k)
{
  int indexOne = hash1(k, M);
  int indexTwo = hash2(k, M);
  if (tableOne[indexOne] == -1){
    tableOne[indexOne] = k;
  }
  else if(tableTwo[indexTwo] == -1){
  tableTwo[indexTwo] = k;
  }
  else{
  bool success;
  if(success!=true){
      int replaceOne = hash2(tableOne[indexOne], M);
      int replaceTwo;
      int temp;
      int tempTwo;

      temp = tableTwo[replaceOne];
      tableTwo[replaceOne] = tableOne[indexOne];
      tableOne[indexOne] = k;

      if (temp == -1){
        success = true;
      }

      replaceTwo = hash1(temp, M);
      tempTwo = tableOne[replaceTwo];
      tableOne[replaceTwo] = temp;

      if (tempTwo == -1){
          success == true;
      }
      else{
        hash(tempTwo);
      }
    }
  }
}
bool cuckooHash::lookup(int k){
  int indexOne = hash1(k, M);
  int indexTwo = hash2(k, M);
  if(tableOne[indexOne] == k){
    return true;
  }

  else if(tableTwo[indexTwo] == k){
    return true;
  }
  else
  return false;
}
void cuckooHash::deleteItem(int k){
    int indexOne = hash1(k, M);
    int indexTwo = hash2(k, M);
    if(tableOne[indexOne] == k){
      tableOne[indexOne] = -1;
      cout << k << "deleted" << endl;
    }
    else if(tableTwo[indexTwo] == k){
      tableTwo[indexTwo] == -1;
      cout << k << "deletet" << endl;
    }
    else
    cout << "The number is not in the list" << endl;
}

void cuckooHash::printListOne(){
cout << "Table one is" << endl;
  for (int i = 0; i<M; i++){
    cout << tableOne[i] << ", ";
  }
  cout << endl;
}
void cuckooHash::printListTwo(){
cout << "Table Two is" << endl;
  for (int i = 0; i<M; i++){
    cout << tableTwo[i] << ", ";
  }
  cout << endl;
}
