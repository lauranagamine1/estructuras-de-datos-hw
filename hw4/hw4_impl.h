#ifndef HW4_IMPL_H
#define HW4_IMPL_H

#include <string>
#include <vector>
#define d 256

#include "hw4.h"

std::vector<int> stringMatch_naive(std::string const& text,
                                   std::string const& pattern){
  // Implemente aqui el método mas ingenuo para resolver el problema de string
  // matching.
  // metodo ingenuo como visto en clase (algoritmo intuitivo) O(m*n)

  std::vector<int> ret;

  int n = text.size();
  int m = pattern.size();


  for (int j=0;j<= n-m; ++j) {
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

// bibliografia referenciada: https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
std::vector<int> stringMatch_RabinKarp(std::string const& text,
                                       std::string const& pattern){
  // Implemente aqui el algoritmo de Rabin-Karp para resolver el problema
  // de string matching.

    const int q = INT_MAX; // # primo para calcular el hash
    int M = pattern.size();
    int N = text.size();
    int p = 0; // hash para el patron
    int t = 0; // hash para el texto
    int h = 1;
    std::vector<int> ret;

    // h = pow(d, M-1) % q
    for (int i=0; i<(M-1); i++)
        h = (h * d) % q;

    for (int i=0; i<M; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            bool match = true;
            for (int j = 0; j < M; j++) {
                if (text[i + j] != pattern[j]) {
                    match = false;
                    break;
                }
            }
            if (match) {
                ret.push_back(i);
            }
        }

        if (i < N - M) {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0) t = (t + q);
        }
    }
  return ret;
}

// bibliografía referenciada: https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

// Función para construir el arreglo LPS (Longest Prefix Suffix) para KMP
void constructLps(std::string const& pattern, std::vector<int>& lps) {
    int M = pattern.size();
    int len = 0; // longitud del prefijo-sufijo mas largo
    lps[0] = 0;  // lps[0] siempre es 0
    int i = 1;

    while (i<M) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

std::vector<int> stringMatch_KnuthMorrisPratt(std::string const& text,
                                              std::string const& pattern){
  // Implemente aqui el algoritmo de Knuth-Morris-Pratt para resolver el
  // problema de string matching.

    int N = text.size();
    int M = pattern.size();
    std::vector<int> lps(M);
    std::vector<int> ret;

    // arreglo LPS para patron
    constructLps(pattern, lps);

    int i = 0; // index para el texto
    int j = 0; // index para el patrón

    while (i < N) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
        }

        if (j == M) {
            ret.push_back(i - j);
            j = lps[j - 1];
        } else if (i < N && text[i] != pattern[j]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return ret;
}


#endif
