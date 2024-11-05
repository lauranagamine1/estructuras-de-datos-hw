#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "hw5.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(HW5Tests, test1) {
  std::vector<std::vector<int>> g;

  ASSERT_TRUE(n_vertices(g) == 0);
  ASSERT_TRUE(n_edges(g) == 0);
  ASSERT_TRUE(n_connected_components(g) == 0);
}

TEST(HW5Tests, test2) {
  std::vector<std::vector<int>> g{{1,2,3},{},{},{}};

  ASSERT_TRUE(n_vertices(g) == 4);
  ASSERT_TRUE(n_edges(g) == 3);
  ASSERT_TRUE(n_connected_components(g) == 1);
}

