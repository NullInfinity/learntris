#pragma once
#ifndef GRID_HPP
#define GRID_HPP

#include <array>
#include <iostream>
#include "Color.hpp"

template <class T, T EmptyValue, unsigned Width, unsigned Height> class Grid;
template <class T, T EmptyValue, unsigned Width, unsigned Height>
std::ostream& operator<<(std::ostream& os, const Grid<T, EmptyValue, Width, Height>& grid);
template <class T, T EmptyValue, unsigned Width, unsigned Height>
std::istream& operator>>(std::istream& is, Grid<T, EmptyValue, Width, Height>& grid);

template <class T, T EmptyValue, unsigned Width, unsigned Height> class Grid {
  typedef std::array<T, Width*Height> GridArray;
  typedef typename GridArray::const_iterator const_iterator;
  typedef typename GridArray::iterator iterator;

  GridArray grid;
  unsigned rotation; // defined mod 4

  static auto sanitizeRow(unsigned row) {
    return (row > Height) ? (Height - 1) : row;
  }
  static auto sanitizeCol(unsigned col) {
    return (col > Width) ? Width : col;
  }
  static void sanitizePos(unsigned& row, unsigned& col) {
    row = sanitizeRow(row);
    col = sanitizeCol(col);
  }

  auto rowStart(unsigned row) {
    return const_cast<iterator>(crowStart(row));
    //return const_cast<iterator>grid.begin() + sanitizeRow(row) * Width;
  }
  auto rowEnd(unsigned row) {
    return const_cast<iterator>(crowEnd(row));
    //return rowStart(row) + Width;
  }
  auto pos(unsigned row, unsigned col) {
    return const_cast<iterator>(cpos(row, col));
    //return rowStart(row) + sanitizeCol(col);
  }
  auto crowStart(unsigned row) const {
    return grid.cbegin() + sanitizeRow(row) * Width;
  }
  auto crowEnd(unsigned row) const {
    return crowStart(row) + Width;
  }
  auto cpos(unsigned row, unsigned col) const {
    return crowStart(row) + sanitizeCol(col);
  }
  //TODO colStart, colEnd -- iterators which jump multiple places per iteration needed

  friend std::ostream& operator<<<>(std::ostream&, const Grid<T, EmptyValue, Width, Height>&);
  friend std::istream& operator>><>(std::istream&, Grid<T, EmptyValue, Width, Height>&);

public:
  Grid() {
    Clear();
  }
  virtual ~Grid() = default;

  void Fill(const T& t) {
    grid.fill(t);
  }
  void Clear() {
    Fill(EmptyValue);
  }

  void SetRow(unsigned row, const T& t) {
    std::fill(rowStart(row), rowEnd(row), t);
  }
  void ClearRow(unsigned row) {
    SetRow(row, EmptyValue);
  }

  void SetCol(unsigned col, const T& t);
  void ClearColumn(unsigned col) {
    SetColumn(col, EmptyValue);
  }

  void Set(unsigned row, unsigned col, const T& t) {
    *pos(row, col) = t;
  }
  T Get(unsigned row, unsigned col) {
    return *cpos(row, col);
  }

  bool IsRowClear(unsigned row) const;
  bool IsRowFull(unsigned row) const;

  constexpr auto GetWidth() const { return Width; }
  constexpr auto GetHeight() const { return Height; }
  constexpr auto GetEmptyValue() const { return EmptyValue; }
};

#include "Grid.inl"

#endif
