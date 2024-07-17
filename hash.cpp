#include "hash.h"
#include <string>

template <class T>
long long int myHash<T>::totalCount = 0;

template <class T>
long long int myHash<T>::correctCount = 0;

template <class T>
long long int myHash<T>::falseCount = 0;

template <class T>
long long int myHash<T>::c_compareCount = 0;

template <class T>
long long int myHash<T>::f_compareCount = 0;

// ---------- Constructor
template <class T>
myHash<T>::myHash() {
    hash = new T[HASHSIZE];
    size = 0;
}

// ---------- Insert function.
template <class T>
void myHash<T>::insert(T item) {
    int key = findhash(item);
    if (hash[key].empty()) {
        hash[key] = item;
    } else {

        int originalKey = key;
        do {
            key = (key + 1) % HASHSIZE;
        } while (!hash[key].empty() && key != originalKey);
        if (hash[key].empty()) {
            hash[key] = item;
        } else {
  
        }
    }
    size++;
}

// ---------- Find function.
template <class T>
bool myHash<T>::find(T item) {
    int key = findhash(item);
    int totalCount = 0;
    if (hash[key].compare(item) == 0) {

        correctCount++;
        c_compareCount += ++totalCount;
        return true;
    } else {

        int originalKey = key;
        do {
            key = (key + 1) % HASHSIZE;
            if (!hash[key].empty()) {
                totalCount++;
                if (hash[key].compare(item) == 0) {
  
                    correctCount++;
                    c_compareCount += totalCount;
                    return true;
                }
            }
        } while (!hash[key].empty() && hash[key].compare(item) != 0 && key != originalKey);

        falseCount++;
        f_compareCount += totalCount;
        return false;
    }
}

// ---------- Findhash function.
template <>
int myHash<std::string>::findhash(std::string word) {
    std::hash<std::string> str_hash;
    return str_hash(word) % HASHSIZE;
}

// ---------- Gets size of dictionary.
template <class T>
int myHash<T>::getSize() const {
    return size;
}