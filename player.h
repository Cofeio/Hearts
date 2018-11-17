
#ifndef Hearts_PLAYER_H
#define Hearts_PLAYER_H




#include "card.h"
#include <string>
#include <iostream>

using namespace std;

class Player{
private:
    string name;
    Card hand[13];
    bool played[13] = {false};
    int points = 0;

public:
    Player(string n){
        name = n;
    }
    
    void deal(Card card[][13], int n){
        for(int i = 0; i < 13; i++){
            hand[i] = card[n][i];
        }

    }
    
    void sortHand(){

        bool swaped = false;
        do {
            swaped = false;
            for(int i = 0; i < (13 - 1); i++) {
                if (hand[i] > hand[i + 1]) {
                    swap(hand[i], hand[i+1]);
                    swaped = true;
                }
            }

        } while(swaped);
    }
    
    void getHand(){

        for(int i = 0; i < 13; i++){
            if(played[i] == false){
                cout << i+1 << ". " << hand[i].getDescription() << endl;
            } else {
                cout << i+1 << ". " << endl;
            }
        }
        cout << endl;
    }

    void addCard(){}

    Card playCard(){
        int pick; 
        cout << "Pick a card to play : ";
        cin >> pick;
        played[pick-1] = true;
        return hand[pick-1];
    }

    Card playCard(Suit lead){
        int pick; 
        bool suitInHand = false;
        bool playedACard = false;
        cout << "Pick a card to play : ";
        
        for(int i = 0; i < 12; i++){
            if(hand[i].getSuit() == lead and played[i] == false){
                suitInHand = true;
            } 
        }
        do{
            if(suitInHand){

                cin >> pick;
                if(hand[pick-1].getSuit() == lead and played[pick-1] == false){
                    played[pick-1] = true;
                    return hand[pick-1];
                    playedACard = true;
                    break;
                } else if(hand[pick-1].getSuit() != lead) {
                    cout << "Hey You need to match the suit!!!!!!";
                    cout << endl << "Pick a card : ";
                } else{
                    cout << "pick a card that you havnt picked";
                }
            }

            if(!suitInHand){
                cin >> pick;
                if(played[pick-1] == false){
                    played[pick-1] = true;
                    return hand[pick-1];
                } else {
                    cout << "Pick a card that hasnt been played : ";
                }
            }

        }while(!playedACard);

    }


    Card compPlayCard(Suit lead){
        bool able = false;
        int pick = 0;
        
        
        for(pick = 0; pick < 13; pick++){
            if(played[pick] == false and hand[pick].getSuit() == lead){
                able = true;
                played[pick] = true;
                return hand[pick];
            } 
        }
        
    
        for(pick = 0; pick < 13; pick++){
            if(played[pick] == false){
                able = true;
                played[pick] = true;
                return hand[pick];
            } 
        }


        played[pick] = true;
        
    }
        Card compPlayCard(){
        bool able = false;
        int pick = 0;
        
        for(pick = 0; pick < 13; pick++){
            if(played[pick] == false){
                able = true;
                played[pick] = true;
                return hand[pick];
            } 
        }


        played[pick] = true;
        
        return hand[pick];
    }

    void setPoints(int p){
        points += p;
    }

    int getPoints(){
        return points;
    }

    string getName(){
        return name;
    }
};

#endif





