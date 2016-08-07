#pragma once
#ifndef TETRISGRID_HPP
#define TETRISGRID_HPP

#include "Grid.hpp"

class TetrisGrid : public Grid<Color, Color::Black, 10, 22> {
public:
  // one iteration of the game loop
  unsigned Step();
};

#endif
