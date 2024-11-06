#ifndef HW2_IMPL_H
#define HW2_IMPL_H

#include <algorithm>
#include <cstdlib>
#include <vector>

#include "hw2.h"

// Heap

int getParent(int index) {
    return (index - 1) / 2;
}

int getLeft(int index) {
    return 2 * index + 1;
}

int getRight(int index) {
    return 2 * index + 2;
}

template <typename T>
Heap<T>::Heap(bool isMinHeap) : minHeap(isMinHeap) {
  // COMPLETE HERE
}

template <typename T>
void Heap<T>::insert(T const& element) {
    int index = heap.size();

    heap.push_back(element);

    while(index > 0 && (minHeap ? heap[index] < heap[getParent(index)] : heap[index] > heap[getParent(index)])) {
        //Mientras no seamos root, y el elemento en el nodo padre no cumpla la condicion del heap, swapeamos y repetimos para el nodo padre.
        std::swap(heap[index], heap[getParent(index)]);
        index = getParent(index);
    }
}

template <typename T>
T Heap<T>::extractTop() {
    if(heap.size() == 0) {
        return T{};
    }

    T top = heap[0];

    //Swapeamos el primer elemento con el ultimo, y eliminamos el nuevo ultimo (que anteriormente era el primero, o sea el que queremos eliminar)
    std::swap(heap[0], heap.back());
    heap.pop_back();

    int index = 0;
    while(true) {
        int left_index = getLeft(index);
        int right_index = getRight(index);
        bool exists_left = left_index < heap.size();
        bool exists_right = right_index < heap.size();

        if(exists_left) {
            //Si hay nodo izquierdo, debemos elegir el menor (en caso de min heap) entre los hijos.
            int swap_index;
            if(exists_right) {
                //Si hay nodo derecho, elegimos el menor (en caso de min heap) entre el izquierdo y derecho
                if(minHeap) {
                    swap_index = heap[left_index] < heap[right_index] ? left_index : right_index;
                } else {
                    swap_index = heap[left_index] > heap[right_index] ? left_index : right_index;
                }
            } else {
                //Si no hay nodo derecho, el menor será el izquierdo.
                swap_index = left_index;
            }

            if(minHeap ? heap[index] > heap[swap_index] : heap[index] < heap[swap_index]) {
                //Si el nodo actual es mayor al menor de los hijos (en caso de min heap), los swapeamos.
                std::swap(heap[index], heap[swap_index]);
                index = swap_index;
            } else {
                //Si el nodo actual es menor o igual al menor de los hijos (en caso de min heap), se cumple la condición del heap y terminamos el bucle.
                break;
            }
        } else {
            //Si no hay nodo izquierdo, el nodo no tiene hijos y por ende ya se cumple la condicion de heap y terminamos el bucle.
            break;
        }
    }

    return top;
}

template <typename T>
T Heap<T>::peek() const {
    if(heap.size() == 0) {
        return T{};
    }

    //Retornamos el primer elemento;
    return heap[0];
}

template <typename T>
size_t Heap<T>::size() const {
    return heap.size();
}

template <typename T>
bool Heap<T>::isEmpty() const {
    return heap.size() == 0;
}


template <typename T>
void Heap<T>::clear() {
    heap.clear();
}

#endif
