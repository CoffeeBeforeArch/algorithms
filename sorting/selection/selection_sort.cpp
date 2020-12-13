// Implementation of selection sort
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Selection sort implementation
void sort(std::vector<int> &values) {
  // For each unsorted element in the vector
  // The last element is implicitly sorted (all other elements were smaller)
  for (auto pos = 0u; pos < values.size() - 1; pos++) {
    // Assume that the current position is the min
    auto min_value = values[pos];
    auto min_index = pos;

    // Compare it against the remaining unsorted elements
    for (auto current = pos + 1; current < values.size(); current++) {
      // Check if the current value is smaller than the current minimum
      if (values[current] < min_value) {
        // Update the min value and index
        min_value = values[current];
        min_index = current;
      }
    }

    // Move the next smallest element into the correct place
    std::swap(values[pos], values[min_index]);
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
