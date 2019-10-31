#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"
using namespace std;

int main() {
    int seed;
    int limit;
    int n = 1;

    cout << "Please enter the seed" << endl;
    cin >> seed;
    cout << "Please enter the iterations:" << endl;
    cin >> limit;
    srand(seed);

    while (n <= limit) {
        LinkedList list;
        vector<int> v(100 * n);

        // generate vector of random integers
        for (int i = 0; i < v.size(); i++) {
            v[i] = rand() % 100;
        }

        // Copy Unsorted Values to Linked List
        for (int i = 0; i < v.size(); i++) {
            list.Append(v[i]);
        }

        // binary insertion sort
        clock_t start_insertionSort = clock();
        insertionSort(v, v.size());
        clock_t end_insertionSort = clock();

        // check if sorted
        for (int i = 1; i < v.size(); i++) {
            assert(v[i-1] <= v[i]);
        }

        // print out the  sorted list
        cout << "Sorted Vector:" << endl;
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << endl;

        // FINISH ME

        // Sort Linked List
        clock_t start_listInsertionSort = clock();
        list.ListInsertionSort();
        clock_t end_listInsertionSort = clock();

        // Print out the Sorted Linked List
        cout << "Sorted Linked List:" << endl;
        list.PrintList();
        cout << endl;

        // Calculate the Times
        double elapsed_insertionSort = double(end_insertionSort - start_insertionSort) / CLOCKS_PER_SEC;
        double elapsed_listInsertionSort = double(end_listInsertionSort - start_listInsertionSort) / CLOCKS_PER_SEC;

        // Print  Times
        cout << endl << " Time of insertionSort:" << elapsed_insertionSort<<endl;
        cout << endl << " Time of listInsertion:" << elapsed_listInsertionSort << endl;
        cout << endl;

        n++;
    }
}

