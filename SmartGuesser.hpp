# pragma once 

#include "Guesser.hpp"



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
