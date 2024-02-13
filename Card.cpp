//
// Created by tedmw on 2/12/2024.
//

#include "Card.h"

// Constructor
Card::Card(int val, Suit st) : value(val), suit(st) {}

// Setter methods
void Card::setValue(int val) { value = val; }
void Card::setSuit(Suit st) { suit = st; }

// Getter methods
int Card::getValue() const { return value; }
Suit Card::getSuit() const { return suit; }

// Overloaded << operator for printing card
std::ostream& operator<<(std::ostream& os, const Card& card) {
    std::string suitStr;
    switch (card.getSuit()) {
        case Suit::CLUB:
            suitStr = "Club";
            break;
        case Suit::DIAMOND:
            suitStr = "Diamond";
            break;
        case Suit::HEART:
            suitStr = "Heart";
            break;
        case Suit::SPADE:
            suitStr = "Spade";
            break;
    }
    os << card.getValue() << " of " << suitStr;
    return os;
}

