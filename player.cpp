//
// Created by Evan Chang on 2019-04-09.
//

#include "card.h"
#include "deck.h"
#include "player.h"
#include <vector>
#include <ctime>
#include <string>
#include <cstdlib>

using namespace std;

//default constructor
Player::Player() {
    myName = "A man has no name.";
}

//add a card to the players hand
void Player::addCard(Card c) {
    myHand.push_back(c);
}

//add two cards to the players set of pairs
void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//check if a certain card is in the hand 
bool Player::cardInHand(Card c) const {

    for(int i=0; i<myHand.size(); i++){
        if(myHand[i].operator==(c)){
            return true;
        }
    }
    return false;
}

//remove an instance of a card from the hand
Card Player::removeCardFromHand(Card c) {
    Card toReturn;
    for(int i=0; i<myHand.size(); i++){
        if(myHand[i].getRank()==(c.getRank())){
            toReturn = myHand[i];
            myHand.erase(myHand.begin() + i);
            return toReturn;
        }
    }
    return toReturn;
}

//checks if a certain rank is in the hand
bool Player::rankInHand(Card c) const {

    int rank = c.getRank();
    for(int i = 0; i<myHand.size(); i++){
        if(myHand[i].getRank() == rank){
            return true;
        }
    }
    return false;
}

//pick a card to request from the opposite
Card Player::chooseCardFromHand() const {

    srand(time(0));
    int random = rand() % myHand.size();
    return myHand[random];

}

//check if there is a pair in the current hand
bool Player::checkHandForBook(Card &c1, Card &c2) {

    int ranks[13];
    int book = -1;

	 //array that holds occurances of each rank
    for(int i=0; i<13; i++){
        ranks[i] = 0;
    }

    //Add an occurence for every time a rank comes up
    for(int i=0; i<myHand.size(); i++){
        ranks[myHand[i].getRank()-1]++;
    }

    //Find which rank is a book
    for(int i=0; i<13; i++){
        if(ranks[i] >= 2){
            book = i+1;
            i = 13;
        }
    }

    bool foundOne = false;
    for(int i = 0; i<myHand.size(); i++){
		  //remove first instance of rank
        if(myHand[i].getRank() == book && !foundOne){
            c1= myHand[i];
            foundOne = true;
        }
		  //remove second instance of rank
        else if(myHand[i].getRank() == book && foundOne){
            c2 = myHand[i];
        }
    }

    return foundOne;
}

//returns number of card pairs
int Player::getBookSize() const {
    return myBook.size()/2;
}

//returns the hand size
int Player::getHandSize() const {
    return myHand.size();
}

//returns a string that displays all pairs
string Player::showBooks() const {

    string toReturn = "";

    for(int i =0; i<myBook.size();i++){
        if(i%2 == 0) {
            toReturn += (myBook[i].toString() + "/");
        }else{
            toReturn += (myBook[i].toString() + ", ");
        }
    }
    return toReturn;
}

//returns a string that displays all cards in hand
string Player::showHand() const {

    string toReturn = "";
    for(int i =0; i<myHand.size();i++){
        toReturn += (myHand[i].toString() + "   ");
    }

    return toReturn;
}
