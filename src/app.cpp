/* File name     : app.cpp
 * Creation date : 02.10.2023
 * Programmer    : Troitskaya Tamara
 * Purpose       : Launches the application.
 */
#include "headers/structs.hpp"

/* Main function */
int main() {
  double C[2][2] = {
    {2, 0},
    {0, 6}
  };

  double B[2][2] = {
    {2, 2},
    {4, 6}
  };

  matrix
    m_b = math::matr<2, 2>(B),
    m_c = math::matr<2, 2>(C),
    m1 = math::get_matrix(m_b, m_c);

  math::matr_print(&m1);
  math::matr_from_file();
  return 0;
}
