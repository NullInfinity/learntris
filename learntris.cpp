#include <iostream>
#include <string>
#include "Grid.hpp"

float Score = 0.0f;
unsigned LinesCleared = 0;

void Query(char c) {
  switch (c) {
    case 's':
      std::cout << Score;
      break;
    case 'n':
      std::cout << LinesCleared;
      break;
    default:
      return;
  }
  std::cout << std::endl;
}

void Step(Grid& grid) {
  unsigned newLinesCleared = grid.Step();
  LinesCleared += newLinesCleared;
  Score += 100 * newLinesCleared;
}

int main(int, const char*[]) {
  bool running = true;
  Grid grid;

  std::string input;
  while (running && getline(std::cin, input)) {
    if (input.length() == 0)
      continue;

    char response = input[0];

    switch (response) {
      case 'q':
        running = false;
        break;
      case 'p':
        std::cout << grid;
        break;
      case 'g':
        std::cin >> grid;
        break;
      case 'c':
        grid.Clear();
        break;
      case 's':
        Step(grid);
        break;
      case '?':
        if (input.length() == 1)
          continue;
        Query(input[1]);
        break;
      default:
        break;
    }
  }

  return 0;
}
