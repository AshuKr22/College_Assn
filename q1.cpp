#include <chrono>
#include<bits/stdc++.h>
using namespace std;
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]); // Swap root with last element
        heapify(arr, i, 0); // Heapify reduced heap
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
int main() {
    const std::string filename = "data1.txt";
    const int numRecords = 1000;
    const int numObservations = 10;

    // Generate data file with sorted integers
    std::ofstream dataFile(filename);
    for (int i = 1; i <= numRecords * 10; ++i) {
        dataFile << i << " ";
    }
    dataFile.close();

    std::ifstream inputFile(filename);
    std::vector<int> dataRecords(numRecords);

    for (int i = 0; i < numRecords; ++i) {
        inputFile >> dataRecords[i];
    }

    std::vector<int> targets;
    for (int i = 0; i < numObservations; ++i) {
        targets.push_back(dataRecords[rand() % numRecords]);
    }

    std::cout << "Target Values: ";
    for (int target : targets) {
        std::cout << target << " ";
    }
    std::cout << std::endl;
    
    
    
    std::cout << "Observation in Microseconds" << std::endl;
    

    std::cout << "Observations for Heao Sort:" << std::endl;
    for (int target : targets) {
        auto start = std::chrono::high_resolution_clock::now();
        heapSort(dataRecords);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";
    }
    std::cout << std::endl;


}