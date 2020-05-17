// A simple implementation of bubble sort in C++
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// Bubble sort implementation (classic)
void sort(std::vector<int> &v) {
  // For each element in the vector
  // (final element is already sorted)
  for (auto i = 0u; i < v.size() - 1; i++) {
    // Swap the largest element to it's final place
    for (auto j = 1u; j < v.size() - i; j++) {
      if (v[j] < v[j - 1]) std::swap(v[j], v[j - 1]);
    }
  }
}

int main() {
  // Number of elements to sort (defualt=16)
  size_t N = 1 << 4;

  // Create a vector of random numbers
  std::vector<int> v(N);
  std::generate(begin(v), end(v), []() { return rand() % 100; });

  // Print the vector before sorting
  std::cout << "Before sort\n";
  for (auto i : v) std::cout << i << " ";
  std::cout << '\n';

  // Sort the vector
  sort(v);

  // Print the vector after sorting
  std::cout << "After sort\n";
  for (auto i : v) std::cout << i << " ";
  std::cout << '\n';

  return 0;
}
