#ifndef HW2_IMPL_H
#define HW2_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw2.h"

// Heap

template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap) {
  // COMPLETE HERE
}

template <typename T>
void Heap<T>::insert(T const& element) {
  // COMPLETE HERE
}

template <typename T>
T Heap<T>::extractTop() {
  // COMPLETE HERE
  return T{};
}

template <typename T>
T Heap<T>::peek() const {
  // COMPLETE HERE
  return T{};
}

template <typename T>
size_t Heap<T>::size() const {
  // COMPLETE HERE
  return 0;
}

template <typename T>
bool Heap<T>::isEmpty() const {
  // COMPLETE HERE
  return true;
}


template <typename T>
void Heap<T>::clear() {
  // COMPLETE HERE
}

#endif
