#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <numeric>

using namespace std;

int main() {
    // Initialize vector with 100,000 integers in descending order
    vector<int> data(100000);
    iota(data.rbegin(), data.rend(), 1);

    // Bubble Sort
    auto startTimeBubbleSort = chrono::high_resolution_clock::now();
    // Bubble Sort implementation here
    // ...
    auto endTimeBubbleSort = chrono::high_resolution_clock::now();

    // STL Sort
    auto startTimeSTLSort = chrono::high_resolution_clock::now();
    sort(data.begin(), data.end());
    auto endTimeSTLSort = chrono::high_resolution_clock::now();

    // Calculate durations
    auto durationBubbleSort = chrono::duration_cast<chrono::microseconds>(endTimeBubbleSort - startTimeBubbleSort);
    auto durationSTLSort = chrono::duration_cast<chrono::microseconds>(endTimeSTLSort - startTimeSTLSort);

    // Print execution times
    cout << "Bubble Sort Execution Time: " << durationBubbleSort.count() << " microseconds\n";
    cout << "STL Sort Execution Time: " << durationSTLSort.count() << " microseconds\n";

    // Print first and last 10 sorted integers
    cout << "First 10 sorted integers: ";
    for (int i = 0; i < 10; ++i) {
        cout << data[i] << " ";
    }
    cout << "\nLast 10 sorted integers: ";
    for (int i = data.size() - 10; i < data.size(); ++i) {
        cout << data[i] << " ";
    }

    return 0;
}
