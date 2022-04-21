#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    // Напишите здесь свой код ...
    return ((pow(1 + sqrt(5), n) - pow(1 - sqrt(5),n))) / (pow(2,n) * sqrt(5));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    // Напишите здесь свой код ...
    for (int i = 0; i < n; i++) {
      fib_curr += fib_prev;
      fib_prev = fib_curr - fib_prev;
    }
    return fib_prev;

  }

  int64_t fib_recursive(int n) {

    // Напишите здесь свой код ...
    if (n <= 0) {
      return 0;
    } else if (n == 1) {
      return n;
    } else {
      return fib_recursive(n-1) + fib_recursive(n-2);
    }
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      // Напишите здесь свой код ...
      return cache[n];
    }

    // Напишите здесь свой код ...
    cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);
    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    // Напишите здесь свой код ...
    Matrix2x2 FibMatrix = {{{0, 1}, {1, 1}}};
    FibMatrix = matrix_power(FibMatrix, n-1);

    // Tip: используйте реализованную функцию matrix_pow

    return FibMatrix[0][0] + FibMatrix[1][0];
  }

}  // namespace assignment
