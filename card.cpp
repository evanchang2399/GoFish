//
// Created by Evan Chang on 2019-04-09.
//

#include "card.h"
#include <string>

using namespace std;

//default constructor that makes an Ace of Spades
Card::Card(){

    myRank = 1;
    mySuit = Card::spades;
}

//constructor that makes a certain card
Card::Card(int rank, Suit suit) {
    myRank = rank;
    mySuit = suit;
}

//check if two cards have the same suit
bool Card::sameSuitAs(const Card &c) const {

    return (this->mySuit == c.mySuit);
}

//return the rank of the card
int Card::getRank() const {
    return myRank;
}

//check if two cards have the same rank
bool Card::operator==(const Card &rhs) const {

    return (sameSuitAs(rhs) && myRank == rhs.getRank());
}

//check if two cards have different ranks
bool Card::operator!=(const Card &rhs) const {
    return !(sameSuitAs(rhs) && myRank == rhs.getRank());
}

//return a string with the letter for the suit
string Card::suitString(Card::Suit s) const {
    if(s == spades){
       return "s";
    }

    else if(s == clubs){
        return "c";
    }

    else if(s == hearts) {
        return "h";
    }

    else{
        return "d";
    }
}

//return the rank as a string
string Card::rankString(int r) const {

    if(r == 2){
        return "2";
    }
	 else if(r == 3){
		  return "3";
	 }
	 else if(r == 4){
		  return "4";
	 }
	 else if(r == 5){
		  return "5";
	 }
	 else if(r == 6){
		  return "6";
	 }
	 else if(r == 7){
		  return "7";
	 }
	 else if(r == 8){
		  return "8";
	 }
	 else if(r == 9){
		 return "9";
	 }
	 else if(r == 10){
		  return "10";
	 }
    else if(r == 1){
        return "A";
    }
    else if(r == 11){
        return "J";
    }
    else if(r == 12){
        return "Q";
    }
    else {
        return "K";
    }
}

//returns the cards information at a string
string Card::toString() const {

    return (rankString(myRank) + suitString(mySuit));
}

//prints out a card 
ostream& operator << (ostream& out, const Card& c){

    out << c.toString();
    return out;
}
