// Implementation of merge sort
// By: Nick from CoffeeBeforeArch

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void merge(std::vector<int> &v, int start_l, int stop_l, int start_r,
           int stop_r) {
  // Extract the sorted subvectors
  std::vector<int> sorted_left(begin(v) + start_l, begin(v) + stop_l + 1);
  std::vector<int> sorted_right(begin(v) + start_r, begin(v) + stop_r + 1);
  
  // Merge them in sorted order
  unsigned l_idx = 0;
  unsigned r_idx = 0;
  unsigned v_idx = start_l;
  while (l_idx < sorted_left.size() && r_idx < sorted_right.size()) {
    // Take from the left if it's less than the right
    if (sorted_left[l_idx] < sorted_right[r_idx]) {
      v[v_idx] = sorted_left[l_idx];
      l_idx++;
      // Otherwise take from the right
    } else {
      v[v_idx] = sorted_right[r_idx];
      r_idx++;
    }
    // Always increment the main vector position
    v_idx++;
  }

  // Drain the remaining elements
  while (l_idx < sorted_left.size()) {
    v[v_idx] = sorted_left[l_idx];
    l_idx++;
    v_idx++;
  }
  while (r_idx < sorted_right.size()) {
    v[v_idx] = sorted_right[r_idx];
    r_idx++;
    v_idx++;
  }
}

void merge_sort(std::vector<int> &v, int start, int stop) {
  // If we aren't left with a single element
  if (start < stop) {
    // Cut the vector in half (find the start/stop points)
    int start_l = start;
    int stop_l = (stop - start) / 2 + start;
    int start_r = stop_l + 1;
    int stop_r = stop;

    // Merge sort on the two sub-vectors
    merge_sort(v, start_l, stop_l);
    merge_sort(v, start_r, stop_r);

    // Then merge the sorted sub-vectors
    merge(v, start_l, stop_l, start_r, stop_r);
  }
}

// Merge sort implementation
void sort(std::vector<int> &values) {
  merge_sort(values, 0, values.size() - 1);
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
