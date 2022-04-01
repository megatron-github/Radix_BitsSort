cmake_minimum_required(VERSION 3.16)
project(radixbits)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -g")

enable_testing()

add_executable(
  test_radixsort
  radixsort.cpp
  test_radixsort.cpp
)

add_executable(
  time_radixsort
  radixsort.cpp
  time_radixsort.cpp
)

target_link_libraries(
  test_radixsort
  gtest_main
  gtest
  pthread
)

include(GoogleTest)
gtest_discover_tests(test_radixsort)

