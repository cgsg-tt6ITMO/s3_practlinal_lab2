/* File name     : app.cpp
 * Creation date : 02.10.2023
 * Programmer    : Troitskaya Tamara
 * Purpose       : Launches the application.
 */
#include "headers/structs.hpp"

/* Main function */
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
    m31 = math::matr<3, 3>(a31),
    m32 = math::matr<3, 3>(a32),
    m1 = math::matr_sum(m31, math::num_mul_matr(-1, m32));

  math::print_matrix(&m1);

  return 0;
}
