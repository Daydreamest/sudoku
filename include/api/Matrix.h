#ifndef MATRIX_H
#define MATRIX_H

#include <array>

template <class T, size_t ROW, size_t COL>
using GenericMatrix = std::array<std::array<T, COL>, ROW>;

template <class T>
using Table = GenericMatrix<T, 9, 9>;

template <class T>
using Tile = GenericMatrix<T, 3, 3>;

template <class T, size_t length>
using GenericRow = std::array<T, length>;

template <class T>
using Row = GenericRow<T, 9>;

template <class T, size_t length>
using GenericColumn = std::array<T, length>;

template <class T>
using Column = GenericColumn<T, 9>;

#endif // MATRIX_H
