#pragma once
#ifndef TETRAMINO_HPP
#define TETRAMINO_HPP

#include <memory>
#include "Grid.hpp"
using namespace std;

enum class TetraminoType {
  I,
  O,
  Z,
  S,
  J,
  L,
  T,
  NumTetraminos
};

class Tetramino {
public:
  virtual ~Tetramino() = 0;
  virtual void Print(ostream&) const = 0;
};
inline Tetramino::~Tetramino() { }

class TetraminoI : public Tetramino, public Grid<Color, Color::Black, 4, 4> {

public:
  TetraminoI() {
    SetRow(1, Color::Cyan);
  }
  ~TetraminoI() { }

  void Print(ostream& os) const {
    os << *dynamic_cast<const Grid<Color, Color::Black, 4, 4>*>(this);
    os << endl;
  }
};

class TetraminoO : public Tetramino, public Grid<Color, Color::Black, 2, 2> {

public:
  TetraminoO() {
    Fill(Color::Yellow);
  }
  ~TetraminoO() { }

  void Print(ostream& os) const {
    os << *dynamic_cast<const Grid<Color, Color::Black, 2, 2>*>(this);
    os << endl;
  }
};

class TetraminoZ : public Tetramino, public Grid<Color, Color::Black, 3, 3> {

public:
  TetraminoZ() {
    Set(0, 0, Color::Red);
    Set(0, 1, Color::Red);
    Set(1, 1, Color::Red);
    Set(1, 2, Color::Red);
  }
  ~TetraminoZ() { }

  void Print(ostream& os) const {
    os << *dynamic_cast<const Grid<Color, Color::Black, 3, 3>*>(this);
    os << endl;
  }
};

class TetraminoS : public Tetramino, public Grid<Color, Color::Black, 3, 3> {

public:
  TetraminoS() {
    Set(0, 1, Color::Green);
    Set(0, 2, Color::Green);
    Set(1, 0, Color::Green);
    Set(1, 1, Color::Green);
  }
  ~TetraminoS() { }

  void Print(ostream& os) const {
    os << *dynamic_cast<const Grid<Color, Color::Black, 3, 3>*>(this);
    os << endl;
  }
};

class TetraminoJ : public Tetramino, public Grid<Color, Color::Black, 3, 3> {

public:
  TetraminoJ() {
    Set(0, 0, Color::Blue);
    Set(1, 0, Color::Blue);
    Set(1, 1, Color::Blue);
    Set(1, 2, Color::Blue);
  }
  ~TetraminoJ() { }

  void Print(ostream& os) const {
    os << *dynamic_cast<const Grid<Color, Color::Black, 3, 3>*>(this);
    os << endl;
  }
};

class TetraminoL : public Tetramino, public Grid<Color, Color::Black, 3, 3> {

public:
  TetraminoL() {
    Set(0, 2, Color::Orange);
    Set(1, 0, Color::Orange);
    Set(1, 1, Color::Orange);
    Set(1, 2, Color::Orange);
  }
  ~TetraminoL() { }

  void Print(ostream& os) const {
    os << *dynamic_cast<const Grid<Color, Color::Black, 3, 3>*>(this);
    os << endl;
  }
};

class TetraminoT : public Tetramino, public Grid<Color, Color::Black, 3, 3> {

public:
  TetraminoT() {
    Set(0, 1, Color::Magenta);
    Set(1, 0, Color::Magenta);
    Set(1, 1, Color::Magenta);
    Set(1, 2, Color::Magenta);
  }
  ~TetraminoT() { }

  void Print(ostream& os) const {
    os << *dynamic_cast<const Grid<Color, Color::Black, 3, 3>*>(this);
    os << endl;
  }
};
const array<shared_ptr<Tetramino>, (unsigned)TetraminoType::NumTetraminos> Tetraminos = {
  make_shared<TetraminoI>(),
  make_shared<TetraminoO>(),
  make_shared<TetraminoZ>(),
  make_shared<TetraminoS>(),
  make_shared<TetraminoJ>(),
  make_shared<TetraminoL>(),
  make_shared<TetraminoT>()
};

inline const auto GetTetramino(TetraminoType tt) {
  return Tetraminos[(unsigned)tt];
}

#endif
