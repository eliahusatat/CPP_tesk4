#pragma once

#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia
{

class SmartGuesser : public bullpgia::Guesser
{
  string Guess;

public:
  SmartGuesser() {}
  string guess() override;
  void init()
  {
    int numberOfAttempts = 0;
    string lastGuess = "";
    uint lastBullCounter = 0;
    int index = 0;
    string currentGuess = "";
    this->bull = 0;
  }
};
}; // namespace bullpgia
