//
// Created by Evan Chang on 2019-04-09.
//

// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin]
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include <ctime>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


//helper that deals a player a hand
void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}

int main( )
{
	 //opens file to write results to
    ofstream file;
    file.open("gofish_results.txt");
    int numCards = 7;

    Player p1("Evan");
    Player p2("Brock");

    Deck d;
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    file << p1.getName() <<" has : " << p1.showHand() << endl;
    file << p2.getName() <<" has : " << p2.showHand() << endl;



    Card c1;
    Card c2;

    Player current = p1;
    Player next = p1;
	
	 //randomize starting player
    srand(time(0));
    if (rand() % 2){
        next = p2;
    }
    else{
        current = p2;
    }
	 //Keep playing until cards are all used
    while((current.getBookSize() + next.getBookSize() <26)){

        file << endl << "Cards remaining in deck: " << d.size() << endl;
        file << current.getName() << "\'s hand: " << current.showHand() << endl << endl;
     
		  //If player is out of cards, try to draw one
        if(current.getHandSize() == 0){
            if (d.size() > 0) {
                current.addCard(d.dealCard());
            }
            Player temp = next;
            next = current;
            current = temp;

        }
        else {
		  		//Check if the player has any new books
            if (current.checkHandForBook(c1, c2)) {
                current.bookCards(c1, c2);
                current.removeCardFromHand(c1);
                current.removeCardFromHand(c2);
            }

			//request a card from opponent
            if(current.getHandSize() > 0) {
                Card request = current.chooseCardFromHand();
                file << current.getName() << " asks for " << request.rankString(request.getRank()) << endl;

					 //If opponent has requested card, book them and write to file
                if (next.rankInHand(request)) {

                    Card booked = next.removeCardFromHand(request);
                    current.bookCards(request, booked);
                    current.removeCardFromHand(request);


                    file << next.getName() << " gave over the " << booked.toString() << endl;
                    file << current.getName() << " books the " + request.rankString(request.getRank()) << "\'s" << endl;
                } 
					 //otherwise, just write to file
					 else {

                    file << "Go Fish!" << endl;
                    if (d.size() > 0) {
                        Card draw = d.dealCard();
                        current.addCard(draw);
                        file << current.getName() << " draws the " << draw.toString() << endl;
                    }
						
						  //switch turns
                    Player temp = next;
                    next = current;
                    current = temp;
                }
            }
        }
    }

	 file << endl << current.getName() << "\'s books: " << current.showBooks() << endl;	
	 file << endl << next.getName() << "\'s books: " << current.showBooks() << endl; 

    if(current.getBookSize() == next.getBookSize()){
        file << "It's a tie!!";
        file.close();
        return EXIT_SUCCESS;
    }

    Player winner = current;
    if(next.getBookSize() > current.getBookSize()){
        winner = next;
    }
    file << winner.getName() << " wins!!!" << endl;
    file.close();
    return EXIT_SUCCESS;
}
