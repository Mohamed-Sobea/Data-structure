#include <cstdint>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class HashTable {
private:
    vector<pair<string,string>> table;
    int size;
public:
    HashTable() {
        size = 3;
        table = vector<pair<string,string>>(size,{"",""});
    }
    int getHash(string key) {
        int hash = 0;
        for (int i = 0; i < key.length(); i++){
            hash = (hash + key[i]) % size ;
        }
        return hash;
    }

    int CollisionHandling(string key) {
        int hash = getHash(key);

        // check if slot is occupied  We use "Linear Probing" for collesion handling
        for (int i=0; i < size ; i++) {
            int newHash = (hash+i) % size;   // try next slot
            if (table[newHash].first == "" || table[newHash].first == key) {
                return newHash;
            }
        }
        return -1;   // No available Slot
    }

    // Inserts or Updates a Key-Value Pair
    void Set(string key, string value) {
       int index = CollisionHandling(key);

        if (index != -1) {
            table[index] = {key,value};
        }else {
            cout << "Table is Full ! cannot insert : " << key << endl;
        }
    }

   // Retrieves a Value by Key
    string Get(string key) {
        int hash = getHash(key);

        for (int i =0; i < size ; i++) {
            int newHash = (hash + i )% size;   // use linear probing for search for the key
            if (table[newHash].first == key) {
                return table[newHash].second;
            }else if (table[newHash].first == "") {
                break;
            }
        }
        return "Not Found !";  // key doesnt exist
    }

    void print() {
        cout << "Hash Table:\n";
        for (int i = 0; i < size; i++) { // Regular for loop
            cout << "[" << i << "] " << (table[i].first.empty() ? "empty" : table[i].first + " -> " + table[i].second) << endl;
        }
        cout << "------------------\n";
    }
};


int main()
{
    HashTable hash;
    hash.Set("moha","msby1144@gmail.com");
    hash.Set("Khalid","Lodaa@gmail.com");
    hash.Set("hihh","hihi@gmail.com");
    hash.Set("vhryhvh","vhryhv55@gmail.com");
    hash.print();
    return 0;
}
