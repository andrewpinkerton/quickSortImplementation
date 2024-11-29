// Name: Isaiah Adams
// C++ Program to demonstrate how to implement the quick
// sort algorithm
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

int partition(vector<int>& vec, int low, int high){

    // Selecting first element as the pivot
    int pivot = vec[low];

    // Index of the last element
    // It is used for swapping
    int i = high;

    for (int j = high; j > low; j--) {

        // If current element is greater than or
        // equal to pivot
        if (vec[j] > pivot) {
            swap(vec[i--], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[low], vec[i]);

    // Return the point of partition
    return i;
}

void quickSort(vector<int>& vec, int low, int high) {

    // base case of recursion
    if(low < high) {
        int part = partition(vec, low, high);

        // Recursive calls...
        quickSort(vec, low, part - 1);
        quickSort(vec, part + 1, high);
    }
}

int main() {
    vector<int> vec = { 10, 7, 8, 9, 1, 5 };
    int n = vec.size();

    // Measure time taken by Quicksort 
    auto startQuick = chrono::high_resolution_clock::now();

    // Calling quicksort for the vector vec
    quickSort(vec, 0, n - 1);

    auto stopQuick = chrono::high_resolution_clock::now();
    auto durationQuiSort = chrono::duration_cast<chrono::microseconds> (stopQuick - startQuick);

    // Printing the elements in the array
    for (auto i : vec) {
        cout << i << " ";
    }

    // Display time for Merge and Insertion Sort
    cout << endl << "\nduration of Merge Sort (in seconds): " << (durationQuiSort.count()) << " seconds.\n";

    return 0;
}