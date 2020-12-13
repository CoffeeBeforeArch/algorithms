// Implementation of insertion sort
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Insertion sort implementations
void sort(std::vector<int> &values) {
  // For each element not in the sorted sub-vector
  // Skip first element (sorted sub-vector contains only a single element)
  for (auto to_insert = 1u; to_insert < values.size(); to_insert++) {
    // Start comparing elements starting at the element we want to insert
    auto current = to_insert;

    // While the current element is not the first in sub-vector
    while (current > 0) {
      // We compare the current element to the previous in the sub-vector
      auto prev = current - 1;

      // Exit when we reach the insertion point
      // (When the prev element is smaller)
      if (values[prev] <= values[current]) break;

      // Swap the smaller element downward
      std::swap(values[prev], values[current]);

      // Move the current element to compare over
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
