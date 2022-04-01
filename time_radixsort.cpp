/**
 * Problem Set 8: Radix Sort with Bits
 * @file time_radixsort.cpp
 * @author Darren Strash
 * @date November 2, 2021
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <ctime>
#include <functional>
#include <limits>

#include "radixsort.h"

using namespace std;

/**
 *     Run radix sort with 1-bit keys
 *     @param the input vector of unsigned ints to sort
 */
void run_radixsort1(vector<unsigned int> & input) {
    radix_sort(input, 1);
}

/**
 *     Run radix sort with 2-bit keys
 *     @param the input vector of unsigned ints to sort
 */
void run_radixsort2(vector<unsigned int> & input) {
    radix_sort(input, 2);
}

/**
 *     Run radix sort with 4-bit keys
 *     @param the input vector of unsigned ints to sort
 */
void run_radixsort4(vector<unsigned int> & input) {
    radix_sort(input, 4);
}

/**
 *     Run radix sort with 8-bit keys
 *     @param the input vector of unsigned ints to sort
 */
void run_radixsort8(vector<unsigned int> & input) {
    radix_sort(input, 8);
}

/**
 *     Run radix sort with 16-bit keys
 *     @param the input vector of unsigned ints to sort
 */
void run_radixsort16(vector<unsigned int> & input) {
    radix_sort(input, 16);
}

/**
 *     Run radix sort with n-bit keys
 *     @param the input vector of unsigned ints to sort
 */
void run_radixsortn(vector<unsigned int> & input) {
    radix_sort(input, 19);
}

/**
 *     Run radix royale submission
 *     @param the input vector of unsigned ints to sort
 */
void run_radixroyale(vector<unsigned int> & input) {
    radix_royale(input);
}

/**
 *     Fill a vector with random unsigned ints
 *     @param the input vector to sort
 */
void generate_random_input(vector<unsigned int> & input, size_t size) {
    input.resize(size);
    for (unsigned int & value : input) {
        value = rand() % std::numeric_limits<unsigned int>::max();
    }
}

/**
 *  Run a specified function repeatedly, and compute its
 *  average running time.
 *  @param func a function pointer to a function
 *  @param size the input size
 *  @return the average running time of func
 */
double time(std::function<void (vector<unsigned int> &)> func, const size_t size) {
    const size_t repetitions = 1;
    clock_t total_clock_time = 0;

    for (size_t iteration = 0; iteration < repetitions; iteration++) {
        vector<unsigned int> input;
        generate_random_input(input, size);

        const clock_t start_time = clock();

        (func)(input);

        total_clock_time += (clock() - start_time);
    }

    const double total_millis_time((total_clock_time * 1000.0) / CLOCKS_PER_SEC);

    return total_millis_time/repetitions;
}

/**
 *     Run algorithms with various input sizes and print
 *     table of running times.
 *
 *     @param run_poly Run algorithms with constant exponents greater than one
 *     @param run_exponential Run exponential time algorithm
 *     @return nothing
 */
void run_timing_experiment(map<string, std::function< void (vector<unsigned int> &)> > func_map, vector<string> const &funcs) {

    cout << "Legend, all times in milliseconds"               << endl << flush;
    cout << "n          : size of input array"                << endl << flush;

    cout << setw(15) << "n" << setw(15);
    for (string func : funcs) {
        cout << setw(15) << func;
    }

    cout << endl;

    for (size_t n = 1; n < 1000000000; n *= 2) {
        cout << setw(15) << n << flush;
        for (string func : funcs) {
            cout << setw(15) << time(func_map[func], n) << flush;
        }
        cout << endl;
    }
}

int main(int argc, char **argv) {
    srand(time(0));
    map<string, std::function<void (vector<unsigned int> &)> > func_map;
    func_map["1-bit"]  = run_radixsort1;
    func_map["2-bit"]  = run_radixsort2;
    func_map["4-bit"]  = run_radixsort4;
    func_map["8-bit"]  = run_radixsort8;
    func_map["16-bit"] = run_radixsort16;
    func_map["n-bit"] = run_radixsortn;
    func_map["royale"] = run_radixroyale;

    vector<string> funcs;

    if (argc == 1) {
        funcs.push_back("1-bit");
        funcs.push_back("2-bit");
        funcs.push_back("4-bit");
        funcs.push_back("8-bit");
        funcs.push_back("16-bit");
    }
    for (int argument = 1; argument < argc; argument++)
        funcs.push_back(argv[argument]);

    run_timing_experiment(func_map, funcs);
    return 0;
}
