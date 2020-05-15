// A simple implementation of selection sort in C++
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// Selection sort implementation (classic)
void sort(std::vector<int> &v) {
  // For each index in the vector
  // Skip the last element (nothing left to sort)
  for (auto i = 0u; i < v.size() - 1; i++) {
    // Use the current as a starting point
    auto smallest = i;

    // And find the next smallest element
    for (auto j = i + 1; j < v.size(); j++) {
      if (v[j] < v[smallest]) smallest = j;
    }

    // Swap the smallest element into place
    // v[i] and v[smallest] should be in the cache
    // Adding an extra branch here is probably slower (miss-prediction)
    std::swap(v[smallest], v[i]);
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
