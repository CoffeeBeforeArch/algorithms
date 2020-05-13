// A simple implementation of selection sort in C++
// By: Nick from CoffeeBeforeArch

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>

// Selection sort implementation
// More modern C++
void sort(std::vector<int> &v) {
  // Get iterators to the current element and end of the vector
  auto current = begin(v);
  auto last = end(v);

  // Keep putting elements in their correct place until we run out
  while (current != last) {
    // Find the smallest element
    auto min = std::min_element(current, last);
    // Swap it into place
    std::swap(*current, *min);
    // Find the min element for the next index
    current++;
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
