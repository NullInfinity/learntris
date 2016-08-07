#include "Grid.hpp"

template <class T, T EmptyValue, unsigned Width, unsigned Height>
std::ostream& operator<<(std::ostream& os, const Grid<T, EmptyValue, Width, Height>& grid) {
  for (unsigned row=0; row<Height; ++row) {
    for (unsigned col=0; col<Width; ++col) {
      os << ColorToCode(*grid.cpos(row, col)) << ' ';
    }
    os << std::endl;
  }
  return os;
}

template <class T, T EmptyValue, unsigned Width, unsigned Height>
std::istream& operator>>(std::istream& is, Grid<T, EmptyValue, Width, Height>& grid) {
  for (unsigned row=0; row<Height; ++row) {
    for (unsigned col=0; col<Width; ++col) {
      char colorCode;
      is >> colorCode;
      *grid.pos(row, col) = CodeToColor(colorCode);
    }
  }
  return is;
}


template <class T, T EmptyValue, unsigned Width, unsigned Height>
bool Grid<T, EmptyValue, Width, Height>::IsRowClear(unsigned row) const {
  for (auto it = crowStart(row); it != crowEnd(row); ++it)
    if (*it != EmptyValue)
      return false;
  return true;
}

template <class T, T EmptyValue, unsigned Width, unsigned Height>
bool Grid<T, EmptyValue, Width, Height>::IsRowFull(unsigned row) const {
  for (auto it = crowStart(row); it != crowEnd(row); ++it)
    if (*it == EmptyValue)
      return false;
  return true;
}
