#include "SmartGuesser.hpp"
#include <iostream>
using std::string ; 

std::string bullpgia::SmartGuesser::guess(){
    if (this->length==1)this->back="0";
    if (this->length==2)this->back="00";
    if (this->length==3)this->back="000";
    if (this->length==4)this->back="0000";
    if (this->length==5)this->back="00000";
    if (this->length==6)this->back="000000";
    if (this->length==7)this->back="0000000";
    
    
    if (this->numberOfAttempts==0){
        
        this->numberOfAttempts++;
       this-> guesss=this->back;
        return this->back;
    }
    else if (this->numberOfAttempts==1){
       this-> backbull=this->bull;
        this->numberOfAttempts++;
       this-> guesss[0]=this->guesss[0]+1;
        return this->guesss;
    }
    else{
        if (this->backbull>this->bull){
           this-> numberOfAttempts++;
        this-> guesss[count]=this->guesss[count]-1;
         
         this->count++;
        this-> guesss[count]++;
         
         return this-> guesss;
        }
        else if (this->backbull==this->bull){
            this->numberOfAttempts++;
            this->back=this->guesss;
            this->guesss[count]++;
            return this->guesss;
            
        }
        else
        {
            this->numberOfAttempts++;
            this->backbull=this->bull;
           
           this-> back=this->guesss;
            this->count++;
           this-> guesss[count]++;
            return this->guesss;
        }
        

    }
    
    
    
    
    }
void bullpgia::Guesser::learn(std::string reaply)
{
    bull = std::stoi(reaply.substr(0,reaply.find(',')));
    pgia = std::stoi(reaply.substr(reaply.find(',')+1,reaply.length()-reaply.find(',')-1));
} 