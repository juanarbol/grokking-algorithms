#include <iostream>

int binary_search (int list[], int size, int element) {
  int low = 0;
  int hight = size;
  int mid = 0;

  while (low <= hight) {
    // Parenthesis are SO IMPORTANT
    mid = (low + hight) / 2;

    if (list[mid] == element) {
      return mid;
    }

    if (list[mid] > element) {
      hight = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return -1;
}

int recursive (int list[], int l, int h, int element) {
  if (l > h) return -1;

  // Parenthesis are SO IMPORTANT
  int m = (l + h) / 2;

  if (list[m] == element) {
    return m;
  }

  if (list[m] > element) {
    return recursive(list, l, m - 1, element);
  }

  return recursive(list, m + 1, h, element);
}

int main () {
  int list[] = {1,2,3,4,5,6,7};
  // Size in bytes allocated / size of each element's type in bytes -1 = size of array
  int size = sizeof(list) / sizeof(list[0]) -1;


  std::cout << binary_search(list, size, 5) << '\n';
  std::cout << recursive(list, 0, size, 1) << '\n';

  return 0;
}
