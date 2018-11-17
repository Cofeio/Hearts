#include <iostream>
#include <iomanip>
#include "player.h"
#include "deck.h"
#include "card.h"
using namespace std;

int main(){
	
    int choice;
    int turn = 1;
    bool game = true;
    Suit lead;

    Deck deck;
    Card cards[4][13];

    Card yourCard;
    Card ishmaleCard;
    Card ahabCard;
    Card mobyDickCard;

    deck.createDeck();
    deck.shuffle();
    deck.convert();
    deck.getDeck(cards);

    Player you("You");
    Player Ishmale("Ishmale");
    Player Ahab("Ahab");
    Player MobyDick("MobyDick");

    you.deal(cards, 0);
    Ishmale.deal(cards, 1);
    Ahab.deal(cards, 2);
    MobyDick.deal(cards, 3);

    you.sortHand();
    Ishmale.sortHand();
    Ahab.sortHand();
    MobyDick.sortHand();

    int first = deck.get2();

    do{

        cout << endl << "Player" << setw(16) << "Points" << endl;
        cout << "------" << setw(16) << "------" << endl;
        cout << you.getName() << setw(16) << right << you.getPoints() << endl;
        cout << Ishmale.getName() << setw(12) << right << Ishmale.getPoints() << endl;
        cout << Ahab.getName() << setw(15) << right << Ahab.getPoints() << endl;
        cout << MobyDick.getName() << setw(11) << right << MobyDick.getPoints() << endl << endl << endl;

        cout << "Your Hand" << endl;
        cout << "---------" << endl;

        
        you.getHand();

            
        switch(first){
            case 1:

                cout << "You go first" << endl;

                yourCard = you.playCard();
                lead = yourCard.getSuit();
                cout << "You played " << yourCard.getDescription() << endl;
                ishmaleCard = Ishmale.compPlayCard(); cout << "Ishmale plays " << ishmaleCard.getDescription() << endl;
                mobyDickCard = MobyDick.compPlayCard(); cout << "MobyDick plays " << mobyDickCard.getDescription() << endl;
                ahabCard = Ahab.compPlayCard(); cout << "Ahab plays " << ahabCard.getDescription() << endl;
                break;
            case 2:

                ishmaleCard = Ishmale.compPlayCard(); cout << "Ishmale plays " << ishmaleCard.getDescription() << endl;
                lead = ishmaleCard.getSuit();
                mobyDickCard = MobyDick.compPlayCard(lead); cout << "MobyDick plays " << mobyDickCard.getDescription() << endl;
                ahabCard = Ahab.compPlayCard(lead); cout << "Ahab plays " << ahabCard.getDescription() << endl;
                yourCard = you.playCard(lead);
                cout << "You played " << yourCard.getDescription() << endl;
                break;
            case 3:

                mobyDickCard = MobyDick.compPlayCard(); cout << "MobyDick plays " << mobyDickCard.getDescription() << endl;
                lead = mobyDickCard.getSuit();
                ahabCard = Ahab.compPlayCard(lead); cout << "Ahab plays " << ahabCard.getDescription() << endl;
                yourCard = you.playCard(lead);
                cout << "You played " << yourCard.getDescription() << endl;
                ishmaleCard = Ishmale.compPlayCard(lead); cout << "Ishmale plays " << ishmaleCard.getDescription() << endl;
                break;
            default:


                ahabCard = Ahab.compPlayCard(); cout << "Ahab plays " << ahabCard.getDescription() << endl;
                lead = ahabCard.getSuit();
                yourCard = you.playCard(lead);
                cout << "You played " << yourCard.getDescription() << endl;
                ishmaleCard = Ishmale.compPlayCard(lead); cout << "Ishmale plays " << ishmaleCard.getDescription() << endl;
                mobyDickCard = MobyDick.compPlayCard(lead); cout << "MobyDick plays " << mobyDickCard.getDescription() << endl;
                break;
        }

        int points = 0;

        if(yourCard.getSuit() == heart){points += 1;}
        if(ishmaleCard.getSuit() == heart){points += 1;}
        if(mobyDickCard.getSuit() == heart){points += 1;}
        if(ahabCard.getSuit() == heart){points += 1;}
        if(yourCard.getSuit() == spade and yourCard.getNumber() == 12){
            points += 13;
        }
        if(ishmaleCard.getSuit() == spade and ishmaleCard.getNumber() == 12){
            points += 13;
        }
        if(mobyDickCard.getSuit() == spade and mobyDickCard.getNumber() == 12){
            points += 13;
        }
        if(ahabCard.getSuit() == spade and ahabCard.getNumber() == 12){
            points += 13;
        }
        
        //- is used as > is already used which has suit as a judgemnt that we dont want

        if((yourCard - ishmaleCard and yourCard - ahabCard and yourCard - mobyDickCard) and (yourCard.getSuit() == lead)){
        
            you.setPoints(points);
            
            first = 1;
        } else if((ishmaleCard - mobyDickCard and ishmaleCard - ahabCard) and (ishmaleCard.getSuit() == lead)) {

            Ishmale.setPoints(points);
            
            first = 2;
        } else if(mobyDickCard - ahabCard and mobyDickCard.getSuit() == lead){
            
            MobyDick.setPoints(points);
            
            first = 3;
        } else {
            
            Ahab.setPoints(points);
            
            first = 4;
        }

        if(turn == 13){
            game = false;
        }

        turn += 1;

        cout << string( 100, '\n' );



    } while(game == true);

    if(you.getPoints() == 26){
        you.setPoints(-26);
        Ishmale.setPoints(26);
        Ahab.setPoints(26);
        MobyDick.setPoints(26);
    }
    if(Ishmale.getPoints() == 26){
        you.setPoints(26);
        Ishmale.setPoints(-26);
        Ahab.setPoints(26);
        MobyDick.setPoints(26);
    }
    if(MobyDick.getPoints() == 26){
        you.setPoints(26);
        Ishmale.setPoints(26);
        Ahab.setPoints(26);
        MobyDick.setPoints(-26);
    }
    if(Ahab.getPoints() == 26){
        you.setPoints(26);
        Ishmale.setPoints(26);
        Ahab.setPoints(-26);
        MobyDick.setPoints(26);
    }


    cout << endl << "Player" << setw(18) << "Final Points" << endl;
    cout << "------" << setw(18) << "------------" << endl;
    cout << you.getName() << setw(16) << right << you.getPoints() << endl;
    cout << Ishmale.getName() << setw(12) << right << Ishmale.getPoints() << endl;
    cout << Ahab.getName() << setw(15) << right << Ahab.getPoints() << endl;
    cout << MobyDick.getName() << setw(11) << right << MobyDick.getPoints() << endl << endl << endl;

}