// This program implements selection sort in C++
// By: Nick form CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Implementation of selection sort
// For each element in a given vector, replace the next smallest element
void sort(std::vector<int> &v) {
  // For every element in the vector except the last
  for (auto iter = begin(v); iter < end(v) - 1; ++iter)
    // Sawp the current element with the smallest element in the remainder of
    // the vector
    std::iter_swap(iter, std::min_element(iter, end(v)));
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
