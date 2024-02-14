#include <chrono>
#include<bits/stdc++.h>



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
    std::cout << "Observations for Linear Search:" << std::endl;
    for (int target : targets) {
        auto start = std::chrono::high_resolution_clock::now();
        linearSearch(dataRecords, target);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";
    }
    std::cout << std::endl;

    std::cout << "Observations for Binary Search:" << std::endl;
    for (int target : targets) {
        auto start = std::chrono::high_resolution_clock::now();
        binarySearch(dataRecords, target);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";
    }
    std::cout << std::endl;

    std::cout << "Observations for Direct Search:" << std::endl;
    for (int target : targets) {
        auto start = std::chrono::high_resolution_clock::now();
        directSearch(dataRecords, target);
        auto end = std::chrono::high_resolution_clock::now();
        std::cout << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " ";
    }
    std::cout << std::endl;


}