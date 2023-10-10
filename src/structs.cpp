/* File name     : structs.cpp
 * Creation date : 04.10.2023
 * Programmer    : Troitskaya Tamara
 * Purpose       : Matrix functions.
 */
#include "headers/structs.hpp"

/* Allocates memory for two dimensional array nxm.
 *   Arguments:
 *     - sizes of 2D array:
 *       size_t n, size_t m.
 *   Returns:
 *     (double**) - array with allocated memory.
 */
double** math::allocate_memory(size_t n, size_t m) {
  double** res = (double**)malloc(n * sizeof(double*));
  for (size_t i = 0; i < n; i++) {
    res[i] = (double*)malloc(m * sizeof(double));
  }
  return res;
}

/* Prints matrix.
 *   Arguments:
 *     - pointer to the matrix:
 *       matrix *m.
 *   Returns: none.
 */
void math::matr_print(matrix* m) {
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
  double** a = A.arr, ** b = B.arr;
  double** res = allocate_memory(n, m);
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
matrix math::matr_sum(matrix A, matrix B) {
  size_t n = A.n, m = A.m;
  // validate sizes
  if (n != B.n || m != B.m) {
    printf("Those matrices cannot be added\n");
    printf("A: %zux%zu, B: %zux%zu\n", n, m, B.n, B.m);
    matrix res = { 0, 0, NULL };
    return res;
  }
  double** a = A.arr, ** b = B.arr;
  double** res = allocate_memory(n, m);
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
 *       double c,
 *     - matrix:
 *       matrix A.
 *   Returns:
 *     (matrix) - result of multiplication.
 */
matrix math::num_mul_matr(double c, matrix A) {
  size_t n = A.n, m = A.m;
  double** a = A.arr;
  double** res = allocate_memory(n, m);
  // calculations
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < m; j++) {
      res[i][j] = c * a[i][j];
    }
  }
  matrix matr = { n, m, res };
  return matr;
}

/* Transposes the matrix.
 *   Arguments:
 *     - the matrix:
 *       matrix m.
 *   Returns:
 *     (matrix) - transposed matrix.
 */
matrix math::matr_transpose(matrix m) {
  double** res = allocate_memory(m.m, m.n);
  for (size_t i = 0; i < m.m; i++) {
    for (size_t j = 0; j < m.n; j++) {
      res[i][j] = m.arr[j][i];
    }
  }
  return matrix{ m.m, m.n, res };
}

/* Calculates minor of the matrix.
 *   Arguments:
 *     - pointer to the matrix nxm:
 *       matrix* M.
 *     - indexes of row and column to be deleted:
 *       size_t x, size_t y.
 *   Returns:
 *     (matrix) - minor matrix (n-1)x(m-1)
 */
matrix math::matr_minor(matrix* M, size_t x, size_t y) {
  size_t n = M->n, m = M->m;
  double** a = M->arr;
  double** res = allocate_memory(n - 1, m - 1);
  size_t i_m = 0, j_m;
  for (size_t i = 0; i < n; i++) {
    if (i == x) continue;
    j_m = 0;
    for (size_t j = 0; j < m; j++) {
      if (j != y && i_m < (n - 1) && j_m < (m - 1)) {
        res[i_m][j_m] = a[i][j];
        j_m++;
      }
    }
    if (i != x) {
      i_m++;
    }
  }
  return matrix{ n - 1, m - 1, res };
}

/* Calculates the determinant.
 *   Arguments:
 *     - pointer to the matrix:
 *       matrix *M.
 *   Returns:
 *     (double) - the determinant.
 */
double math::determinant(matrix* M) {
  size_t n = M->n;
  if (n != M->m) {
    std::cout << "This matrix is not squared, determinant cannot be calculated."
      << std::endl;
  }
  double** a = M->arr;
  if (M->n == 1) return a[0][0];
  if (M->n == 2) return a[0][0] * a[1][1] - a[0][1] * a[1][0];

  double res = 0, coef = 1;
  for (size_t i = 0; i < n; i++) {
    matrix cur_minor = matr_minor(M, 0, i);
    res += coef * a[0][i] * determinant(&cur_minor);
    coef *= -1;
  }
  return res;
}

/* Calculates inverted matrix.
 *   Arguments:
 *     - pointer to matrix to be inverted:
 *       matrix* M.
 *   Returns:
 *     (matrix) - the inverted matrix.
 */
matrix math::matr_invert(matrix* M) {
  size_t n = M->n, m = M->m;
  if (n != m) {
    std::cout << "This matrix cannot be inverted." << std::endl;
    return matrix{ 0, 0, NULL };
  }
  double** arr = allocate_memory(n, m);
  double coef;
  // adjusted
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      if (i % 2 != j % 2) {
        coef = -1;
      }
      else coef = 1;
      matrix minorr = matr_minor(M, i, j);
      arr[i][j] = determinant(&minorr) * coef;
    }
  }
  // transpose
  matrix res = matr_transpose(matrix{ n, m, arr });
  // multiply to inv to det
  return num_mul_matr(1.0 / determinant(M), res);
}

/* There is an equation A * B = C. Get matrix A.
 *   Arguments:
 *     - matrix B:
 *       matrix B,
 *     - matrix C:
 *       matrix C.
 *   Returns:
 *     (matrix) - matrix A.
 */
matrix math::get_matrix(matrix B, matrix C) {
  return matr_mul_matr(C, matr_invert(&B));
}

/* Get matrix from file.
 */
matrix math::matr_from_file() {
  // Create a text string, which is used to output the text file
  std::string myText;
  // Read from the text file
  std::ifstream MyReadFile("src/files/a.txt");
  // Use a while loop together with the getline() function to read the file line by line
  while (std::getline(MyReadFile, myText)) {
    // Output the text from the file
    std::cout << myText << std::endl;
  }
  // Close the file
  MyReadFile.close();
  return matrix{ 0, 0, NULL };
}
