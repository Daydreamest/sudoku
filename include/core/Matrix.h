#ifndef MATRIX_H
#define MATRIX_H

#include <array>

template <class T, size_t ROW, size_t COL>
using Matrix = std::array<std::array<T, COL>, ROW>;

#endif // MATRIX_H
