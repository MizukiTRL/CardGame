#ifndef DECK_H
#define DECK_H

#include "./Card.h"

struct Deck{
    int deck[20];
    struct Card handDeck[5];
    struct Card genericCard;
};


#endif