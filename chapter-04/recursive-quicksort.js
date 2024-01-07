'use strict'

function quickSort (list) {
  // Base case
  if (list.length <= 1) {
    return list
  }

  const pivot = list[0]
  const greater = list.filter(n => n > pivot)
  const smaller = list.filter(n => n < pivot)

  return [...quickSort(smaller), pivot, ...quickSort(greater)]
}

const list = [9,8,7,6,5,4,3,2,1]
console.log(quickSort(list))
