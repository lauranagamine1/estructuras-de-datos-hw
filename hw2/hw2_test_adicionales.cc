//
// Created by laura on 9/11/2024.
//
#include <iostream>
#include <vector>

#include "gtest/gtest.h"
#include "hw2.h"

// Operador para comparar vectores en los tests
template <typename T>
bool operator==(std::vector<T> const& a, std::vector<T> const& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i]) return false;
    return true;
}

// Test de inicialización y tamaño
TEST(HW2Tests, InitializationAndSize) {
Heap<int> minHeap(true);
Heap<int> maxHeap(false);

ASSERT_EQ(minHeap.size(), 0);
ASSERT_EQ(maxHeap.size(), 0);
ASSERT_TRUE(minHeap.isEmpty());
ASSERT_TRUE(maxHeap.isEmpty());
}

// Test de inserción y verificación de la raíz (min-heap)
TEST(HW2Tests, MinHeapInsertAndPeek) {
Heap<int> minHeap(true);
minHeap.insert(4);
minHeap.insert(5);
minHeap.insert(1);
minHeap.insert(3);

ASSERT_EQ(minHeap.size(), 4);
ASSERT_EQ(minHeap.peek(), 1);  // Menor elemento
}

// Test de inserción y verificación de la raíz (max-heap)
TEST(HW2Tests, MaxHeapInsertAndPeek) {
Heap<int> maxHeap(false);
maxHeap.insert(4);
maxHeap.insert(5);
maxHeap.insert(1);
maxHeap.insert(3);

ASSERT_EQ(maxHeap.size(), 4);
ASSERT_EQ(maxHeap.peek(), 5);  // Mayor elemento
}

// Test de extracción de la raíz (min-heap)
TEST(HW2Tests, MinHeapExtractTop) {
Heap<int> minHeap(true);
minHeap.insert(4);
minHeap.insert(5);
minHeap.insert(1);
minHeap.insert(3);

ASSERT_EQ(minHeap.extractTop(), 1);
ASSERT_EQ(minHeap.extractTop(), 3);
ASSERT_EQ(minHeap.extractTop(), 4);
ASSERT_EQ(minHeap.extractTop(), 5);
ASSERT_TRUE(minHeap.isEmpty());
}

// Test de extracción de la raíz (max-heap)
TEST(HW2Tests, MaxHeapExtractTop) {
Heap<int> maxHeap(false);
maxHeap.insert(4);
maxHeap.insert(5);
maxHeap.insert(1);
maxHeap.insert(3);

ASSERT_EQ(maxHeap.extractTop(), 5);
ASSERT_EQ(maxHeap.extractTop(), 4);
ASSERT_EQ(maxHeap.extractTop(), 3);
ASSERT_EQ(maxHeap.extractTop(), 1);
ASSERT_TRUE(maxHeap.isEmpty());
}

// Test de inserciones y borrado completo
TEST(HW2Tests, ClearHeap) {
Heap<int> minHeap(true);
minHeap.insert(4);
minHeap.insert(5);
minHeap.insert(1);
minHeap.insert(3);

minHeap.clear();
ASSERT_EQ(minHeap.size(), 0);
ASSERT_TRUE(minHeap.isEmpty());
}

// Test de extracción en heap vacío
TEST(HW2Tests, ExtractTopOnEmptyHeap) {
Heap<int> minHeap(true);
ASSERT_EQ(minHeap.extractTop(), int{});  // Esperamos el valor predeterminado para int
}

// Test de funcionamiento con datos negativos en min-heap
TEST(HW2Tests, MinHeapWithNegativeNumbers) {
Heap<int> minHeap(true);
minHeap.insert(-4);
minHeap.insert(-1);
minHeap.insert(-3);
minHeap.insert(-5);

ASSERT_EQ(minHeap.extractTop(), -5);
ASSERT_EQ(minHeap.extractTop(), -4);
ASSERT_EQ(minHeap.extractTop(), -3);
ASSERT_EQ(minHeap.extractTop(), -1);
ASSERT_TRUE(minHeap.isEmpty());
}

// Test de funcionamiento con datos negativos en max-heap
TEST(HW2Tests, MaxHeapWithNegativeNumbers) {
Heap<int> maxHeap(false);
maxHeap.insert(-4);
maxHeap.insert(-1);
maxHeap.insert(-3);
maxHeap.insert(-5);

ASSERT_EQ(maxHeap.extractTop(), -1);
ASSERT_EQ(maxHeap.extractTop(), -3);
ASSERT_EQ(maxHeap.extractTop(), -4);
ASSERT_EQ(maxHeap.extractTop(), -5);
ASSERT_TRUE(maxHeap.isEmpty());
}

// Test de mezcla de números positivos y negativos
TEST(HW2Tests, MixedNumbersInMinHeap) {
Heap<int> minHeap(true);
minHeap.insert(0);
minHeap.insert(-10);
minHeap.insert(15);
minHeap.insert(-5);
minHeap.insert(20);

ASSERT_EQ(minHeap.extractTop(), -10);
ASSERT_EQ(minHeap.extractTop(), -5);
ASSERT_EQ(minHeap.extractTop(), 0);
ASSERT_EQ(minHeap.extractTop(), 15);
ASSERT_EQ(minHeap.extractTop(), 20);
ASSERT_TRUE(minHeap.isEmpty());
}
