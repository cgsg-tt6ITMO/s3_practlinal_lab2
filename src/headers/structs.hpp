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
  int64_t** allocate_memory(size_t n, size_t m);

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
  void print_matrix(matrix* m);

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
  matrix matr_mul_matr(matrix A, matrix B);

  /* Sum of two matrices.
   *   Arguments:
   *     - two matrices:
   *       matrix A, matrix B.
   *   Returns:
   *     (matrix) - result of sum.
   *   Notes:
   *     Returns { 0, 0, NULL }, if matrices are incompatible.
   */
  matrix matr_sum(matrix A, matrix B);

  /* Multiplies matrix by number.
   *   Arguments:
   *     - number:
   *       int64_t c,
   *     - matrix:
   *       matrix A.
   *   Returns:
   *     (matrix) - result of multiplication.
   */
  matrix num_mul_matr(int64_t c, matrix A);
}