#include <iostream>
#include "hashtable.h"
#include <string>
#include <fstream>
#include <chrono>

using namespace std;

// Function to load names from a file into the hash table
void loadNamesFromFile(const string& filename, HashTable& hashTable) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    string name;
    while (getline(file, name)) {
        hashTable.insertData(name); // Insert name into the hash table
    }
    file.close();
}

int main() {
    int numValues = 100; // Number of buckets in the hash table
    HashTable hashTable(numValues);

    // Load names from a dataset file
    string filename = "english_names_1000.txt";
    cout << "Loading names from " << filename << "..." << endl;

    auto start = std::chrono::high_resolution_clock::now();
    loadNamesFromFile(filename, hashTable); // Load names
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    cout << "Loading Time: " << elapsed.count() << " seconds" << endl;

    // Display the hash table
    hashTable.displayHashTable();

    return 0;
}
