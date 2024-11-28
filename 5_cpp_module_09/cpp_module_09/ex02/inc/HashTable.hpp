#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP

#include <vector>
#include <list>
#include <utility>
#include <cstddef>

typedef std::list<std::pair<int, int> > hash_chain;

class HashTable
{
private:
    HashTable();
    std::vector<hash_chain> table;
    size_t size;

    size_t hashFunction(int key) const;

public:
    HashTable(size_t size);
    HashTable(const HashTable& other);
    HashTable& operator=(const HashTable& other);
    ~HashTable();

    void insert(int key, int value);
    int get(int key) const;
    bool contains(int key) const;
};

#endif
