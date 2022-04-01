/**
 * Problem Set 8: Radix Sort with Bits
 * @file radixsort.cpp
 * @author Your pseudonym goes here
 * @collaborators You collaborators go here
 * @date the final date you worked on this file goes here
 */
#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <vector>

unsigned int get_key(const unsigned int   value,
                     const unsigned short num_bits,
                     const unsigned int   start_bit);

void counting_sort(std::vector<unsigned int> & array,
                   const unsigned short        num_bits,
                   const unsigned short        start_bit);


void radix_sort(std::vector<unsigned int> & array,
                const unsigned short        num_bits);

void radix_royale(std::vector<unsigned int> & array);
#endif // RADIXSORT_H
