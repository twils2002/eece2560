//
// Created by tedmw on 2/12/2024.
//

#ifndef DECK_H
#define DECK_H

#include "Card.h"

// Node structure for linked list
struct Node {
    Card card;
    Node* next;
    Node(const Card& c);
};

// Class representing a deck of cards
class Deck {
private:
    Node* head; // Pointer to the first card in the deck

public:
    // Constructor
    Deck();

    // Destructor to deallocate memory
    ~Deck();

    // Function to add a card to the deck
    void addCard(const Card& card);

    // Function to shuffle the deck
    void shuffle();

    // Function to count cards in the deck
    int countCards() const;

    // Overloaded << operator for printing the deck
    friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
};

#endif
