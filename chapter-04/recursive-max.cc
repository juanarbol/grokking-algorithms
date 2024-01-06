#include <cstdio>
#include <vector>
#include <stdio.h>

// Init the current maximum as the lowest number ever
int get_max_value_recursive(std::vector<int> v, int prevMax = 0) {
  // Base case, the vector is now empty
  // We can return the biggest number found
  if (v.begin() == v.end()) {
    // Nothing to sum
    return prevMax;
  }

  // Compare last number with the maximum (at least for now)
  if (v.back() > prevMax) {
    prevMax = v.back();
  }

  // Get rid of the last element
  v.pop_back();
  // Call this thing recursively
  // The final result could be like 1 + 1 + ... v.size() times
  return get_max_value_recursive(v, prevMax);
}

int main () {
  // Waiting that to be 11 ALWAYS
  std::vector<int> numberList = {1,2,3,4, 11 ,5,6,7};
  printf("The biggest number in the list is %d\n",
         get_max_value_recursive(numberList));
  return 0;
}
