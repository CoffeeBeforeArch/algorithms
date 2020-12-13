// Implementation of bubble sort
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Bubble sort implementations
void sort(std::vector<int> &values) {
  // For each position in the vector (descending)
  for (int target = values.size() - 1; target > 0; target--) {
    // For each element in the unsorted sub-array
    for (int current = 0; current < target; current++) {
      // Compare the current element to the next
      auto next = current + 1;
      if (values[current] > values[next])
        // Swap the larger element upward
        std::swap(values[current], values[next]);
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
