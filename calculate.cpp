#include "calculate.hpp"


/** @return a String that represent the answer bull and pgia **/

string bullpgia::calculateBullAndPgia(string choise, string guess)
{

   if(guess.length() == 0  || choise.length() == 0  || guess.length() != choise.length()) throw std::invalid_argument("invalid input");
   int countBull = 0, countPgia = 0;

   bool Bull[choise.length()];
   bool Pgia[choise.length()];

   /* BULLS  */
   for (int i = 0; i < choise.length(); i++)
   {
      if(choise[i]  > '9' || choise[i] < '0' || guess[i] > '9') throw std::invalid_argument("invalid input");
      Bull[i] = true;
      Pgia[i] = true;
      if (choise.at(i) == guess.at(i))
      {
         Bull[i] = false;
         countBull++;
      }
   }

   for (int i = 0; i < choise.length(); i++)
   {
      if (Bull[i] != false)
         for (int j = 0; j < guess.length(); j++)
         {
            if (!(Bull[j] == false || Pgia[j] == false))
            {
               if (choise[i] == guess[j])
               {
                  Pgia[j] = false;
                  countPgia++;
               }
            }
         }
   }


   
   return std::to_string(countBull) + "," + std::to_string(countPgia); 
}
