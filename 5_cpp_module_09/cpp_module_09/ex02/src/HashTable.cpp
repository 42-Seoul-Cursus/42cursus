#include "HashTable.hpp"
#include <stdexcept>

HashTable::HashTable(size_t size)
    : size(size)
{
    table.resize(size);
}

HashTable::HashTable(const HashTable &other) : table(other.table), size(other.size) {}

HashTable &HashTable::operator=(const HashTable &other)
{
    if (this != &other)
    {
        table = other.table;
        size = other.size;
    }
    return *this;
}

HashTable::~HashTable() {}

size_t HashTable::hashFunction(int key) const
{
    return key % size;
}

void HashTable::insert(int key, int value)
{
    size_t index = hashFunction(key);

    for (hash_chain::iterator it = table[index].begin(); it != table[index].end(); ++it)
    {
        if (it->first == key)
        {
            it->second = value;
            return;
        }
    }

    table[index].push_back(std::make_pair(key, value));
}

int HashTable::get(int key) const
{
    size_t index = hashFunction(key);

    for (hash_chain::const_iterator it = table[index].begin();
         it != table[index].end(); ++it)
    {
        if (it->first == key)
            return it->second;
    }

    throw std::runtime_error("Key not found");
}

bool HashTable::contains(int key) const
{
    size_t index = hashFunction(key);

    for (hash_chain::const_iterator it = table[index].begin(); it != table[index].end(); ++it)
    {
        if (it->first == key)
            return true;
    }

    return false;
}
