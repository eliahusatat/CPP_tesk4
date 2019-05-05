#include "SmartGuesser.hpp"
#include <iostream>
using std::string;

std::string bullpgia::SmartGuesser::guess()
{
    if (numberOfAttemps == 0)
    {
        numberOfAttemps++;
        return Guess;
    }
    else if (numberOfAttemps == 1)
    {
        bullCounter = bull;
        numberOfAttemps++;
        Guess.at(index)++;
        return Guess;
    }
    else
    {
        if (bull > bullCounter)
        {
            bullCounter = bull;
            numberOfAttemps++;
            index++;
            Guess.at(index)++;
            return Guess;
        }
        else if (bull < bullCounter)
        {
            numberOfAttemps++;
            Guess.at(index)--;
            index++;
            Guess.at(index)++;
            return Guess;
        }
        else // ==
        {
            numberOfAttemps++;
            Guess.at(index)++;
            return Guess;
        }
    }
}


void bullpgia::SmartGuesser::startNewGame(uint length)
{
    index = 0;
    bullCounter = 0;
    numberOfAttemps = 0;
    Guess = "";
    for (int i = 0; i < length; i++)
    {
        Guess += '0';
    }
}