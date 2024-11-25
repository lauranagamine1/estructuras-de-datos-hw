#include <gtest/gtest.h>
#include "hw4.h" // Archivo con las implementaciones

TEST(StringMatchTest, NaiveMatch) {
std::string text = "abracadabra";
std::string pattern = "abra";
std::vector<int> expected = {0, 7};
EXPECT_EQ(stringMatch_naive(text, pattern), expected);
}

TEST(StringMatchTest, RabinKarpMatch) {
std::string text = "abracadabra";
std::string pattern = "abra";
std::vector<int> expected = {0, 7};
EXPECT_EQ(stringMatch_RabinKarp(text, pattern), expected);
}

TEST(StringMatchTest, KnuthMorrisPrattMatch) {
std::string text = "abracadabra";
std::string pattern = "abra";
std::vector<int> expected = {0, 7};
EXPECT_EQ(stringMatch_KnuthMorrisPratt(text, pattern), expected);
}

TEST(StringMatchTest, NoMatch) {
std::string text = "abracadabra";
std::string pattern = "xyz";
std::vector<int> expected = {};
EXPECT_EQ(stringMatch_naive(text, pattern), expected);
EXPECT_EQ(stringMatch_RabinKarp(text, pattern), expected);
EXPECT_EQ(stringMatch_KnuthMorrisPratt(text, pattern), expected);
}

TEST(StringMatchTest, OverlappingMatch) {
std::string text = "aaaaa";
std::string pattern = "aaa";
std::vector<int> expected = {0, 1, 2};
EXPECT_EQ(stringMatch_naive(text, pattern), expected);
EXPECT_EQ(stringMatch_RabinKarp(text, pattern), expected);
EXPECT_EQ(stringMatch_KnuthMorrisPratt(text, pattern), expected);
}
