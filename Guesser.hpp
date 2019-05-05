#pragma once
#include <iostream>

using std::string;

namespace bullpgia
{
class Guesser
{

protected:
  uint bull;
  uint pgia;

public:
  uint length;

  int numberOfAttempts = 0;
  string lastGuess = "";
  uint lastBullCounter = 0;
  int index = 0;
  string currentGuess = "";
  virtual string guess() = 0;
  virtual void startNewGame(uint length)
  { 
    this->length = length; 
  };
  virtual void learn(string replay);
};
} // namespace bullpgia
