#ifndef Hearts_Card_H
#define Hearts_Card_H


enum Suit{ spade, heart, diamond, club };

class Card {
private:
    int number;
    Suit suit;
    std::string description;

public:
    void setSuit(Suit s){
        suit = s;
    }
    
    Suit getSuit(){
        return suit;
    }
    
    int getNumber(){
        return number;
    }

    void setNumber(int n){
        number = n;
    }

    void setDescription(){
        std::string stringValue = std::to_string(number);
        switch (number)
        {
            case 1: stringValue = "Ace"; break;
            case 11: stringValue = "Jack"; break;
            case 12: stringValue = "Queen"; break;
            case 13: stringValue = "King"; break;
        }
        switch (suit) {
            case spade:
                description = "Spade " + stringValue;
                break;
            case heart:
                description = "Heart " + stringValue;
                break;
            case diamond:
                description = "Diamond " + stringValue;
                break;
            case club:
                description = "Club " + stringValue;
                break;
        }
    }
    std::string getDescription(){
        return description;
    }
    bool operator>(const Card& card) {
        if (suit > card.suit) {
            return true;
        }
        if (suit == card.suit){
            if (number < card.number){
                return true;
            }
        }
        return false;
    }
    
    bool operator-(const Card& card) {
        if (number > card.number) {
            return true;
        } else{
            return false;
        }
    }
};



#endif