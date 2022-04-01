/**
 * Problem Set 8: Radix Sort with Bits
 * @file test_radixsort.cpp
 * @author Clearence Clothes
 * @date 11/10/21
 */
#include <iostream>
#include <vector>
#include "radixsort.h"
#include "gtest/gtest.h"

using namespace std;

/// a class to use for testing binary_search with gtest
class RadixSortTest: public ::testing::Test {
    // Would Put any setup or teardown here. None needed for this problem set.
};

/**
 * Test sorting an empty array
 */
TEST(RadixSortTest, EmptyTest) {
    vector<unsigned int> input;
    vector<unsigned int> expected_output;
    unsigned int num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);
}

/**
 * Test sorting a singleton array
 */
TEST(RadixSortTest, SingletonTest) {
    vector<unsigned int> input(1, 9999);
    vector<unsigned int> expected_output(1, 9999);
    unsigned int num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);
}

/**
 * Test sorting a sorted array
 */
TEST(RadixSortTest, SortedTest) {
    vector<unsigned int> input = {1, 2, 3, 4, 5, 6, 7};
    vector<unsigned int> expected_output = {1, 2, 3, 4, 5, 6, 7};
    unsigned int num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input = {134, 245, 3456, 45670, 556711, 689054, 71230321};
    expected_output = {134, 245, 3456, 45670, 556711, 689054, 71230321};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);
}

/**
 * Test sorting an array with repated elements
 */
TEST(RadixSortTest, RepeatedTest) {
    vector<unsigned int> input(10, 1);
    vector<unsigned int> expected_output(10, 1);
    unsigned int num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input = {1, 2, 1, 2, 1, 2, 1, 2, 3, 4};
    expected_output = {1, 1, 1, 1, 2, 2, 2, 2, 3, 4};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input = {1234, 2345, 1234, 2345, 1234, 2345, 36700, 4569958, 2};
    expected_output = {2, 1234, 1234, 1234, 2345, 2345, 2345, 36700, 4569958};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);
}

/**
 * Test sorting an array with elements in random, unsorted order
 */
TEST(RadixSortTest, WorstCaseTest) {
    vector<unsigned int> input = {7, 6, 5, 4, 3, 2, 1};
    vector<unsigned int> expected_output = {1, 2, 3, 4, 5, 6, 7};
    unsigned int num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input = {7123, 6890, 5567, 4567, 3456, 2345, 1234};
    expected_output = {1234, 2345, 3456, 4567, 5567, 6890, 7123};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input = {9999, 9765, 8999, 1234, 1000};
    expected_output = {1000, 1234, 8999, 9765, 9999};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input =  {9999, 1000, 8999, 9765, 1234};
    expected_output = {1000, 1234, 8999, 9765, 9999};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input =  {999990, 100, 89959, 979595, 1234, 1000000};
    expected_output = {100, 1234, 89959, 979595, 999990, 1000000};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input = {712323478, 6890758, 556725, 456700, 34569, 234, 12};
    expected_output = {12, 234, 34569, 456700, 556725, 6890758, 712323478};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    input = {4294967295, 42949672, 3322445598, 4237846529, 1234567890};
    expected_output = {42949672, 1234567890, 3322445598, 4237846529, 4294967295};
    num_bits = 1;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 2;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 4;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);

    num_bits = 8;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);
    //
    num_bits = 16;
    radix_sort(input, num_bits);
    EXPECT_EQ(input, expected_output);
}


// Controls operation of program.
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
