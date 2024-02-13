//
// Created by tedmw on 2/12/2024.
//

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

// Enum for card suits
enum class Suit { CLUB, DIAMOND, HEART, SPADE };

// Class representing a single card
class Card {
private:
    int value;
    Suit suit;
public:
    // Constructor
    Card(int val, Suit st);

    // Setter methods
    void setValue(int val);
    void setSuit(Suit st);

    // Getter methods
    int getValue() const;
    Suit getSuit() const;

    // Overloaded << operator for printing card
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};

#endif
