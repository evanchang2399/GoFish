//
// Created by Evan Chang on 2019-04-09.
//

#include "card.h"
#include "deck.h"
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

//default constructor 
Deck::Deck(){

    myIndex = 0;

	 //Create every card in the deck
    Card toAdd;
    for(int i = 1; i<= 13; i++){
        toAdd = Card(i, Card::spades);
        myCards[i-1] = toAdd;
    }

    for(int i = 1; i<=13; i++){
        toAdd = Card(i, Card::clubs);
        myCards[i+12] = toAdd;
    }

    for(int i = 1; i<=13; i++){
        toAdd = Card(i, Card::hearts);
        myCards[i+25] = toAdd;
    }

    for(int i = 1; i<=13; i++){
        toAdd = Card(i, Card::diamonds);
        myCards[i+38] = toAdd;
    }

}

//Print out all cards in the deck
string Deck::toString(){
    string toReturn = "";

    for(int i = 0; i < this->size(); i++){
        toReturn += (myCards[i].toString() + "  ");
    }
    return toReturn;
}

//shuffle the deck
void Deck::shuffle() {

    srand(time(0));
	 //randomly insert elements elsewhere in the deck 
    for(int i = 0; i < this->size(); i++){
        int toSwap = rand() % this->size();
        Card temp = myCards[toSwap];
        myCards[toSwap] = myCards[i];
        myCards[i] = temp;
    }
}

//deal the top card
Card Deck::dealCard() {

    myIndex++;
    return myCards[myIndex-1];
}

//return size of deck
int Deck::size() const {
    return 52-myIndex;
}
