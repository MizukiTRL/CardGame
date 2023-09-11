#include <stdio.h>
#include <string.h>
#include "../classes/Effect.h"
#include "../classes/Player.h"
#include "../Classes/Card.h"
#include "../definitions.h"
//#include "../cJSON/cJSON.h"

void saveData(struct Player *p, struct Card *e){
    FILE *outfile = fopen("path/to/file", "w");
    fwrite(&p, sizeof(struct Player), 3, outfile);
    fclose(outfile);
}

void loadData(struct Player *p, struct Card *c){
    FILE *file = fopen("./bin/players.bin", "wb");

    if (file != NULL) {
        fread(&p, sizeof(struct Player), 3, file);
        fclose(file);
    }
}

int setUp(){

    struct Effect empty={
        .name = "Empty",
        .effectId = 0,
        .effect = 0,
        .duration = 0,
        .canStack = TRUE,
        .type = "empty"
    };

    struct Player velvet = {
        .id = 1,
        .atk = 75,
        .attackEffects = {empty},
        .matk = 75,
        .magicAttackEffects = {empty},
        .def = 125,
        .defenseEffects = {empty},
        .mdef = 125,
        .magicDefenseEffects = {empty},
        .maxHp = 500,
        .currentHp = 500,
        .name = "Velvet",
        .shield = 0,
        .shieldDuration = 0,
        .state = TRUE
    };

    struct Player mia = {
        .id = 2,
        .atk = 125,
        .attackEffects = {empty},
        .matk = 100,
        .magicAttackEffects = {empty},
        .def = 75,
        .defenseEffects = {empty},
        .mdef = 75,
        .magicDefenseEffects = {empty},
        .maxHp = 450,
        .currentHp = 450,
        .name = "Mia",
        .shield = 0,
        .shieldDuration = 0,
        .state = TRUE
    };


    return TRUE;
}

