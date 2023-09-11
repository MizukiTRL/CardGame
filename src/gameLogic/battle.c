#include <stdio.h>
#include "../Classes/Deck.h"
#include "../Classes/Player.h"
#include "../definitions.h"

void useCardTurn(struct Player *user,struct Player *target, struct Card c, int *points){
    if(c.cost>points){
        printf("insuficient points\n");
        return;
    }
    if(c.id == 0){
        printf("no card selected\n");
        return;
    }

    useCard(c, user, target);

    *points -= c.cost;

}

int battle(struct Player *p, struct Player *e, struct Deck deck, struct Card *cards){

    //to do:
    //ending battle
    //enemy AI

        //1: use card
        //2: end turn
        //3: use generic card

    int battle = TRUE;
    int win = TRUE;
    int energy = 5;
    int maxEnergy = 10;
    int turn = 0;

    while (battle){
        energy += 3;

        int turnEnd = FALSE;

        if(energy >maxEnergy){
            energy = 10;
        }

        
        

        turn += 1;
        printf("Turn: %d\n", turn);

        while (!turnEnd){

            int optAction = 0;
            int optCard;
            int turnEnd = FALSE;

            switch (optAction)
            {
            case 1:
                if(optCard<5 && optCard>=0){
                    useCardTurn(p, e, deck.handDeck[optCard], &energy);
                    deck.handDeck[optCard] = cards[0];
                }else{
                    printf("invalit input");
                }
                
            break;
            case 2:
                printf("turn ended\n");
                turnEnd = TRUE;
            break;
            
            default:
                break;
            }

            if(e->state == FALSE){
                turnEnd = TRUE;
                battle = FALSE;
            }

        }

        if(p->state == FALSE){
            battle = FALSE;
            win = FALSE;
        }

        for(int i = 0; i < 10; i++){
            struct Effect *atk = &p->attackEffects[i];
            struct Effect *matk = &p->magicAttackEffects[i];
            struct Effect *def = &p->defenseEffects[i];
            struct Effect *mdef = &p->magicDefenseEffects[i];
            int *shield = &p->shieldDuration;

            struct Effect *eatk = &e->attackEffects[i];
            struct Effect *ematk = &e->magicAttackEffects[i];
            struct Effect *edef = &e->defenseEffects[i];
            struct Effect *emdef = &e->magicDefenseEffects[i];
            int *eshield = &e->shieldDuration;

            if(atk->effectId != 0){
                atk->duration -= 1;
                if(atk->duration == 0){
                    *atk = cards[0].effect;
                }
            }

            if(eatk->effectId != 0){
                eatk->duration -= 1;
                if(eatk->duration == 0){
                    *eatk = cards[0].effect;
                }
            }

            if(matk->effectId != 0){
                atk->duration -= 1;
                if(matk->duration == 0){
                    *matk = cards[0].effect;
                }
            }

            if(ematk->effectId != 0){
                eatk->duration -= 1;
                if(ematk->duration == 0){
                    *ematk = cards[0].effect;
                }
            }

            if(def->effectId != 0){
                def->duration -= 1;
                if(def->duration == 0){
                    *def = cards[0].effect;
                }
            }

            if(edef->effectId != 0){
                edef->duration -= 1;
                if(edef->duration == 0){
                    *edef = cards[0].effect;
                }
            }

            if(mdef->effectId != 0){
                mdef->duration -= 1;
                if(mdef->duration == 0){
                    *mdef = cards[0].effect;
                }
            }

            if(emdef->effectId != 0){
                emdef->duration -= 1;
                if(emdef->duration == 0){
                    *emdef = cards[0].effect;
                }
            }

            if(shield != 0){
                *shield -= 1;
                if(shield == 0){
                    p->shield = 0;
                }
            }

            if(eshield != 0){
                *eshield -= 1;
                if(eshield == 0){
                    e->shield = 0;
                }
            }

            printf("got te card: ");

            int deckPick = 0;

        }

    }

    return win;

}