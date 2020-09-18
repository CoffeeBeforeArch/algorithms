// This program implements insertion sort in C++
// By: Nick form CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Implementation of insertion sort
// Insert elements into a sorted sub-array until there are no elements left
void sort(std::vector<int> &v) {
  // For each element to insert into the sorted sub-array
  for (auto element = begin(v) + 1; element < end(v); element++)
    ;
}

// Helper function to print the contents of a vector
void print(const std::vector<int> &v) {
  for (auto element : v) std::cout << element << " ";
  std::cout << '\n';
}

int main() {
  // Create random number generaotr
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(0, 1024);

  // Vector to sort
  std::vector<int> v(10);
  std::generate(begin(v), end(v), [&] { return dist(rng); });

  // Print the vector before sorting
  print(v);

  // Sort the vector
  sort(v);

  // Print the vector after sorting
  print(v);

  return 0;
}
