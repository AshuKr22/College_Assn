#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

// Helper function to heapify a subtree rooted with the given node
template <typename T>
void heapify(vector<T>& arr, int n, int i, bool isMaxHeap) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMaxHeap && left < n && arr[left] > arr[largest])
        largest = left;

    if (isMaxHeap && right < n && arr[right] > arr[largest])
        largest = right;

    if (!isMaxHeap && left < n && arr[left] < arr[largest])
        largest = left;

    if (!isMaxHeap && right < n && arr[right] < arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, isMaxHeap);
    }
}

// Main function for heap sort
template <typename T>
void heapSort(vector<T>& arr, bool isMaxHeap) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }
}

 int main() {
    ifstream inputFile("index.txt");

    if (!inputFile.is_open()) {
        cerr << "Unable to open the input file." << endl;
        return 1;
    }

    vector<int> input;
    int value;

    // Read values from the input file
    while (inputFile >> value) {
        input.push_back(value);
    }

    // Close the input file
    inputFile.close();

    // Perform Min Heap sort (ascending order)
    auto startMinHeap = chrono::high_resolution_clock::now();
    heapSort(input, false);
    auto endMinHeap = chrono::high_resolution_clock::now();

    // Output sorted result and time taken
    cout << "Decending Order (Min Heap): ";
    for (const auto& num : input) {
        cout << num << " ";
    }
    cout << endl;

    auto durationMinHeap = chrono::duration_cast<chrono::microseconds>(endMinHeap - startMinHeap);
    cout << "Time taken (Min Heap): " << durationMinHeap.count() << " microseconds" << endl;

    // Perform additional Min Heap sort for descending order
    auto startMinHeapDescending = chrono::high_resolution_clock::now();
    heapSort(input, false);
    auto endMinHeapDescending = chrono::high_resolution_clock::now();

    // Output sorted result and time taken
    cout << "Ascending Order (Min Heap): ";
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    auto durationMinHeapDescending = chrono::duration_cast<chrono::microseconds>(endMinHeapDescending - startMinHeapDescending);
    cout << "Time taken (Descending Min Heap): " << durationMinHeapDescending.count() << " microseconds" << endl;

    // Perform Max Heap sort (descending order)
    auto startMaxHeap = chrono::high_resolution_clock::now();
    heapSort(input, true);
    auto endMaxHeap = chrono::high_resolution_clock::now();

    // Output sorted result and time taken
    cout << "Ascending Order (Max Heap): ";
    for (const auto& num : input) {
        cout << num << " ";
    }
    cout << endl;

    auto durationMaxHeap = chrono::duration_cast<chrono::microseconds>(endMaxHeap - startMaxHeap);
    cout << "Time taken (Max Heap): " << durationMaxHeap.count() << " microseconds" << endl;

    // Perform additional Max Heap sort for ascending order
    auto startMaxHeapAscending = chrono::high_resolution_clock::now();
    heapSort(input, true);
    auto endMaxHeapAscending = chrono::high_resolution_clock::now();

    // Output sorted result and time taken
    cout << "Descending Order (Max Heap): ";
    for (const auto& num : input) {
        cout << num << " ";
    }
    cout << endl;

    auto durationMaxHeapAscending = chrono::duration_cast<chrono::microseconds>(endMaxHeapAscending - startMaxHeapAscending);
    cout << "Time taken (Ascending Max Heap): " << durationMaxHeapAscending.count() << " microseconds" << endl;

    return 0;
}



#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;

// Helper function to heapify a subtree rooted with the given node
template <typename T>
void heapify(vector<T>& arr, int n, int i, bool isMaxHeap) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (isMaxHeap && left < n && arr[left] > arr[largest])
        largest = left;

    if (isMaxHeap && right < n && arr[right] > arr[largest])
        largest = right;

    if (!isMaxHeap && left < n && arr[left] < arr[largest])
        largest = left;

    if (!isMaxHeap && right < n && arr[right] < arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest, isMaxHeap);
    }
}

// Main function for heap sort
template <typename T>
void heapSort(vector<T>& arr, bool isMaxHeap) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, isMaxHeap);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, isMaxHeap);
    }
}

 int main() {
    ifstream inputFile("index.txt");

    if (!inputFile.is_open()) {
        cerr << "Unable to open the input file." << endl;
        return 1;
    }

    vector<int> input;
    int value;

    // Read values from the input file
    while (inputFile >> value) {
        input.push_back(value);
    }

    // Close the input file
    inputFile.close();

    // Perform Min Heap sort (ascending order)
    auto startMinHeap = chrono::high_resolution_clock::now();
    heapSort(input, false);
    auto endMinHeap = chrono::high_resolution_clock::now();

    // Output sorted result and time taken
    cout << "Decending Order (Min Heap): ";
    for (const auto& num : input) {
        cout << num << " ";
    }
    cout << endl;

    auto durationMinHeap = chrono::duration_cast<chrono::microseconds>(endMinHeap - startMinHeap);
    cout << "Time taken (Min Heap): " << durationMinHeap.count() << " microseconds" << endl;

    // Perform additional Min Heap sort for descending order
    auto startMinHeapDescending = chrono::high_resolution_clock::now();
    heapSort(input, false);
    auto endMinHeapDescending = chrono::high_resolution_clock::now();

    // Output sorted result and time taken
    cout << "Ascending Order (Min Heap): ";
    for (auto it = input.rbegin(); it != input.rend(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    auto durationMinHeapDescending = chrono::duration_cast<chrono::microseconds>(endMinHeapDescending - startMinHeapDescending);
    cout << "Time taken (Descending Min Heap): " << durationMinHeapDescending.count() << " microseconds" << endl;

    // Perform Max Heap sort (descending order)
    auto startMaxHeap = chrono::high_resolution_clock::now();
    heapSort(input, true);
    auto endMaxHeap = chrono::high_resolution_clock::now();

    // Output sorted result and time taken
    cout << "Ascending Order (Max Heap): ";
    for (const auto& num : input) {
        cout << num << " ";
    }
    cout << endl;

    auto durationMaxHeap = chrono::duration_cast<chrono::microseconds>(endMaxHeap - startMaxHeap);
    cout << "Time taken (Max Heap): " << durationMaxHeap.count() << " microseconds" << endl;

    // Perform additional Max Heap sort for ascending order
    auto startMaxHeapAscending = chrono::high_resolution_clock::now();
    heapSort(input, true);
    auto endMaxHeapAscending = chrono::high_resolution_clock::now();

    // Output sorted result and time taken
    cout << "Descending Order (Max Heap): ";
    for (const auto& num : input) {
        cout << num << " ";
    }
    cout << endl;

    auto durationMaxHeapAscending = chrono::duration_cast<chrono::microseconds>(endMaxHeapAscending - startMaxHeapAscending);
    cout << "Time taken (Ascending Max Heap): " << durationMaxHeapAscending.count() << " microseconds" << endl;

    return 0;
}