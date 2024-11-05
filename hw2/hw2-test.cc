#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "hw2.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

template <typename T>
bool operator==(std::vector<T> const& a, std::vector<T> const& b) {
  if (a.size() != b.size()) return false;
  for (int i = 0; i < a.size(); ++i)
    if (a[i] != b[i]) return false;
  return true;
}

TEST(HW2Tests, test1) {
  Heap<int> h(true);

  ASSERT_TRUE(h.size() == 0);
}

TEST(HW2Tests, test2) {
  Heap<int> h(false);

  ASSERT_TRUE(h.size() == 0);
}

TEST(HW2Tests, test3) {
  Heap<int> h(true);

  h.insert(4);
  h.insert(5);
  h.insert(1);
  h.insert(3);

  ASSERT_TRUE(h.size() == 4);
  ASSERT_TRUE(h.peek() == 1);
}
