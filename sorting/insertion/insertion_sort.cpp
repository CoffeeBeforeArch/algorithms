// Implementation of insertion sort
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Insertion sort implementations
void sort(std::vector<int> &values) {
  // For each element not in the sorted sub-vector
  for (auto i = 1u; i < values.size(); i++) {
    // Indices of elements to compare
    auto current = i;

    // Go through all elements in the sorted sub-vector
    while (current > 0) {
      // Exit when we reach the insertion point
      if (values[current - 1] <= values[current]) break;

      // Swap the elements over
      std::swap(values[current - 1], values[current]);

      // Move the index over
      current--;
    }
  }
}

// Helper function to print the vector contents
void print(const std::vector<int> &values) {
  for (auto v : values) std::cout << v << ' ';
  std::cout << '\n';
}

int main() {
  // Number of elements to sort
  int N = 16;

  // Create our random number generator
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<int> dist(0, 100);

  // Create vector of input elements
  std::vector<int> values;
  values.reserve(N);
  for (int i = 0; i < N; i++) values.push_back(dist(rng));

  // Print out starting values
  print(values);

  // Sort the vector
  sort(values);

  // Print ending values
  print(values);

  return 0;
}
