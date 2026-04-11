#include <iostream>
#include "linked_list.h"
constexpr int LINEAR_PROBING_TABLE_SIZE = 10;

int get_chain_hash_index(int value) {
    return value % 10;
}

int get_linear_probing_hash_index(int value) {
    return value % LINEAR_PROBING_TABLE_SIZE;
}

int linear_probe(int* hashTable, int value) {
    int index = get_linear_probing_hash_index(value);

    int startIndex = index;

    while (hashTable[index] != -1) {
        index = (index + 1) % LINEAR_PROBING_TABLE_SIZE;

        if (index == startIndex)
            return -1;
    }

    return index;
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
    int* linearProbingHashTable = new int[LINEAR_PROBING_TABLE_SIZE]();
    for (int i = 0; i < LINEAR_PROBING_TABLE_SIZE; i++)
        linearProbingHashTable[i] = -1;

    linear_probing_hash(linearProbingHashTable, 3);
    linear_probing_hash(linearProbingHashTable, 7);
    linear_probing_hash(linearProbingHashTable, 9);
    linear_probing_hash(linearProbingHashTable, 19);

    for (int i = 0; i < LINEAR_PROBING_TABLE_SIZE; i++) {
        if (linearProbingHashTable[i]!= -1)
            std::cout << "Bucket " << i << ": " << linearProbingHashTable[i]<< std::endl;
    }

    #pragma endregion

    return 0;
}