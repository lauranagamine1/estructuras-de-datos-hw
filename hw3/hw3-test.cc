#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "hw3.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(HW3Tests, test1) {
  BST<int> t;

  ASSERT_TRUE(t.size() == 0);
}

TEST(HW3Tests, test2) {
  BST<int> t;

  t.insert(4);
  t.insert(2);
  t.insert(5);
  t.insert(3);

  ASSERT_TRUE(t.size() == 4);
  ASSERT_TRUE(t.isEmpty() == false);
  ASSERT_TRUE(t.findMin() == 2);
  ASSERT_TRUE(t.findMax() == 5);
}

