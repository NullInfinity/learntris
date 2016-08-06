#pragma once
#ifndef GRID_HPP
#define GRID_HPP

#include <array>
#include <iostream>
#include "Color.hpp"

class Grid {
public:
  static constexpr unsigned Width = 10, Height = 22;

private:
  std::array<Color, Width * Height> grid;
  auto crowStart(unsigned row) const {
    return grid.cbegin() + row * Grid::Width;
  }
  auto crowEnd(unsigned row) const {
    return crowStart(row) + Width;
  }
  auto rowStart(unsigned row) {
    return grid.begin() + row * Grid::Width;
  }
  auto rowEnd(unsigned row) {
    return rowStart(row) + Width;
  }

  friend std::ostream& operator<<(std::ostream&, const Grid&);
  friend std::istream& operator>>(std::istream&, Grid&);
public:
  Grid() {
    Clear();
  }

  bool IsRowClear(unsigned row) const;
  bool IsRowFull(unsigned row) const;

  void SetRow(unsigned row, Color color) {
    std::fill(rowStart(row), rowEnd(row), color);
  }
  void ClearRow(unsigned row) {
    SetRow(row, Color::Black);
  }
  void Clear() {
    grid.fill(Color::Black);
  }

  // one iteration of the game loop
  unsigned Step();
};

std::ostream& operator<<(std::ostream& os, const Grid& grid);
std::istream& operator>>(std::istream& is, Grid& grid);

#endif
