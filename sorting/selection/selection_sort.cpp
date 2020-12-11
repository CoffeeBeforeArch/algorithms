// Implementation of selection sort
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

// Selection sort implementations
void sort(std::vector<int> &values) {
  // For each unsorted element in the vector
  for (auto i = 0u; i < values.size() - 1; i++) {
    // Assume that the current value is the min
    auto min_value = values[i];
    auto min_index = i;

    // Compare it against the remaining unsorted elements
    for (auto j = i + 1; j < values.size(); j++) {
      // Check if the if we found a smaller element
      if (values[j] < min_value) {
        // Update the min value and index
        min_value = values[j];
        min_index = j;
      }
    }

    // Move the next smallest element into the correct place
    std::swap(values[i], values[min_index]);
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
