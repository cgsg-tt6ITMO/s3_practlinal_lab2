/* File name     : structs.hpp
 * Creation date : 02.10.2023
 * Programmer    : Troitskaya Tamara
 * Purpose       : Functions for matrices.
 */
#pragma once

#include <iostream>
#include <stdlib.h>   // malloc
#include <fstream>    // files
#include <sstream>    // getline
#include <string>

/* Namespace for math */
namespace math {

  const double PI = 3.14159265359, SQRT_PI = sqrt(PI);

  struct matrix {
    size_t n, m;
    double** arr;
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
   *     (double**) - array with allocated memory.
   */
  double** allocate_memory(size_t n, size_t m);

  /* Initializes matrix in a shorter way.
   *   Template parameters:
   *     - size of matrix:
   *       size_t n, size_t m.
   *   Arguments:
   *     - array to be wrapped in matrix:
   *       double arr[n][m].
   *   Returns:
   *     (matrix) - matrix nxm.
   */
  template<size_t n, size_t m>
  matrix matr(double arr[n][m]) {
    double** res = allocate_memory(n, m);
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
  void matr_print(matrix* m);

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
   *       double c,
   *     - matrix:
   *       matrix A.
   *   Returns:
   *     (matrix) - result of multiplication.
   */
  matrix num_mul_matr(double c, matrix A);

  /* Transposes the matrix.
   *   Arguments:
   *     - the matrix:
   *       matrix m.
   *   Returns:
   *     (matrix) - transposed matrix.
   */
  matrix matr_transpose(matrix m);

  /* Calculates minor of the matrix.
   *   Arguments:
   *     - pointer to the matrix nxm:
   *       matrix* M.
   *     - indexes of row and column to be deleted:
   *       size_t x, size_t y.
   *   Returns:
   *     (matrix) - minor matrix (n-1)x(m-1)
   */
  matrix matr_minor(matrix* M, size_t x, size_t y);

  /* Calculates the determinant.
   *   Arguments:
   *     - pointer to the matrix:
   *       matrix *M.
   *   Returns:
   *     (double) - the determinant.
   */
  double determinant(matrix* M);

  /* Calculates inverted matrix.
   *   Arguments:
   *     - pointer to matrix to be inverted:
   *       matrix* M.
   *   Returns:
   *     (matrix) - the inverted matrix.
   */
  matrix matr_invert(matrix* M);

  /* There is an equation A * B = C. Get matrix A.
   *   Arguments:
   *     - matrix B:
   *       matrix B,
   *     - matrix C:
   *       matrix C.
   *   Returns:
   *     (matrix) - matrix A.
   */
  matrix get_matrix(matrix B, matrix C);

  matrix matr_from_file();
}
