#include <iostream>
#include <string>
#include <vector>

#include "gtest/gtest.h"

#include "hw4.h"

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(HW4Tests, test1) {
  std::string text{"This is a text"};
  std::string pattern{"pattern"};

  std::vector<int> t1 = stringMatch_naive(text, pattern);
  std::vector<int> t2 = stringMatch_RabinKarp(text, pattern);
  std::vector<int> t3 = stringMatch_KnuthMorrisPratt(text, pattern);

  ASSERT_TRUE(t1.size() == 0);
  ASSERT_TRUE(t2.size() == 0);
  ASSERT_TRUE(t3.size() == 0);
}

TEST(HW4Tests, test2) {
  std::string text{"This is a text"};
  std::string pattern{"is"};

  std::vector<int> t1 = stringMatch_naive(text, pattern);
  std::vector<int> t2 = stringMatch_RabinKarp(text, pattern);
  std::vector<int> t3 = stringMatch_KnuthMorrisPratt(text, pattern);

  std::vector<int> expected{2, 5};

  ASSERT_TRUE(t1 == expected);
  ASSERT_TRUE(t2 == expected);
  ASSERT_TRUE(t3 == expected);
}
