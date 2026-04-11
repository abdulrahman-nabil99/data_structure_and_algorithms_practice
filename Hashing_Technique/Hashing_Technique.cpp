#include <iostream>
#include "linked_list.h"
constexpr int TABLE_SIZE = 10;
constexpr int DOUBLE_HASHING_PRIIME = 7;    

int get_chain_hash_index(int value) {
    return value % TABLE_SIZE;
}

int get_linear_probing_hash_index(int value) {
    return value % TABLE_SIZE;
}

int linear_probe(int* hashTable, int value) {
    int index = get_linear_probing_hash_index(value);

    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;

        if (index == startIndex)
            return -1;
    }

    return index;
}

int quadratic_probe(int* hashTable, int value) {
    int h = get_linear_probing_hash_index(value);
    int i = 0;

    int index;

    while (i < TABLE_SIZE) {
        index = (h + i * i) % TABLE_SIZE;

        if (hashTable[index] == -1)
            return index;

        i++;
    }

    return -1;
}

bool chain_hash(LinkedList<int>* hash_table, int value) {
    if (hash_table == nullptr)
        return false;

    int hashIndex = get_chain_hash_index(value);

    hash_table[hashIndex].insert_sorted(value);

    return true;
}

bool linear_probing_hash(int* hashTable, int value) {
    int index = linear_probe(hashTable, value);

    if (index == -1)
        return false;

    hashTable[index] = value;
    return true;
}

int double_hash_one(int value) {
    return value % TABLE_SIZE;
}

int double_hash_two(int value) {
    return DOUBLE_HASHING_PRIIME - (value % DOUBLE_HASHING_PRIIME);
}

bool double_hash(int* hashTable, int value) {
    int index = double_hash_one(value);
    int step = double_hash_two(value);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int newIndex = (index + i * step) % TABLE_SIZE;

        if (hashTable[newIndex] == -1) {
            hashTable[newIndex] = value;
            return true;
        }
    }

    return false;
}

int main()
{
    #pragma region chain_hash
    std::cout << "##### Chain Hash #####" << std::endl;
    LinkedList<int>* lists = new LinkedList<int>[10];

    chain_hash(lists, 15);
    chain_hash(lists, 25);
    chain_hash(lists, 7);
    chain_hash(lists, 17);
    chain_hash(lists, 3);
    chain_hash(lists, 12);
    chain_hash(lists, 1223);

    for (int i = 0; i < 10; i++) {
        if (lists[i].count() > 0) {
            std::cout << "Bucket " << i << ": ";
            lists[i].display();
        }
    }

    delete[] lists;
    #pragma endregion

    #pragma region linear_probing_hash
    std::cout << "\n##### Linear Probing Hash #####" << std::endl;
    int* linearProbingHashTable = new int[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        linearProbingHashTable[i] = -1;

    linear_probing_hash(linearProbingHashTable, 3);
    linear_probing_hash(linearProbingHashTable, 7);
    linear_probing_hash(linearProbingHashTable, 9);
    linear_probing_hash(linearProbingHashTable, 19);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (linearProbingHashTable[i]!= -1)
            std::cout << "Bucket " << i << ": " << linearProbingHashTable[i]<< std::endl;
    }
    #pragma endregion

#pragma region linear_probing_hash
    std::cout << "\n##### Double Hashing #####" << std::endl;
    int* doubleHashingTable = new int[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++)
        doubleHashingTable[i] = -1;

    double_hash(doubleHashingTable, 3);
    double_hash(doubleHashingTable, 7);
    double_hash(doubleHashingTable, 9);
    double_hash(doubleHashingTable, 19);

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (doubleHashingTable[i] != -1)
            std::cout << "Bucket " << i << ": " << doubleHashingTable[i] << std::endl;
    }
#pragma endregion
    return 0;
}