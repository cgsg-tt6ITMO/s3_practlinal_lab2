/* File name     : structs.cpp
 * Creation date : 02.10.2023
 * Programmer    : Troitskaya Tamara
 * Purpose       : Functions for matrices.
 */

#include "headers/structs.hpp"

  /* Allocates memory for two dimensional array nxm.
   *   Arguments:
   *     - sizes of 2D array:
   *       size_t n, size_t m.
   *   Returns:
   *     (int64_t**) - array with allocated memory.
   */
  int64_t** math::allocate_memory(size_t n, size_t m) {
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
  matrix math::matr(size_t arr[n][m]) {
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
  void math::print_matrix(matrix* m) {
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
  matrix math::matr_mul_matr(matrix A, matrix B) {
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


/* Main function.
 */
int main() {
  size_t n = 3;

  size_t a31[3][3] = {
   {1,0,0},
   {4,7,0},
   {7,8,11}
  };

  size_t a32[3][3] = {
   {1,0,0},
   {0,1,0},
   {0,0,1}
  };

  size_t a33[2][3] = {
    {1, 2, 2},
    {3, 1, 1}
  };

  size_t a34[3][2] = {
    {4, 2},
    {3, 1},
    {1, 5}
  };

  matrix
    m31 = math::matr<2, 3>(a33),
    m32 = math::matr<3, 2>(a34),
    mul = math::matr_mul_matr(m31, m32),
    mul2 = math::matr_mul_matr(m32, m31);

  math::print_matrix(&mul);
  math::print_matrix(&mul2);

  return 0;
}
