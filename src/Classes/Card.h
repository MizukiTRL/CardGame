#ifndef CARD_H
#define CARD_H
#include <stdio.h>
#include "./Effect.h"

struct Card{
    char name[12];
    int id;
    int cost;
    int rarity;
    int cardType;  //0: null  1: pattack  2: mattack  3: pdef buff  4: mdef buff 5: patk buff  6: matk buff  7:healing  8:shield
    float atk;
    int shield;
    int heal;
    struct Effect effect;
    char desc[256];
    char lore[999];
};
#endif