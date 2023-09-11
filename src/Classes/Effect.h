#ifndef EFFECT_H
#define EFFECT_H
#include "../definitions.h"

struct Effect{
    char name[12];
    char type[3];
    int effectId;
    int canStack;
    float effect;
    int duration;
};
#endif