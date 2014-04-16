#include<stdio.h>
#include "manapool.h"

int can_put_card(card_t card_to_put, manapool_t *pool) {

    pool->current_mana = 1;
    pool->current_mana = pool->max_mana - card_to_put.card_mana;
    if(pool->current_mana >= 0 ){
        return 1;
    }
    else{
        return 0;
    }
}

void add_mana(manapool_t *pool, int mana_to_add) {
    pool->max_mana += mana_to_add;
}

void remove_mana(manapool_t *pool, int mana_to_add) {

    pool->max_mana -= mana_to_add;
}

int main() {
    manapool_t pool;
    card_t attacker = {"Blue car", 2, 3, 1};
    pool.max_mana = 1;
    int mana_to_operate;
    int flag;
    while (flag != 1 && flag != 2) {
        printf("Chose from the options below: \n1:Add mana\n2:Remove mana\nYour Choice: ");
        scanf("%d", &flag);
    }
    switch (flag) {
        case 1:
            printf("Add mana: ");
            scanf("%d", &mana_to_operate);
            add_mana(&pool, mana_to_operate);
            break;
        case 2:
            printf("Remove mana: ");
            scanf("%d", &mana_to_operate);
            remove_mana(&pool, mana_to_operate);
            break;
        default: printf("An error occured");
    }
    if(can_put_card(attacker ,&pool) == 1){
        printf("You have enough mana to put the card");
    }
    else{
        printf("You DON'T have enough mana to put the card");
    }
    return 0;
}
