// This program implements bubble sort in C++
// By: Nick form CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Implementation of bubble sort
void sort(std::vector<int> &v) {

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
