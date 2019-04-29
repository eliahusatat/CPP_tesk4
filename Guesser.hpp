#pragma once
#include <iostream>

using std::string;

namespace bullpgia
{
class Guesser
{

  string guessOption;

public:
  uint length;
  virtual string guess() = 0;
  virtual void startNewGame(uint length){};
  virtual void learn(string replay){};
};
} // namespace bullpgia
