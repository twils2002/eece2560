//
// Created by tedmw on 2/12/2024.
//

#include "Deck.h"
#include <ctime> // for srand and rand

// Constructor
Deck::Deck() : head(nullptr) {
    // Initialize the deck with all 52 cards
    for (int val = 1; val <= 13; ++val) {
        for (int st = 0; st < 4; ++st) {
            Suit suit = static_cast<Suit>(st);
            Card newCard(val, suit);
            addCard(newCard);
        }
    }
}

// Destructor to deallocate memory
Deck::~Deck() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Function to add a card to the deck
void Deck::addCard(const Card& card) {
    Node* newNode = new Node(card);
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to shuffle the deck
void Deck::shuffle() {
    std::srand(unsigned(std::time(0))); // Seed random number generator
    int deckSize = countCards();
    if (deckSize < 2) return; // No need to shuffle if only one card or none
    Node* current = head;
    for (int i = 0; i < deckSize - 1; ++i) {
        int randIndex = rand() % deckSize;
        // Swap values between current node and node at random index
        Card temp = current->card;
        Node* tempNode = current;
        for (int j = 0; j < randIndex; ++j) {
            if (tempNode->next == nullptr) {
                continue;
            }
            tempNode = tempNode->next;
        }
        current->card = tempNode->card;
        tempNode->card = temp;
        current = current->next;
    }
}

// Function to count cards in the deck
int Deck::countCards() const {
    int count = 0;
    Node* temp = head;
    while (temp) {
        ++count;
        temp = temp->next;
    }
    return count;
}

// Overloaded << operator for printing the deck
std::ostream& operator<<(std::ostream& os, const Deck& deck) {
    Node* temp = deck.head;
    while (temp) {
        os << temp->card << std::endl;
        temp = temp->next;
    }
    return os;
}

// Node constructor
Node::Node(const Card& c) : card(c), next(nullptr) {}
