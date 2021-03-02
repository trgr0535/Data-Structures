
#include"DSHW4Header.hpp";

using namespace std;

void displayMenu();

int main(int argc, char* argv[])
{
  int k = 1;

CountryNetwork CountryNet;

  while (k == 1)
  {
      int x;

      displayMenu();
      cin >> x;

      if (x == 1)
      {
      CountryNet.loadDefaultSetup();
      CountryNet.printPath();
      }
      else if (x == 2)
      {
      CountryNet.printPath();
      }
      else if (x == 3)
      {
      string newCountryName;
      string previousCountry;

      cout << "Enter a new country name:" << endl;
      cin >> newCountryName;
      cout << "Enter the previous country name (or First):" << endl;
      cin >> previousCountry;

      Country* tempPtr;
      tempPtr = CountryNet.searchNetwork(previousCountry);

          if (previousCountry == "First")
          {
            CountryNet.insertCountry(NULL, newCountryName);
          }
          else if (tempPtr == NULL)
          {
            cout << "INVALID(previous country name)...Please enter a VALID previous country name!" << endl;
            cin >> previousCountry;
            tempPtr = CountryNet.searchNetwork(previousCountry);
            CountryNet.insertCountry(tempPtr, newCountryName);
          }
          else
          {
            CountryNet.insertCountry(tempPtr, newCountryName);
          }
        CountryNet.printPath();
      }
      else if (x == 4)
      {
        string countryDel;
        cout << "Enter a country name:" << endl;
        cin >> countryDel;
        CountryNet.deleteCountry(countryDel);
        CountryNet.printPath();


      }
      else if(x == 5)
      {
        CountryNet.reverseEntireNetwork();
        CountryNet.printPath();
      }
      else if (x == 6)
      {
        int N;
        cout << "Enter the count of values to be rotated:" << endl;
        cin >> N;
        CountryNet.rotateNetwork(N);
        CountryNet.printPath();
      }
      else if (x == 7)
      {
      cout << "Network before deletion" << endl;
      CountryNet.printPath();
      CountryNet.deleteEntireNetwork();
      cout <<"Network after deletion" << endl;
      CountryNet.printPath();
      }
      else
      {
      cout << "Quitting... cleaning up path:" << endl;
    CountryNet.printPath();
    CountryNet.deleteEntireNetwork();
      cout << "Path cleaned" << endl;
      cout << "Goodbye!" << endl;
      exit(0);
      }
  }
      return 0;
}

void displayMenu()
{
    cout << "Select a numerical option:" << endl;
    cout << "+=====Main Menu=========+" << endl;
    cout << " 1. Build Network " << endl;
    cout << " 2. Print Network Path " << endl;
    cout << " 3. Add Country " << endl;
    cout << " 4. Delete Country " << endl;
    cout << " 5. Reverse Network" << endl;
    cout << " 6. Rotate Network" << endl;
    cout << " 7. Clear Network " << endl;
    cout << " 8. Quit " << endl;
    cout << "+-----------------------+" << endl;
    cout << "#> ";
}
CountryNetwork::CountryNetwork()
{
 head = NULL;
 }
/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
  if (head == NULL)
  {
  return true;
  }
  else
  {
  return false;
  }

}
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
  Country* newCountry = new Country;
  Country* temp = new Country;
  newCountry->next = NULL;
  newCountry->name = countryName;
    if (previous == NULL)
    {

      temp = head;
      head = newCountry;

      head->next = temp;


    cout << "adding: " << countryName << " (HEAD)" << endl;


    }
    else
    {
      temp = previous->next;
      previous->next = newCountry;
      newCountry->next = temp;
      cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
    }
  }
void CountryNetwork::deleteCountry(string countryName)
{
 Country* temp;
 Country* curr;
 temp = head;

 if(head->name == countryName)
 {
     head = head->next;
     delete(temp);
     temp = head;
 }

 else
 {
     while(temp != NULL && temp->name != countryName)
     {
     curr = temp;
     temp = temp->next;
     }

     if (temp == NULL)
     {
     cout << "Country does not exist." << endl;
     }
     else
     {
     curr->next = temp->next;
     delete(temp);
     }
 }
 }
void CountryNetwork::loadDefaultSetup()
{
     insertCountry(head,"United States");
     insertCountry(searchNetwork("United States"),"Canada");
     insertCountry(searchNetwork("Canada"),"Brazil");
     insertCountry(searchNetwork("Brazil"),"India");
     insertCountry(searchNetwork("India"),"China");
     insertCountry(searchNetwork("China"),"Australia");
 }
Country* CountryNetwork::searchNetwork(string countryName)
{
     Country* checkCountry;
     checkCountry = head;
     while((checkCountry != NULL) && (checkCountry->name != countryName))
     {
         checkCountry = checkCountry->next;
     }
     if (checkCountry == NULL)
     {
     return NULL;
     }
     else
     {
     return checkCountry;
     }
 }
void CountryNetwork::deleteEntireNetwork()
{
    Country* temp;
    temp = head;
    if (head == NULL)
    {
        return;
    }
    else
    {
    while (temp != NULL)
    {
        head = temp->next;
        cout << "deleting: " << temp->name << endl;
        delete temp;
        temp = head;

    }
    delete head;
    cout << "Deleted network" << endl;
    }
}
void CountryNetwork :: rotateNetwork(int n)
{
   Country* temp;
   Country* splitL;
   Country* splitR;
   Country* last;

   int count = 0;

   temp = head;

   while(temp != NULL)
   {
   temp = temp->next;
   count++;
   }

   temp = head;

   if(head == NULL)
   {
   cout << "Linked List is Empty" << endl;
   }
   else if(count < n)
   {
   cout << "Rotate not possible" << endl;
   }
   else
   {
     for (int i = 0; i<n; i++)
     {
     splitL = temp;
     temp = temp->next;
     splitR = temp;
     }

     temp = head;

     while(temp != NULL)
     {
     last = temp;
     temp = temp->next;
     }

     last->next = head;
     splitL->next = NULL;
     head = splitR;
     cout << "Rotate Complete" << endl;
   }
 }
void CountryNetwork::reverseEntireNetwork()
{
Country* previous;
Country* current;
Country* after;
previous = NULL;
current = head;

while(current != NULL)
{
after = current->next;

current->next = previous;
previous = current;
current = after;
}
head = previous;
}

void CountryNetwork::printPath()
{
Country* ptr;
ptr = head;
cout << "== CURRENT PATH =="<< endl;
if (head ==NULL)
{
  cout << "nothing in path" << endl;
}
else
  {
    while (ptr != NULL)
    {
    cout << ptr->name << " -> ";
    ptr = ptr->next;
    }
  cout << "NULL" << endl;
  }
cout << "===" << endl;
}
