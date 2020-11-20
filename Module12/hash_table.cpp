#include <iostream>
#include <list>
#include <cstdlib>
#include <cassert>

class HashTable
{
private:
    int buckets;           // number of buckets to store elements
    std::list<int> *table; // pointer to said buckets

public:
    HashTable(int b)
    {
        // Allocate space fro number of buckets asked for
        buckets = b;
        table = new std::list<int>[buckets];
    }

    void insert(int d);
    void print();
};

/* Insert into hash table */
void HashTable::insert(int d)
{
    // Simple hash function is just a modulo number of buckets
    int bucket = d % buckets;
    table[bucket].push_back(d);
}

/* Print out hash table */
void HashTable::print()
{
    for (int i = 0; i < buckets; i++)
    {
        std::cout << "| Bucket " << i << " | ";
        for (auto j : table[i])
        {
            std::cout << "-> | " << j << " | ";
        }
        std::cout << std::endl;
    }
}

int main(void)
{
    // Create hash table with 8 buckets
    HashTable ht(8);

    // Set random number seed
    srand(time(nullptr));

    // Insert 20 random ints
    for (int i = 0; i < 20; i++)
    {
        ht.insert(rand() % 100);
    }

    // print out hash table
    ht.print();

    return EXIT_SUCCESS;
}