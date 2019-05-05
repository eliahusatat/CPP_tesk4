#include "SmartGuesser.hpp"
#include <iostream>
using std::string;

std::string bullpgia::SmartGuesser::guess()
{
    std::cout << bull << " << " << std::endl ;
     /* init the string*/
    if (this->numberOfAttempts == 0)
    {
        for (int i = 0; i < length; i++)
            this->lastGuess += '0';

        this->numberOfAttempts++;
        this->currentGuess = this->lastGuess;
        return this->lastGuess;
    }

    else if (this->numberOfAttempts == 1)
    {
        this->lastBullCounter = this->bull;
        this->numberOfAttempts++;
        this->currentGuess.at(0) = '1';
        return this->currentGuess;
    }
    else
    {

        if (this->lastBullCounter > this->bull)
        {
            this->lastBullCounter = this->bull;
            this->numberOfAttempts++;
            this->currentGuess.at(index)--;
            this->index++;
            return this->currentGuess;
        }
        else if (this->lastBullCounter == this->bull)
        {
            this->numberOfAttempts++;
            this->currentGuess.at(index)++;
            return this->currentGuess;
        }
        else
        {
            this->numberOfAttempts++;
            this->lastBullCounter = this->bull;
            this->index++;
            return this->currentGuess;
        }
    }

    return "1234";
}

void bullpgia::Guesser::learn(std::string reaply)
{
    bull = std::stoi(reaply.substr(0, reaply.find(',')));
    pgia = std::stoi(reaply.substr(reaply.find(',') + 1, reaply.length() - reaply.find(',') - 1));
}