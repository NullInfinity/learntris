#include "Game.hpp"

std::string Game::Query(char id) const {
  std::ostringstream oss;
  switch (id) {
    case 's':
      oss << Score;
      break;
    case 'n':
      oss << LinesCleared;
      break;
    default:
      break;
  }
  return oss.str();
}

void Game::Step() {
  unsigned newLinesCleared = grid.Step();
  LinesCleared += newLinesCleared;
  Score += 100 * newLinesCleared;
}

void Game::Reset() {
  grid.Clear();
}
