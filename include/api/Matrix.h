#ifndef MATRIX_H
#define MATRIX_H

#include <array>

template <class T, size_t ROW, size_t COL>
using Matrix = std::array<std::array<T, COL>, ROW>;

template <class T>
using SudokuTable = Matrix<T, 9, 9>;

template <class T>
using SudokuTile = Matrix<T, 3, 3>;

template <class T, size_t length>
using Row = std::array<T, length>;

template <class T>
using SudokuRow = Row<T, 9>;

template <class T, size_t length>
using Column = std::array<T, length>;

template <class T>
using SudokuColumn = Column<T, 9>;

#endif // MATRIX_H
