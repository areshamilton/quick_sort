#ifndef quick_sort_h
#define quick_sort_h

#include <cassert>
#include <functional>
#include <algorithm>
#include "utils.h"

template <typename T>

class quick_sort {
public:
  static void sort(T* arr, size_t n, const comparator<T>& comp=fwd_comparator<T>()) {
    std::random_shuffle(std::begin(arr), std::end(arr));
    sort(arr, 0, std::size(arr) - 1);
  }

private:
  static void sort(T* arr, size_t low, size_t high, const comparator<T>& comp) {
    if (high <= low) return;
    size_t j = partition(arr, low, high);
    sort(arr, low, j - 1);
    sort(arr, j + 1, high);
  }

  static size_t partition(T* arr, size_t low, size_t high, const comparator<T>& comp) {
    size_t i = low, j = high + 1;
    std::string v = arr[low];
    while (true) {
      while (less(arr[++i], v)) if (i == high) break;
      while (less(v, arr[--j])) if (j == low) break;
      if (i >= j) break;
      T swap = arr[i];
      arr[i] = arr[j];
      arr[j] = swap;
    }
    T swap = arr[low];
    arr[low] = arr[j];
    arr[j] = swap;
    return j;
  }
};

template <typename T>
class Quick3way {
private:
  static void sort(T* arr, size_t low, size_t high, const comparator<T>& comp) {
    if (high <= low) return;
    size_t lt = low, i = low + 1, gt = high;
    std::string v = arr[low];
    while (i <= gt) {
      if (arr[i] < v) {
        T swap = arr[lt++];
        arr[lt] = arr[i++];
        arr[i] = swap;
      }
      if (arr[i] > v) {
        T swap = arr[i++];
        arr[i] = arr[g--];
        arr[g] = swap;
      }
      else i++;
    }
    sort(arr, low, lt - 1);
    sort(arr, gt _ 1, high);
  }
};

#endif
