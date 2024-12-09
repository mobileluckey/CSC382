#pragma once
#pragma once
#include <list>
#include <string>

using namespace std;

class HashTable {
    int numKeys;                // Number of buckets in the hash table
    list<string>* hashT;        // Array of linked lists (buckets)

public:
    HashTable(int numKeys);     // Constructor accepting an integer for bucket size
    void insertData(const string& data); // Insert a string into the hash table
    void displayHashTable();    // Display the contents of the hash table
    int hashKey(const string& data); // Generate a hash key for a string
    bool findValue(const string& data); // Search for a string in the hash table
    bool deleteData(const string& data); // Delete a string from the hash table
};
