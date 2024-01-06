#include <iostream>
#include <cstring>
#include <list>
using namespace std;

class Hashtable {
    private:
        static const int hashGroups = 10;
        list<pair<int, string>> table[hashGroups];

    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        void printTable();
};


bool Hashtable::isEmpty() const { 
    int sum{};
    for(int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if(!sum) {
        return true;
    }
    return false;
}

int Hashtable::hashFunction(int key) {
    return key % hashGroups;
}

void Hashtable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            bItr->second = value;
            cout << "Key exists.Value replaced" << endl;
            break;
        }
    }

    if(!keyExists) {
        cell.emplace_back(key, value);
    }

    return;
}

void Hashtable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for(; bItr != end(cell); bItr++) {
        if(bItr->first == key) {
            keyExists = true;
            bItr = cell.erase(bItr);
            cout << "Item removed" << endl;
            break;
        }
    }
    if (!keyExists){
        cout << "Key not found" << endl;
    }
    return;
}

void Hashtable::printTable(){
    for (int i{}; i < hashGroups; i++){
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++){
            cout << "Key:  " << bItr->first << "   Value: " << bItr->second << endl;
        }
    }
    return;
}

int main() {
    Hashtable HT;

    if (HT.isEmpty()){
        cout << "Correct answer" << endl;
    } else{
        cout<< "We need to check our code" << endl;
    }

    HT.insertItem(905, "Jim");
    HT.insertItem(201, "Tom");
    HT.insertItem(332, "Bob");
    HT.insertItem(124, "Sally");
    HT.insertItem(107, "Sandy");
    HT.insertItem(929, "Rob");
    HT.insertItem(928, "Barb");
    HT.insertItem(928, "Rick");

    HT.printTable();

    HT.removeItem(332);
    HT.removeItem(100);

    if (HT.isEmpty()){
        cout << "Check code" << endl;
    } else{
        cout<< "Correct" << endl;
    }


    return 0;
}