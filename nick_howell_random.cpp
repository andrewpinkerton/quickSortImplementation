// Name: Nicholas Howell

// C++ Program to demonstrate how to implement the quick
// sort algorithm
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>
using namespace std;

int partition(vector<int>& vec, int low, int high) {

    // Selecting last element as the pivot
    std::srand(std::time(0));
    int RandIndex = rand() % (high - low) + low; //generates a random number between 0 and size of the array
    swap(vec[RandIndex], vec[high]);

    int pivot = vec[high];

    // Index of element just before the last element
    // It is used for swapping
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {

        // If current element is smaller than or
        // equal to pivot
        if (vec[j] <= pivot) 
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    // Put pivot to its position
    swap(vec[i + 1], vec[high]);

    // Return the point of partition
    return (i + 1);
}

void quickSort(vector<int>& vec, int low, int high) {

    // Base case of recursion
    if (low < high) 
    {
        int part = partition(vec, low, high);

        // Recursive calls...
        quickSort(vec, low, part - 1); // Left side
        quickSort(vec, part + 1, high); // Right side
    }

}

void printVector(vector<int>& vec) 
{
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

vector<int> generateRandomVector(int length) 
{
    vector<int> vec = {};
    std::srand(std::time(0));
    for (int i = 0; i < length; i++) 
    {
        vec.push_back(rand() % 100);
    }
    return vec;
}

void runWithTime(vector<int>& vec) 
{
    auto clockStart = std::chrono::high_resolution_clock::now();
    quickSort(vec, 0, vec.size() - 1);
    auto clockStop = std::chrono::high_resolution_clock::now();
    auto clockDuration =
        std::chrono::duration_cast<std::chrono::microseconds>
        (clockStop - clockStart);
    printVector(vec);
    cout << "Time: " << clockDuration.count() << endl << endl;
}

int main() {
    vector<int> vec = { 10, 7, 8, 9, 1, 5 };
    vector<int> midVec = generateRandomVector(50);
    vector<int> largeVec = generateRandomVector(1000);

    runWithTime(vec);
    runWithTime(midVec);
    runWithTime(largeVec);
    
    return 0;
}