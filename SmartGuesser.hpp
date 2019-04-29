# pragma once 

#include "Guesser.hpp"
#include "calculate.hpp"



namespace bullpgia
{


class SmartGuesser: public bullpgia::Guesser
  {
    string Guess ; 
    public: 
    SmartGuesser(){}
    string guess() override ;

  };
};
