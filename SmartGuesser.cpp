#include "SmartGuesser.hpp"
#include <iostream>
using std::string ; 

std::string bullpgia::SmartGuesser::guess(){return "";}
void bullpgia::Guesser::learn(std::string reaply)
{
    bull = std::stoi(reaply.substr(0,reaply.find(',')));
    pgia = std::stoi(reaply.substr(reaply.find(',')+1,reaply.length()-reaply.find(',')-1));
} 