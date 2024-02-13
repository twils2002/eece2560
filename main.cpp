#include <iostream>
#include "Deck.h"

int main() {
    // Initialize deck
    Deck deck;
    std::cout << "Before Shuffle:\n" << deck << std::endl;

    // Shuffle deck
    deck.shuffle();
    std::cout << "After Shuffle:\n" << deck << std::endl;

    return 0;
}

