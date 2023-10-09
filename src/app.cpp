/* File name     : app.cpp
 * Creation date : 02.10.2023
 * Programmer    : Troitskaya Tamara
 * Purpose       : Launches the application.
 */
#include "headers/structs.hpp"

/* Main function */
int main() {
  double B[2][2] = {
    {0, 1 / math::SQRT_PI},
    {1 / math::SQRT_PI, 0}
  };

  double C[2][2] = {
    {0, sqrt(6 / math::PI)},
    {sqrt(6 / math::PI), 0}
  };

  matrix
    m_b = math::matr<2, 2>(B),
    m_c = math::matr<2, 2>(C),
    m1 = math::get_matrix(m_b, m_c);

  math::matr_print(&m1);

  return 0;
}
