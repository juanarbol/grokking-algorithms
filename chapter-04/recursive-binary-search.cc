#include <vector>
#include <stdio.h>

// Init the current maximum as the lowest number ever
int binary_search_recursive(std::vector<int> v, int l, int h, int numberToFind) {
  // Not found
  if (l > h) {
    return -1;
  }

  // Base case, nothing else to do
  int middle = (int)(l + h) / 2;
  if (v[middle] == numberToFind) {
    return middle;
  }

  // Recurive cases
  if (v[middle] > numberToFind) {
    // Discard upper middle
    return binary_search_recursive(v, l, middle - 1, numberToFind);
  } else {
    // Move lower to middle + 1
    return binary_search_recursive(v, middle + 1, h, numberToFind);
  }
}

int main () {
  // The vector must be sorted
  std::vector<int> numberList = {1,2,3,4,5,6,7,8};
  int numberToFind = 2;
  printf("The index of the requested number (%d) in the list is %d\n",
         numberToFind,
         binary_search_recursive(numberList, 0, numberList.size() - 1, numberToFind));
  return 0;
}
