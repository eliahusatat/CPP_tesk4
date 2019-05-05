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
  string Guess ; 




  virtual string guess() = 0;
  virtual void startNewGame(uint length)
  { 
    this->length = length; 
  }
  virtual void learn(string replay)
  {
    bull = std::stoi(replay.substr(0, replay.find(',')));
    pgia = std::stoi(replay.substr(replay.find(',') + 1, replay.length() - replay.find(',') - 1));
  }
};
} // namespace bullpgia
