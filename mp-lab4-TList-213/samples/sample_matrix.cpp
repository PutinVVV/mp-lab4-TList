// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
#include "Vector.h"

void main()
{
 int q=4;
  cout << "Test matrix" << endl;
  TMatrix<int> A(q,q), B(q,q), C(q,q);
  cout << "Matrix A and B: " << endl;
  cout << "A:" << endl << A << endl;
  cout << "B:" << endl << B << endl;
  cout << "+: " << endl;
  C = A + B;
  cout << "A + B:" << endl;
  cout<< C << endl;

  C=A - B;
  cout << "-: " << endl;
  cout << "A - B:" << endl << C << endl;
}
