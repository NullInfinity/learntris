#include "Grid.hpp"

std::ostream& operator<<(std::ostream& os, const Grid& grid) {
  for (unsigned row=0; row<Grid::Height; ++row) {
    for (unsigned col=0; col<Grid::Width; ++col) {
      os << ColorToCode(grid.grid[row * Grid::Width + col]) << ' ';
    }
    os << std::endl;
  }
  return os;
}

std::istream& operator>>(std::istream& is, Grid& grid) {
  for (unsigned row=0; row<Grid::Height; ++row) {
    for (unsigned col=0; col<Grid::Width; ++col) {
      char colorCode;
      is >> colorCode;
      grid.grid[row * Grid::Width + col] = CodeToColor(colorCode);
    }
  }
  return is;
}


bool Grid::IsRowClear(unsigned row) const {
  for (auto it = crowStart(row); it != crowEnd(row); ++it)
    if (*it != Color::Black)
      return false;
  return true;
}

bool Grid::IsRowFull(unsigned row) const {
  for (auto it = crowStart(row); it != crowEnd(row); ++it)
    if (*it == Color::Black)
      return false;
  return true;
}

unsigned Grid::Step() {
  unsigned rowsCleared = 0;
  for (unsigned row=0; row<Height; ++row) {
    if (IsRowFull(row)) {
      ClearRow(row);
      ++rowsCleared;
    }
  }
  return rowsCleared;
}
