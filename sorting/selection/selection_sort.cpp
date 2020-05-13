// A simple implementation of selection sort in C++
// By: Nick from CoffeeBeforeArch

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

// Selection sort implementation
// More modern C++
void sort(std::vector<int> &v) {
  // For each index...
  for (auto current = begin(v); current < end(v); ++current) {
    // Swap in the smallest element
    std::iter_swap(current, std::min_element(current, end(v)));
  }
}

int main() {
  // Number of elements to sort (defualt=16)
  size_t N = 1 << 4;

  // Create a vector of random numbers
  std::vector<int> v(N);
  std::generate(begin(v), end(v), [](){ return rand() % 100; });

  // Print the vector before sorting
  std::cout << "Before sort\n";
  for(auto i : v) std::cout << i << " ";
  std::cout << '\n';
  
  // Sort the vector
  sort(v);
  
  // Print the vector after sorting
  std::cout << "After sort\n";
  for(auto i : v) std::cout << i << " ";
  std::cout << '\n';

  return 0;
}
