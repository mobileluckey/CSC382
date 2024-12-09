#include "hashtable.h"
#include <iostream>
#include <list>
#include <string>

using namespace std;

// Constructor: Initialize the hash table with the given number of buckets
HashTable::HashTable(int numKeys) {
    this->numKeys = numKeys;
    hashT = new list<string>[numKeys]; // Allocate an array of linked lists
}

// Hash function: Generate a hash key for a string
int HashTable::hashKey(const string& data) {
    unsigned long hash = 0;
    for (char ch : data) {
        hash = (hash * 31 + ch) % numKeys;
    }
    return hash;
}

// Insert a string into the hash table
void HashTable::insertData(const string& data) {
    int dataKey = hashKey(data); // Compute the hash key
    hashT[dataKey].push_back(data); // Add the string to the appropriate bucket
}

// Display the contents of the hash table
void HashTable::displayHashTable() {
    for (int i = 0; i < numKeys; i++) {
        cout << i;
        for (const auto& x : hashT[i]) {
            cout << " --> " << x;
        }
        cout << "\n";
    }
}

// Search for a string in the hash table
bool HashTable::findValue(const string& data) {
    int dataKey = hashKey(data);
    for (const auto& x : hashT[dataKey]) {
        if (x == data) {
            return true; // String found
        }
    }
    return false; // String not found
}

// Delete a string from the hash table
bool HashTable::deleteData(const string& data) {
    int dataKey = hashKey(data);
    for (auto it = hashT[dataKey].begin(); it != hashT[dataKey].end(); ++it) {
        if (*it == data) {
            hashT[dataKey].erase(it); // Remove the string from the bucket
            return true; // Deletion successful
        }
    }
    return false; // String not found
}
