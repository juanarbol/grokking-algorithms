#include <vector>

int get_vector_size_recursive(std::vector<int> v) {
  // Base case, the vector is now empty
  if (v.begin() == v.end()) {
    // Nothing to sum
    return 0;
  }

  // Get rid of the last element
  v.pop_back();
  // Call this thing recursively
  // The final result could be like 1 + 1 + ... v.size() times
  return 1 + get_vector_size_recursive(v);
}

int main () {
  std::vector<int> numberList = {1,2,3,4,5,6,7};
  // The status code will be the result of the recursive size of vector getter
  return get_vector_size_recursive(numberList);
}
