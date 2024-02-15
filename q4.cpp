#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

// Shell sort function
void shellSort(vector<int>& arr) {
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j;

            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// Merge function for mergesort
void merge(vector<int>& arr, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> left(n1);
    vector<int> right(n2);

    for (int i = 0; i < n1; ++i) {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < n2; ++j) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            ++i;
        } else {
            arr[k] = right[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = left[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = right[j];
        ++j;
        ++k;
    }
}

// Mergesort function
void mergeSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

// Quicksort partition function
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quicksort function
void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    // Read 1000 elements from the input file
    ifstream inputFile("index.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening the input file." << endl;
        return 1;
    }

    vector<int> arr_quick, arr_merge, arr_shell;
    int num;

    for (int i = 0; i < 1000 && inputFile >> num; ++i) {
        arr_quick.push_back(num);
        arr_merge.push_back(num);
        arr_shell.push_back(num);
    }

    inputFile.close();

    // Measure time taken for quicksort using chrono
    auto start_quick = high_resolution_clock::now();
    quicksort(arr_quick, 0, arr_quick.size() - 1);
    auto stop_quick = high_resolution_clock::now();
    auto duration_quick = duration_cast<microseconds>(stop_quick - start_quick);

    // Measure time taken for mergesort using chrono
    auto start_merge = high_resolution_clock::now();
    mergeSort(arr_merge, 0, arr_merge.size() - 1);
    auto stop_merge = high_resolution_clock::now();
    auto duration_merge = duration_cast<microseconds>(stop_merge - start_merge);

    // Measure time taken for shell sort using chrono
    auto start_shell = high_resolution_clock::now();
    shellSort(arr_shell);
    auto stop_shell = high_resolution_clock::now();
    auto duration_shell = duration_cast<microseconds>(stop_shell - start_shell);

    // Output sorted arrays and time taken
    cout << "Quicksort - Sorted array:" << endl;
    for (int element : arr_quick) {
        cout << element << " ";
    }
    cout << "\nTime taken for quicksort: " << duration_quick.count() << " microseconds." << endl;

    cout << "\nMergesort - Sorted array:" << endl;
    for (int element : arr_merge) {
        cout << element << " ";
    }
    cout << "\nTime taken for mergesort: " << duration_merge.count() << " microseconds." << endl;

    cout << "\nShell sort - Sorted array:" << endl;
    for (int element : arr_shell) {
        cout << element << " ";
    }
    cout << "\nTime taken for shell sort: " << duration_shell.count() << " microseconds." << endl;

    return 0;
}