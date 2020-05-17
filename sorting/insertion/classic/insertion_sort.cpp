// A classic insertion sort implementation
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// Insertion sort implementation
// More modern C++
void sort(std::vector<int> &v) {
  // For each element not in the sorted sub-array...
  for (auto i = 1u; i < v.size(); i++) {
    // Start at the current element
    auto j = i;
    // And swap it downward into place
    while (j > 0 && v[j - 1] > v[j]) {
      std::swap(v[j - 1], v[j]);
      j--;
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
