// A classic insertion sort implementation
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>

// Insertion sort implementation
// More modern C++
void sort(std::vector<int> &v) {
  // Current element and end of vector
  auto first = begin(v);

  // Keep inserting until we run out of elements
  for (auto pivot = begin(v) + 1u; pivot < end(v); ++pivot) {
    // Current element to sort and start of sorted sub-array
    auto current = pivot;
    auto prev = pivot - 1u;
    // Swap until we hit the pivot is the first element or we found the right
    // position
    while (current != first && (*current < *prev)) {
      // Swap contents and move both iterators to the left
      // Sinks the smallest element into place
      std::iter_swap(current--, prev--);
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
