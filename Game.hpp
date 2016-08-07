#pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include <string>
#include <sstream>
#include "TetrisGrid.hpp"
#include "Tetramino.hpp"

class Game {
  float Score = 0.0f;
  unsigned LinesCleared = 0;

  bool running = true;
  TetrisGrid grid;
  TetraminoType activeTetramino;

public:
  void Reset();
  void Step();

  const TetrisGrid& GetGrid() const { return grid; }
  TetrisGrid& GetGridWrite() { return grid; }

  void SetActiveTetramino(TetraminoType tt) {
    if (tt != TetraminoType::NumTetraminos)
      activeTetramino = tt;
  }
  TetraminoType GetActiveTetramino() const {
    return activeTetramino;
  }

  std::string Query(char id) const;
};

#endif
