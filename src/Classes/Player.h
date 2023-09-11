#ifndef PLAYER_H
#define PLAYER_H

#include "./Effect.h"
#include "./Card.h"


struct Player{
    char name[12];
    int id;

    int maxHp;
    int currentHp;
    int atk;
    int matk;
    int def;
    int mdef;

    struct Effect attackEffects[10];
    struct Effect magicAttackEffects[10];
    struct Effect defenseEffects[10];
    struct Effect magicDefenseEffects[10];
    int shield;
    int shieldDuration;
    int state;

};

int DamageFormula(struct Player p, struct Card c){
    float totalAtk = (float)p.atk;
    float atkBuff = 1.0f;
    for(int i =0; i<10 ; i++){
        if(p.attackEffects[i].effect!=0){
            atkBuff += p.attackEffects[i].effect;
        }
    }
    totalAtk= totalAtk*atkBuff;
    int totalDmg = ((int)totalAtk*c.atk);
    return (int)totalDmg;
}

int MagicDamageFormula(struct Player p, struct Card c){
    float totalAtk = (float)p.atk;
    float atkBuff = 1.0f;
    for(int i =0; i<10 ; i++){
        if(p.magicAttackEffects[i].effect!=0){
            atkBuff += p.magicAttackEffects[i].effect;
        }
    }
    totalAtk= totalAtk*atkBuff;
    int totalDmg = ((int)totalAtk*c.atk);
    return (int)totalDmg;
}

void takeDMG(struct Player *player, struct Card card){

    int dmg = DamageFormula(*player, card);
    int shield = player->shield;
    int def = player->def;
    float defBuff = 1.0f;

    for(int i =0; i<10 ; i++){
        if(player->defenseEffects[i].effect!=0){
            defBuff += player->defenseEffects[i].effect;
        }
    }

    def = def * defBuff;

    printf("def: %d\n", def);

    dmg = (int)(dmg *(100.0f/(100.0f+(float)def)));

    if(player->shield>0){
        player->shield = player->shield - dmg;
        dmg = dmg - shield;
    }
    if(player->shield<0){
        player->shield=0;
    }
    if(dmg<0){
        dmg=0;
    }

    printf("%d\n", dmg);

    player->currentHp -= dmg;

    if(player->currentHp < 0){
        player->state = FALSE;
    }
}

void takeMagicDMG(struct Player *player, struct Card card){
    int dmg = MagicDamageFormula(*player, card);
    int shield = player->shield;
    int def = player->def;
    float defBuff = 1.0f;

    for(int i =0; i<10 ; i++){
        if(player->magicDefenseEffects[i].effect!=0){
            defBuff += player->magicDefenseEffects[i].effect;
        }
    }

    def = def * defBuff;

    printf("def: %d\n", def);

    dmg = (int)(dmg *(100.0f/(100.0f+(float)def)));

    if(player->shield>0){
        player->shield = player->shield - dmg;
        dmg = dmg - shield;
    }
    if(player->shield<0){
        player->shield=0;
    }
    if(dmg<0){
        dmg=0;
    }

    printf("%d\n", dmg);

    player->currentHp -= dmg;

    if(player->currentHp < 0){
        player->state = FALSE;
    }
}

void atkCard(struct Card c, struct Player *p, struct Player *target){
    switch (c.cardType)
    {
    case 1:
        takeDMG(target, c);
    break;

    case 2:
        takeMagicDMG(target, c);
    break;
    
    default:
        break;
    }
}

void defCard(struct Card c, struct Player *p){

    switch (c.cardType)
    {
    case 3:
        if(p->defenseEffects[9].effect!=0.0f){
            p->defenseEffects[9]=c.effect;
        }else{
            for(int i = 0; i<10; i++){
                if(p->defenseEffects[i].effect==0.0f){
                    p->defenseEffects[i]=c.effect;
                    i=10;
                }
            }
        }
    break;
    case 4:
        if(p->magicDefenseEffects[10].effect!=0.0f){
            p->magicDefenseEffects[0]=c.effect;
        }else{
            for(int i = 0; i<10; i++){
                if(p->magicDefenseEffects[i].effect==0.0f){
                    p->magicDefenseEffects[i]=c.effect;
                    i=10;
                }
            }
        }
    break;
    
    default:
        break;
    }

}

void buffCard(struct Card c, struct Player *p){

    switch (c.cardType)
    {
    case 5:
        if(p->attackEffects[10].effect!=0.0f){
            p->attackEffects[0]=c.effect;
        }else{
            for(int i = 0; i<10; i++){
                if(p->attackEffects[i].effect==0.0f){
                    p->attackEffects[i]=c.effect;
                    i=10;
                }
            }
        }
    break;
    case 6:
        if(p->magicAttackEffects[10].effect!=0.0f){
            p->magicAttackEffects[0]=c.effect;
        }else{
            for(int i = 0; i<10; i++){
                if(p->magicAttackEffects[i].effect==0.0f){
                    p->magicAttackEffects[i]=c.effect;
                    i=10;
                }
            }
        }
    break;
    case 7:
        p->currentHp+= c.heal;
        if(p->currentHp>p->maxHp){
            p->currentHp = p->currentHp;
        }
    break;
    case 8:
        if(p->shield < c.shield){
            p->shield = c.shield;
            p->shieldDuration=c.effect.duration;
        }
    break;
    
    default:
        break;
    }

}

void useCard(struct Card c, struct Player *p, struct Player *target){
    
    switch (c.cardType)
    {
    case 1:
        atkCard(c, p, target);
    break;
    case 2:
        atkCard(c, p, target);
    break;
    case 3:
        defCard(c, p);
    break;
    case 4:
        defCard(c, p);
    break;
    case 5:
        buffCard(c, p);
    break;
    case 6:
        buffCard(c, p);
    break;
    case 7:
        buffCard(c, p);
    break;
    case 8:
        buffCard(c, p);
    break;
    
    default:

        break;
    }


}


#endif