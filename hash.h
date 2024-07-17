#ifndef HASH_H
#define HASH_H
template <class T>
class myHash {
 private:

    const static int HASHSIZE = 134999;
    T * hash; 
    int size;
public:

    static long long int totalCount;
    static long long int correctCount;
    static long long int falseCount;
    static long long int c_compareCount;
    static long long int f_compareCount;

    myHash();
    ~myHash() { delete[] hash; } 
    void insert (T item);
    bool find (T item);
    int getsize() { return size;}
    int findhash(T word);
    int getSize() const;
};
#include "hash.cpp"
#endif