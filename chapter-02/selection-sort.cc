#include <vector>
#include <iostream>

int find_smallest (std::vector<int> list) {
  int s = list[0];
  int sIndex = 0;

  for (int i = 0;  i < list.size(); i++) {
    if (list[i] < s) {
      s = list[i];
      sIndex = i;
    }
  }

  return sIndex;
}

int main () {
  // Compile with: --std=c++11 --stdlib=libc++
  std::vector<int> v = {8, 4, 5, 9};
  std::vector<int> sorted;

  for (int& number: v) {
    int smallerIdx = find_smallest(v);
    sorted.push_back(v[smallerIdx]);
    // This is like python's List.pop(idx)
    v.erase(v.begin() + smallerIdx, v.begin() + smallerIdx + 1);
  }

  std::cout << "SORTED LIST:" << std::endl;
  for (int& number: sorted) {
    std::cout << number << std::endl;
  }
}
