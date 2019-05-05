#pragma once

#include "Guesser.hpp"
#include "calculate.hpp"

namespace bullpgia
{

class SmartGuesser : public bullpgia::Guesser
{
private:
  int bullCounter;
  int index = 0;
  int numberOfAttemps = 0 ; 

public:
  
  SmartGuesser() {}
  string guess() override;
  void startNewGame(uint length) override;
};
}; // namespace bullpgia
