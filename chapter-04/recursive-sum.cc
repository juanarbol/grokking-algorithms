#include <vector>

int sum(std::vector<int> numbers) {
  // Base case
  if (numbers.size() == 0) return 0;

  // Get the last element
  int state = numbers.back();
  // Delete now the last element
  numbers.pop_back();
  // Recursive part
  return state + sum(numbers);
}

int main () {
  std::vector<int> numberList = {1,2,3,4,5};
  // The status code will be the result of the recursive sum;
  return sum(numberList);
}
