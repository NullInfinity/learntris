#include "TetrisGrid.hpp"

unsigned TetrisGrid::Step() {
  unsigned rowsCleared = 0;
  for (unsigned row=0; row<GetHeight(); ++row) {
    if (IsRowFull(row)) {
      ClearRow(row);
      ++rowsCleared;
    }
  }
  return rowsCleared;
}
