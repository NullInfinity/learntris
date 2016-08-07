#include <iostream>
#include <string>
#include "Game.hpp"

using namespace std;

int main(int, const char*[]) {
  Game game;
  bool running = true;

  while (running) {
    string input;
    cin >> input;

    if (input.length() == 0)
      continue;
    if (cin.eof()) {
      running = false;
      break;
    }

    char response = input[0];

    switch (response) {
      case 'q':
        //game.End();
        running = false;
        break;
      case 'p':
        cout << game.GetGrid();
        break;
      case 'g':
        cin >> game.GetGridWrite();
        break;
      case 'c':
        game.Reset();
        break;
      case 's':
        game.Step();
        break;
      case 't':
        GetTetramino(game.GetActiveTetramino())->Print(cout);
        break;
      case 'I':
        game.SetActiveTetramino(TetraminoType::I);
        break;
      case 'O':
        game.SetActiveTetramino(TetraminoType::O);
        break;
      case 'Z':
        game.SetActiveTetramino(TetraminoType::Z);
        break;
      case 'S':
        game.SetActiveTetramino(TetraminoType::S);
        break;
      case 'J':
        game.SetActiveTetramino(TetraminoType::J);
        break;
      case 'L':
        game.SetActiveTetramino(TetraminoType::L);
        break;
      case 'T':
        game.SetActiveTetramino(TetraminoType::T);
        break;
      case '?':
        if (input.length() == 1)
          continue;
        cout << game.Query(input[1]) << endl;
        break;
      default:
        break;
    }
  }

  return 0;
}
