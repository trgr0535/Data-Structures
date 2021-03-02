#include "LinearProbe.cpp"
#include "BST.cpp"
#include "LinkedList.cpp"
#include "CuckooHash.cpp"


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <chrono>



using namespace std;

void displayMainMenu();
void displayMenu1();

double* average(double *a, double n){
  double sum = 0;
  double temp = 0;
  for (int i = 0; i < 4; i++){
    temp = a[i];
    sum =  temp / 100;
     a[i] = sum;
   }
  return a;
}


int main(int argc, char* argv[]) {
	ifstream insfile, sdfile;
	insfile.open("insert.csv");
	sdfile.open("deletesearch.csv");

	HashTableLP LProbe;
	HashTableLL LinkedL;
	BinarySearchTreeHT BiST;
  cuckooHash CuHa;

  vector<int> ranarr;
  int tempvar = 0;
  for (int i = 0; i < 100; i++){
    tempvar = rand() % 1000 + 1;
    ranarr.push_back(tempvar);
  }

	vector<int> sdarr;
	string numins, numsd;
  int temp;
  int count = 0;
	while (getline(sdfile, numsd, ',')){
		temp = stoi(numsd);
		sdarr.push_back(temp);
	}

	int mainNumSel = 0;
	int numSelect = 0;
	while (mainNumSel != 3){
		displayMainMenu();
		numSelect = 0;
		cout << "# ";
		cin >> mainNumSel;
		if (mainNumSel == 1){
      ifstream dataA;
      dataA.open("dataSetA.csv");

      string numarrA;
      vector<int> arrA;

      while (getline(dataA, numarrA, ',')){
        int temp = stoi(numarrA);
        arrA.push_back(temp);
      }

			while (numSelect != 5){
				displayMenu1();
				cout << "# ";
				cin >> numSelect;

        double lfarr[6] = {0.1, 0.2, 0.5, 0.7, 0.9, 1.0};

				if (numSelect == 1){
          int startTime, endTime, tempins, intoarr;
          double execTime, n, lftemp;
          double timemat[4];
          int count = 0;
          double loadf = 0;
          for (int i = 0; i < 6; i++){
            lftemp = lfarr[i];
            while (loadf < lftemp){
                loadf = LProbe.lf();
                intoarr = arrA[count];
                LProbe.Hash1LP(intoarr);
                count++;
            }

            // Insert Hash1
            startTime = clock();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              LProbe.Hash1LP(tempins);
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            timemat[0] = execTime;

            // Insert Hash2
            startTime = clock();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              LProbe.Hash2LP(tempins);
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            timemat[1] = execTime;

            // Search
            startTime = clock();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              LProbe.searchLP(tempins);
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            timemat[2] = execTime;

            // Delete
            startTime = clock();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              LProbe.deleteLP(tempins);
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            timemat[3] = execTime;

            n = ranarr.size();
            double* timeave = average(timemat, n);

            cout << "=======================Using a load factor of "<< lfarr[i] << "=========================" << endl;
            cout << "The average time for inserting 100 elements (w/ Hash1) is : " << timeave[1] << " seconds" << endl;
            cout << "The average time for inserting 100 elements (w/ Hash2) is : " << timeave[2] << " seconds" << endl;
            cout << "The average time for search 100 elements is               : " << timeave[3] << " seconds" << endl;
            cout << "The average time for delete 100 elements is               : " << timeave[4] << " seconds" << endl;
            cout << endl;
          }
        }

				if (numSelect == 2){
          std::chrono::high_resolution_clock::time_point startTime;
          std::chrono::high_resolution_clock::time_point endTime;
          std::chrono::duration<double> execTime;
          int tempins, intoarr;
          double n, lftemp;
          double timemat[4];
          int count = 0;
          double loadf = 0;
          for (int i = 0; i < 6; i++){
            lftemp = lfarr[i];
            while (loadf < lftemp){
                loadf = LinkedL.lf();
                intoarr = arrA[count];
                LinkedL.Hash1LL(intoarr);
                count++;
            }

            // Insert Hash1
            startTime = std::chrono::high_resolution_clock::now();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              LinkedL.Hash1LL(tempins);
            }
            endTime = std::chrono::high_resolution_clock::now();
            execTime = std::chrono::duration_cast<std::chrono::duration<double>>(endTime-startTime);
            auto msExecTime = std::chrono::duration_cast <std::chrono::nanoseconds>(execTime);
            timemat[0] = (int)msExecTime.count()/100;

            // Insert Hash2
            startTime = std::chrono::high_resolution_clock::now();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              LinkedL.Hash2LL(tempins);
            }
            endTime = std::chrono::high_resolution_clock::now();
            execTime = std::chrono::duration_cast<std::chrono::duration<double>>(endTime-startTime);
            msExecTime = std::chrono::duration_cast <std::chrono::nanoseconds>(execTime);
            timemat[1] = (int)msExecTime.count()/100;

            // Search
            startTime = std::chrono::high_resolution_clock::now();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              LinkedL.searchLL(tempins);
            }
            endTime = std::chrono::high_resolution_clock::now();
            execTime = std::chrono::duration_cast<std::chrono::duration<double>>(endTime-startTime);
            msExecTime = std::chrono::duration_cast <std::chrono::nanoseconds>(execTime);
            timemat[2] = (int)msExecTime.count()/100;

            // Delete
            startTime = std::chrono::high_resolution_clock::now();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              LinkedL.deleteLL(tempins);
            }
            endTime = std::chrono::high_resolution_clock::now();
            execTime = std::chrono::duration_cast<std::chrono::duration<double>>(endTime-startTime);
            // msExecTime = std::chrono::duration_cast <std::chrono::nanoseconds>(execTime);
            timemat[3] = (int)execTime.count()/100;

            // n = ranarr.size();
            // double* timeave = average(timemat, n);

            cout << "=======================Using a load factor of "<< lfarr[i] << "=========================" << endl;
            cout << "The average time for inserting 100 elements (w/ Hash1) is : " << timemat[1] << " seconds" << endl;
            cout << "The average time for inserting 100 elements (w/ Hash2) is : " << timemat[2] << " seconds" << endl;
            cout << "The average time for search 100 elements is               : " << timemat[3] << " seconds" << endl;
            cout << "The average time for delete 100 elements is               : " << timemat[4] << " seconds" << endl;
            cout << endl;
          }
				}

				if (numSelect == 3){
          cout << "Here1" << endl;
          int startTime, endTime, tempins, intoarr;
          double execTime, n, lftemp;
          double timemat[4];
          int count = 0;
          double loadf = 0;
          for (int i = 0; i < 6; i++){
            lftemp = lfarr[i];
            cout << "Here2" << endl;

            while (loadf < lftemp){
              loadf = LinkedL.lf();
              cout <<  loadf << endl;

              intoarr = arrA[count];
              BiST.Hash1BST(intoarr);
              count++;
            }

            // Insert Hash1
            cout << "Here3" << endl;
            startTime = clock();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              BiST.Hash1BST(tempins);
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            timemat[0] = execTime/100;

            // Insert Hash2
            cout << "Here4" << endl;
            startTime = clock();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              BiST.Hash2BST(tempins);
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            timemat[1] = execTime/100;

            // Search
            cout << "Here5" << endl;
            startTime = clock();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              BiST.searchHT(tempins);
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            timemat[2] = execTime/100;

            // Delete
            cout << "Here6" << endl;
            startTime = clock();
            for (int j = 0; j < ranarr.size(); j++){
              tempins = ranarr[j];
              BiST.deleteNum(tempins);
            }
            endTime = clock();
            execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
            timemat[3] = execTime/100;

            // n = ranarr.size();
            // double* timeave = average(timemat, n);

            cout << "=======================Using a load factor of "<< lfarr[i] << "=========================" << endl;
            cout << "The average time for inserting 100 elements (w/ Hash1) is : " << timemat[1] << " seconds" << endl;
            cout << "The average time for inserting 100 elements (w/ Hash2) is : " << timemat[2] << " seconds" << endl;
            cout << "The average time for search 100 elements is               : " << timemat[3] << " seconds" << endl;
            cout << "The average time for delete 100 elements is               : " << timemat[4] << " seconds" << endl;
            cout << endl;
          }
        }

				if (numSelect == 4){
          // int startTime, endTime, tempins, intoarr;
          // double execTime, n, lftemp;
          // double *timeave;
          // double timemat [3][100];
          // int count = 0;
          // double loadf = 0;
          // for (int i = 0; i < 6; i++){
          //   lftemp = lfarr[i];
          //   while (loadf < lftemp){
          //     loadf = BiST.lf();
          //     intoarr = arrA[count];
          //     LinkedL.Hash1LL(intoarr);
          //     count++;
          //   }
          //
          //   for (int j = 0; j < 100; j++){
          //     // tempins = insarr[j];
          //     tempins = 2003;
          //
          //     startTime = clock();
          //       CuHa.hash(tempins);
          //     endTime = clock();
          //     execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
          //     timemat[1][j] = execTime;
          //
          //     timemat[3][j] = 0;
          //
          //     // Search
          //     startTime = 0;
          //     endTime = 0;
          //     startTime = clock();
          //       CuHa.lookup(tempins);
          //     endTime = clock();
          //
          //     execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
          //     timemat[3][j] = execTime;
          //
          //
          //     // Delete
          //     startTime = 0;
          //     endTime = 0;
          //     startTime = clock();
          //       CuHa.deleteItem(tempins);
          //     endTime = clock();
          //
          //     execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
          //     timemat[4][j] = execTime;
          //   }
          //   n = 100;
          //   timeave = average(timemat, n);
          //   cout << "=======================Using a load factor of "<< lfarr[i] << "=========================" << endl;
          //   cout << "The average time for inserting 100 elements (w/ Hash) is  : " << timeave[1] << " seconds" << endl;
          //   cout << "The average time for search 100 elements is               : " << timeave[3] << " seconds" << endl;
          //   cout << "The average time for delete 100 elements is               : " << timeave[4] << " seconds" << endl;
          //   cout << endl;
          // }
				}

				if (numSelect == 5){
					break;
				}
			}
		}
		if (mainNumSel == 2){
      ifstream dataC;
      dataC.open("dataSetC_alt.csv");

      string numarrC;
      vector<int> arrC;

      while (getline(dataC, numarrC, ',')){
        int temp = stoi(numarrC);
        arrC.push_back(temp);
      }

      while (numSelect != 5){
        displayMenu1();
        cout << "# ";
        cin >> numSelect;

        int optSelect = 0;
        if (numSelect == 1){

        }

        if (numSelect == 2){

        }

        if (numSelect == 3){

        }

        if (numSelect == 4){

        }

        if (numSelect == 5){
          break;
        }
      }
		}

		if (mainNumSel == 3){
			cout << "===============================================" << endl;
			cout << endl;
			cout << "Quitting the program...." << endl;
			cout << "Quit!" << endl;
		}
	}
	return 0;
}

void displayMainMenu(){
	cout << "===================Main Menu===================" << endl;
  cout << "1. Data Set A" << endl;
  cout << "2. Data Set B" << endl;
  cout << "3. Quit" << endl;
}

void displayMenu1(){
  cout << "======Implementing the Hash Table Methods======" << endl;
  cout << "1. Hash Data (Linear Probing)" << endl;
  cout << "2. Hash Data (Linked List)" << endl;
	cout << "3. Hash Data (Binary Search Tree)" << endl;
	cout << "4. Hash Data (Cuckoo Hash)" << endl;
  cout << "5. Go back" << endl;
}
