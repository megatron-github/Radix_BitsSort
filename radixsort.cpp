/**
 * Problem Set 8: Radix Sort with Bits
 * @file radixsort.cpp
 * @author Clearence Clothes
 * @date 11/10/21
 */
#include <vector>
#include "radixsort.h"

using namespace std;

/**
 * Extract a key from value with num_bits bits starting at start_bit.
 * @param value the value from which we wish to extract the key
 * @param num_bits the length of the key in bits
 * @param start_bit the first bit (least significant) in our sequence of bits
 * @return the key
 */
unsigned int get_key(const unsigned int   value,
                     const unsigned short num_bits,
                     const unsigned int   start_bit) {
    // bit shifting to get the desired bit keys
    // starts at start_bit with length num_bits
    return value << (32 - (start_bit + num_bits)) >> (32 - num_bits);
}

/**
 * Sort the given vector using counting sort.
 * @param array the vector the sort
 * @param num_bits the length of the key to sort on in bits
 * @param start_bit the first bit (least significant) in our sequence of bits
 */
void counting_sort(vector<unsigned int> & array,
                   const unsigned short   num_bits,
                   const unsigned short   start_bit) {
    // find the distribution of the bit keys located from
    // the start_bit position of the numbers in the input array
    vector<unsigned int> space_taken((1 << num_bits), 0);
    for(size_t at_indx = 0; at_indx < array.size(); at_indx++) {
        unsigned int by_key = get_key(array[at_indx], num_bits, start_bit);
        space_taken[by_key] = space_taken[by_key] + 1;
    }
    // find how many cells in the array in which the bit keys
    // located from start_bits position have taken
    for(size_t at_indx = 1; at_indx < space_taken.size(); at_indx++) {
        space_taken[at_indx] = space_taken[at_indx - 1] + space_taken[at_indx];
    }
    // sort input array by the cells taken by the bit keys located
    // from the start_bit position of the numbers in the input array
    vector<unsigned int> sorted_copy(array.size());
    for(size_t at_indx = array.size(); at_indx > 0; at_indx--) {
        unsigned int by_key = get_key(array[at_indx - 1], num_bits, start_bit);
        sorted_copy[space_taken[by_key] - 1] = array[at_indx - 1];
        space_taken[by_key] = space_taken[by_key] - 1;
    }
    array = sorted_copy;
}

/**
 * Sort the given vector using radix sort.
 * @param array the vector the sort
 * @param num_bits the length of the keys to sort on in bits
 */
void radix_sort(vector<unsigned int> & array,
                const unsigned short   num_bits) {
    if (array.size() > 1) {
        // index through each bit key of length num_bits from each number
        // in the input array and sort the bit keys
        for(unsigned short start_bit = 0;
            start_bit < 32;
            start_bit += num_bits) {
            counting_sort(array, num_bits, start_bit);
        }
    }
}

/**
 * Your entry for the Radix Royale (if you wish to participate)
 * @param array the vector the sort
 */
void radix_royale(vector<unsigned int> & array) {
    if (array.size() > 1) {
        for(unsigned short start_bit = 0;
            start_bit < 32;
            start_bit += 16) {
            counting_sort(array, 16, start_bit);
        }
    }
}
