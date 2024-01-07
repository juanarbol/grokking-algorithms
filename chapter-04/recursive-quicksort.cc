#include <cstdio>
#include <vector>
#include <stdio.h>

std::vector<int> quick_sort(std::vector<int> list) {
  // Base case
  if (list.size() <= 1) {
    return list;
  }

  // Recursive case
  int pivot = list.at(0);
  std::vector<int> less;
  std::vector<int> greather;

  for (int number : list) {
    if (number > pivot) {
      greather.push_back(number);
    } else {
      less.push_back(number);
    }
  }

  std::vector<int>::iterator it;
  std::vector<int> sortedVec;
  std::vector<int> lessSortedVec = quick_sort(less);
  std::vector<int> greatherSortedVec = quick_sort(greather);
  sortedVec.insert(sortedVec.begin(), lessSortedVec.begin(), lessSortedVec.end());
  sortedVec.push_back(pivot);
  sortedVec.insert(sortedVec.end(), greatherSortedVec.begin(), greatherSortedVec.end());

  return sortedVec;
}

int main () {
  // THI IS NOT WORKING, WILL LEAVE IT AS A CHALLENEG
  // I WILL IMPLEMENT THAT IN JAVASCRIPT IN THE MEANTIME
  std::vector<int> numberList = {5,4,3,2,1};
  // The status code will be the result of the recursive sum;
  std::vector<int> sorted = quick_sort(numberList);

  printf("Sorted array:\n");
  for (int n : sorted) {
    printf("%d,", n);
  }

  return 0;
}
