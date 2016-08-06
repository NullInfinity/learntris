#pragma once
#ifndef COLOR_HPP
#define COLOR_HPP

#include <algorithm>

enum class Color {
  // do not change numbering -- used as array indices
  Black = 0,
  Blue,
  Cyan,
  Green,
  Magenta,
  Orange,
  Red,
  Yellow,
  NumColors
};

constexpr std::array<char, (unsigned)Color::NumColors> ColorCodes = {
  '.',
  'b',
  'c',
  'g',
  'm',
  'o',
  'r',
  'y'
};

inline char ColorToCode(Color c) {
  return ColorCodes[(unsigned)c];
}

inline Color CodeToColor(char c) {
  auto it = std::find(ColorCodes.begin(), ColorCodes.end(), c);
  unsigned i = it - ColorCodes.begin();
  return Color((unsigned)i);
}

#endif
