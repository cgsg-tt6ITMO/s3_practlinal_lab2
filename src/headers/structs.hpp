/* File name     : structs.hpp
 * Creation date : 02.10.2023
 * Programmer    : Troitskaya Tamara
 * Purpose       : Functions for matrices.
 */
#pragma once

#include <iostream>
#include <stdlib.h>   // malloc

/* Namespace for math */
namespace math {

  struct matrix {
    size_t n, m;
    int64_t** arr;
  };
}

typedef struct math::matrix matrix;

/* Namespace for math */
namespace math {
  /* Allocates memory for two dimensional array nxm.
   *   Arguments:
   *     - sizes of 2D array:
   *       size_t n, size_t m.
   *   Returns:
   *     (int64_t**) - array with allocated memory.
   */
  int64_t** allocate_memory(size_t n, size_t m) {
    int64_t** res = (int64_t**)malloc(n * sizeof(int64_t*));
    for (size_t i = 0; i < n; i++) {
      res[i] = (int64_t*)malloc(m * sizeof(int64_t));
    }
    return res;
  }

  /* Initializes matrix in a shorter way.
   *   Template parameters:
   *     - size of matrix:
   *       size_t n, size_t m.
   *   Arguments:
   *     - array to be wrapped in matrix:
   *       size_t arr[n][m].
   *   Returns:
   *     (matrix) - matrix nxm.
   */
  template<size_t n, size_t m>
  matrix matr(size_t arr[n][m]) {
    int64_t** res = allocate_memory(n, m);
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        res[i][j] = arr[i][j];
      }
    }
    matrix matr = { n, m, res };
    return matr;
  }

  /* Prints matrix.
   *   Arguments:
   *     - pointer to the matrix:
   *       matrix *m.
   *   Returns: none.
   */
  void print_matrix(matrix* m) {
    for (size_t i = 0; i < m->n; i++) {
      for (size_t j = 0; j < m->m; j++) {
        std::cout << (m->arr)[i][j] << " ";
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }

  /* Multiplies two matrices. Validates sizes.
   *   Arguments:
   *     - first matrix:
   *       matrix A,
   *     - second matrix:
   *       matrix B.
   *   Returns:
   *     (matrix) - result of multiplication.
   *   Notes:
   *     Returns { 0, 0, NULL }, if matrices are incompatible.
   */
  matrix matr_mul_matr(matrix A, matrix B) {
    size_t n = A.n, m = B.m, l = A.m;
    // validate sizes
    if (l != B.n) {
      printf("Those matrices cannot be multiplied\n");
      printf("A: %zux%zu, B: %zux%zu\n", n, l, B.n, m);
      matrix res = { 0, 0, NULL };
      return res;
    }
    int64_t** a = A.arr, ** b = B.arr;
    int64_t** res = allocate_memory(n, m);
    // calculations
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        res[i][j] = 0;
        for (size_t k = 0; k < l; k++) {
          res[i][j] += a[i][k] * b[k][j];
        }
      }
    }
    matrix matr = { n, m, res };
    return matr;
  }

  /* Sum of two matrices.
   *   Arguments:
   *     - two matrices:
   *       matrix A, matrix B.
   *   Returns:
   *     (matrix) - result of sum.
   *   Notes:
   *     Returns { 0, 0, NULL }, if matrices are incompatible.
   */
  matrix matr_sum(matrix A, matrix B) {
    size_t n = A.n, m = A.m;
    // validate sizes
    if (n != B.n || m != B.m) {
      printf("Those matrices cannot be added\n");
      printf("A: %zux%zu, B: %zux%zu\n", n, m, B.n, B.m);
      matrix res = { 0, 0, NULL };
      return res;
    }
    int64_t** a = A.arr, ** b = B.arr;
    int64_t** res = allocate_memory(n, m);
    // calculations
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        res[i][j] = a[i][j] + b[i][j];
      }
    }
    matrix matr = { n, m, res };
    return matr;
  }

  /* Multiplies matrix by number.
   *   Arguments:
   *     - number:
   *       int64_t c,
   *     - matrix:
   *       matrix A.
   *   Returns:
   *     (matrix) - result of multiplication.
   */
  matrix num_mul_matr(int64_t c, matrix A) {
    size_t n = A.n, m = A.m;
    int64_t** a = A.arr;
    int64_t** res = allocate_memory(n, m);
    // calculations
    for (size_t i = 0; i < n; i++) {
      for (size_t j = 0; j < m; j++) {
        res[i][j] = c * a[i][j];
      }
    }
    matrix matr = { n, m, res };
    return matr;
  }
}