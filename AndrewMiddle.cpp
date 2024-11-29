// Name: Andrew Pinkerton
// C++ Program to demonstrate how to implement the quick
// sort algorithm

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <vector>

using namespace std;

int partition(vector<int>& vec, int low, int high) {
    int mid = low + (high - low) / 2;
    int pivot = vec[mid];

    swap(vec[mid], vec[high]);

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] >= pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);

    return (i + 1);
}

void quickSort(vector<int>& vec, int low, int high) {

    // Base case of recursion
    if (low < high)
    {
        int part = partition(vec, low, high);

        //Recursive calls...
        quickSort(vec, low, part - 1); // left side
        quickSort(vec, part + 1, high); // right side
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