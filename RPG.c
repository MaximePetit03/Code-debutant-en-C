#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[16];
    int Max_Hp;
    int player_life;
    int player_roll;
}player;

typedef struct {
    int MaxHp;
    int dragon_life;
    int dragon_roll;
}dragon;

int init_characters();
int display_player();
int display_dragon();
int roll_dice(); 
int roll_dices(); //Spin dice three time
int init_turn(dragon *Pv, player *pv); //Choose who begin wth roll dices
int player_attack();
int dragon_attack();
int game_turn(); //how game turn takes place

int init_characters(player *pv, dragon *Pv){
    printf("Quelle est ton nom ?(Max 15 lettres, pas d'espaces) ");
    scanf("%s", pv->name);
    pv->player_life = 20;
    pv->Max_Hp = 20;
    Pv->dragon_life = 20;
    Pv->MaxHp = 20;
}
int display_player(player *pv){
    printf("Joueur\nname : %s\n", pv->name);
    printf("Hp : %d/%d\n", pv->player_life, pv->Max_Hp);
}

int display_dragon(dragon *Pv){
    printf("\nDialga\n");
    printf("Hp : %d/%d\n", Pv->dragon_life, Pv->MaxHp);
}
int roll_dice(int faces){
    int random = rand() % faces + 1;
    return random;
}
int roll_dices(int dices, int faces){
    int sum_dices = 0; // sum of dices
    for(int i = 0; i < 3; i++){
        int roll_dice();
        sum_dices += roll_dice(6);
    }
    return sum_dices;
}
int init_turn(dragon *Pv, player *pv){
    pv->player_roll = 0;
    Pv->dragon_roll = 0;
    
    pv->player_roll += roll_dices(3, 6);
    printf("\n%d\n", pv->player_roll);
    Pv->dragon_roll += roll_dices(3, 6);
    printf("%d\n", Pv->dragon_roll);
    
    if(pv->player_roll > Pv->dragon_roll){
        printf("\n%s attaque Dialga de %d dégats\n", pv->name, pv->player_roll);
        Pv->dragon_life -= pv->player_roll;
        player_attack(Pv, pv);
    } else if (pv->player_roll < Pv->dragon_roll){
        printf("\nDialga attaque de %d dégats\n", Pv->dragon_roll);
        pv->player_life -= Pv->dragon_roll;
        player_attack(Pv, pv);
    }
}
int player_attack(dragon *Pv, player *pv){
    printf("Joueur\nname : %s\n", pv->name);
    printf("Hp : %d/100\n", pv->player_life);
    printf("\nDialga\n");
    printf("Hp : %d/100\n", Pv->dragon_life);

    return Pv->dragon_life;
}
int dragon_attack(player *pv, dragon *Pv){
    printf("Joueur\nname : %s\n", pv->name);
    printf("Hp : %d/100\n", pv->player_life);
    printf("\nDialga\n");
    printf("Hp : %d/100\n", Pv->dragon_life);

    return pv->player_life;
}
int game_turn(dragon *Pv, player *pv){
    while(pv->player_life > 0 && Pv->dragon_life > 0) {
        init_turn(Pv, pv);
    }
    if (pv->player_life <= 0) {
            printf("Vous avez perdu\n");
        } else if (Pv->dragon_life <= 0){
            printf("Vous avez gagné\n");
    }
}
int main(){
    srand(time(NULL));
    player pv;
    dragon Pv;
    init_characters(&pv, &Pv);
    display_player(&pv);
    display_dragon(&Pv);
    roll_dices(3, 6);
    game_turn(&Pv, &pv);
}






