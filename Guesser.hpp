#pragma once
#include <iostream>

using std::string;

namespace bullpgia
{
class Guesser
{

private:
  string guessOption;
  uint bull;
  uint pgia;

public:
  uint length;
  virtual string guess() = 0;
  virtual void startNewGame(uint length) { this->length = length; };
  virtual void learn(string replay);
};
} // namespace bullpgia
