#pragma once
#include <iostream>

using std::string;

namespace bullpgia
{
class Guesser
{

private:
  string guessOption;
 // uint bull;
  //uint pgia;

public:
uint length;
   
  uint bull;
  uint pgia;
  int numberOfAttempts=0;
  string back="";
  uint backbull=0;
  int count=0;
  string guesss="";
  virtual string guess() = 0;
  virtual void startNewGame(uint length) { this->length = length; };
  virtual void learn(string replay);
  
};
} // namespace bullpgia
