#include <iostream>
#include <vector>

#include "gtest/gtest.h"

#include "hw1.h"

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

TEST(AVLTreeTests, test1) {
  AVLTree<int> tree;

  std::vector<int> detected = tree.inorderTraversal();
  std::vector<int> expected{};

  ASSERT_TRUE(detected == expected);
}

TEST(AVLTreeTests, test2) {
  AVLTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  std::vector<int> detected = tree.inorderTraversal();
  std::vector<int> expected{10, 20, 25, 30, 40, 50};

  ASSERT_TRUE(detected == expected);
}

TEST(AVLTreeTests, test3) {
  AVLTree<int> tree;

  tree.insert(10);
  tree.insert(20);
  tree.insert(30);
  tree.insert(40);
  tree.insert(50);
  tree.insert(25);

  std::vector<int> detected = tree.inorderTraversal();
  std::vector<int> expected{10, 20, 25, 30, 40, 50};

  ASSERT_TRUE(detected == expected);

  tree.remove(10);

  std::vector<int> detected2 = tree.inorderTraversal();
  std::vector<int> expected2{20, 25, 30, 40, 50};

  ASSERT_TRUE(detected2 == expected2);
}

TEST(AVLTreeTests, test4) {
  AVLTree<int> tree;

  tree.insert(10);
  ASSERT_TRUE(tree.height() == 0);

  tree.insert(20);
  ASSERT_TRUE(tree.height() == 1);

  tree.insert(30);
  ASSERT_TRUE(tree.height() == 2);

  tree.insert(40);
  ASSERT_TRUE(tree.height() == 2);

  tree.insert(50);
  ASSERT_TRUE(tree.height() == 3);

  tree.insert(25);
  ASSERT_TRUE(tree.height() == 3);

  std::vector<int> detected = tree.inorderTraversal();
  std::vector<int> expected{10, 20, 25, 30, 40, 50};

  ASSERT_TRUE(detected == expected);

  ASSERT_TRUE(tree.search(10) == true);
  tree.remove(10);
  ASSERT_TRUE(tree.search(10) == false);

  std::vector<int> detected2 = tree.inorderTraversal();
  std::vector<int> expected2{20, 25, 30, 40, 50};

  ASSERT_TRUE(detected == expected);

  ASSERT_TRUE(tree.search(20) == true);
  ASSERT_TRUE(tree.search(25) == true);
  ASSERT_TRUE(tree.search(30) == true);
  ASSERT_TRUE(tree.search(40) == true);
  ASSERT_TRUE(tree.search(50) == true);
  ASSERT_TRUE(tree.search(15) == false);
}
