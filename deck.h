#ifndef Hearts_DECK_H
#define Hearts_DECK_H
using namespace std;

#include <iostream>
#include <string>

#include "card.h"


class Deck {
private:
    Card deckTwoD[4][13];
    Card deckOneD[52];
    
public:
    void createDeck() {

        Suit s;

        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                deckTwoD[j][i].setNumber(i + 1);
                s = (Suit) + j;
                deckTwoD[j][i].setSuit(s);
                deckTwoD[j][i].setDescription();
            }
        }

        int k = 0;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
                deckOneD[k] = deckTwoD[i][j];
                k++;
            }
        }
    }


    Card shuffle() {
        unsigned int num, random = 0;
        unsigned seed;
        seed = time(0);
        srand(seed);

        for (int i = 0; i < 52; i++) {

            Card deckTemp[52];
            random = rand();
            num = random % 52;

            deckTemp[i] = deckOneD[i];
            deckOneD[i] = deckOneD[num];
            deckOneD[num] = deckTemp[i];

        }
        return deckOneD[51];
    }

    Card convert(){
        int k = 0;

        for(int i = 0; i < 13; i++){
            for(int j = 0; j<4; j++){
                deckTwoD[j][i] = deckOneD[k];
                k++;
            }
        }
        return deckTwoD[4][12];
    }
    
    void getDeck(Card cards[4][13]) {
        for (int i = 0; i < 13; i++) {
            //cout << endl;
            for (int j = 0; j < 4; j++) {

                cards[j][i] = deckTwoD[j][i];
            }
        }
    }
    int get2(){

        int position2;
        int positiona;
        for(int i = 0; i < 52; i++){
            if(deckOneD[i].getNumber() == 2 && deckOneD[i].getSuit() == club){
                position2 = i%4+1;
                return position2;
            }
            if(deckOneD[i].getNumber() == 1 && deckOneD[i].getSuit() == club){
                positiona = i%4+1;
                return positiona;
            }
        }
    }
        

};


#endif //Hearts_DECK_H