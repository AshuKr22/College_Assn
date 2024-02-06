#include<bits/stdc++.h>
using namespace std;

#include <chrono>
using namespace chrono;

void bubbleSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
}

int main() {
    // Create a vector with random integers
    vector<int> data;
    for(int i=1000;i>=1;i--)
    {
        data.push_back(i);
    }
    // Measure time for Bubble Sort
    auto startBubble = high_resolution_clock::now();
    bubbleSort(data);
    auto stopBubble = high_resolution_clock::now();
    auto durationBubble = duration_cast<microseconds>(stopBubble - startBubble);

  
    cout << "\nTime taken by Bubble Sort: " << durationBubble.count() << " microseconds\n";

    // Measure time for Insertion Sort
    auto startInsertion = high_resolution_clock::now();
    insertionSort(data);
    auto stopInsertion = high_resolution_clock::now();
    auto durationInsertion = duration_cast<microseconds>(stopInsertion - startInsertion);
    cout << "\nTime taken by Insertion Sort: " << durationInsertion.count() << " microseconds\n";

      auto startSelection = high_resolution_clock::now();
    selectionSort(data);
    auto stopSelection = high_resolution_clock::now();
    auto durationSelection = duration_cast<microseconds>(stopSelection - startSelection);
     cout << "\nTime taken by Selection Sort: " << durationSelection.count() << " microseconds\n";


}