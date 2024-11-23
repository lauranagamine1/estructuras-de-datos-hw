#ifndef HW4_IMPL_H
#define HW4_IMPL_H

#include <string>
#include <vector>

#include "hw4.h"

std::vector<int> stringMatch_naive(std::string const& text,
                                   std::string const& pattern){
  // Implemente aqui el método mas ingenuo para resolver el problema de string
  // matching.
  // metodo ingenuo como visto en clase (algoritmo intuitivo)

  std::vector<int> ret;

  int n = text.size();
  int m = pattern.size();


  for (int j=0;j<= n-m;++j) {
      int i = 0;

      while (i < m && text[j + i] == pattern[i]) {
          ++i;
      }

      if (i == m) {
          ret.push_back(j);
      }
  }
  return ret;
}

std::vector<int> stringMatch_RabinKarp(std::string const& text,
                                       std::string const& pattern)
{
  // Implemente aqui el algoritmo de Rabin-Karp para resolver el problema
  // de string matching.

  std::vector<int> ret;
  return ret;
}

std::vector<int> stringMatch_KnuthMorrisPratt(std::string const& text,
                                              std::string const& pattern)
{
  // Implemente aqui el algoritmo de Knuth-Morris-Pratt para resolver el
  // problema de string matching.

  std::vector<int> ret;
  return ret;
}


#endif
