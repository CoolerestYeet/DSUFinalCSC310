/*
Bloom Filter by Matt Maher
How to Use:
include "#include "bloomfilter.h"" at the top of your program
Create the filter by using BloomFilter<(data type), (# of bits wanted), (# of hash functions)> (name);
Then you can use the insert functions, its in the form of (name).insert("value/string/whatever");
After you get all the values inserted, you can instantly look up what is in the list by using contains
Contains is in the form of (name).contains("value/string/whatever"), and returns true/false
*/

#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <cstddef>
#include <bitset>
#include <functional>

using namespace std;
// Bloom filter implementation
template <typename T, size_t N, size_t K>
class BloomFilter {
private:
    bitset<N> bits; // initializes array of bits (or bools to be more accurate) N units long
    hash<T> hashers[K]; // creates K amount of hash functions based on datatype

public:
    void insert(const T& value); // initialization of functions
    bool contains(const T& value) const;
};

// Implementation of member functions
template <typename T, size_t N, size_t K>
void BloomFilter<T, N, K>::insert(const T& value) {
    for (size_t i = 0; i < K; ++i) { // iterates through hash functions
        size_t hash = hashers[i](value) % N; // hashes value or word and turns the bit on
        bits.set(hash); // 'set' sets the bit value to on (or one, or true, or whatever)
    }
}

template <typename T, size_t N, size_t K>
bool BloomFilter<T, N, K>::contains(const T& value) const {
    for (size_t i = 0; i < K; ++i) { // iterates through hash functions
        size_t hash = hashers[i](value) % N; // hashes value or word to find the location of the bit
        if (!bits.test(hash)) { // checks bit value
            return false; // if one is false, that means that the value/word does not exist in the set
        }
    }
    return true; // if all K pass, the value/word probably exists in the set
}

#endif 