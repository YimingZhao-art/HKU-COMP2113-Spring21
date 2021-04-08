//This file is used to initialize certain data of the game
//Following are libraries we need to use.
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<string>
#include<cctype>
#include<iomanip>
#include<vector>
//Following are libraries defined by us.
#include "data.h"
#include "initial.h"

using namespace std;

//read magics,and set the default number
void initialmagics(MAGICS magics[]) //Initial the magics of the game.
{
    for(int i=0; i<10; i++)
        magics[i].damage = 6 * (i + 1);  //Initial the damage of magics.

    //Initial the name of the magics.
    magics[0].name = "Flap";
    magics[1].name = "Hit";
    magics[2].name = "Sound_Explosion";
    magics[3].name = "Shock_Wave";
    magics[4].name = "Whirlwind";
    magics[5].name = "Rapid_Impact";
    magics[6].name = "Extreme_Freezing_Point";
    magics[7].name = "Rainbow_Rays";
    magics[8].name = "Chidori";
    magics[9].name = "Fusion_Strike";

    return;
}

//set the boss default parameter
void initialboss(BOSS boss[]) //Initial the data of boss.
{
    //Initial the name of boss
    boss[0].name = "Fire_Cloud_Cthulhu";
    boss[1].name = "Sea_Dragon";
    boss[2].name = "Tree_Giant";
    boss[3].name = "Lu_Benwee";

    //Initial the current hp, hpmax and level of boss
    for(int i=0; i<4; i++)
    {
        boss[i].hp = 800;
        boss[i].hpmax = 800;
        boss[i].level = 10;
    }
    //Initial the charateristic of boss
    boss[0].character = "fire";
    boss[1].character = "water";
    boss[2].character = "wood";
    boss[3].character = "normal";

    return;
}


//set the pokemon default
void initialpokemon(POKEMON pokemons[]) //Initial the data of Pokemons.
{   
    //Initial the name of pokemons.
    pokemons[0].name = "Flame_Orangutan";
    pokemons[1].name = "Ruth_Wong";
    pokemons[2].name = "Mona_Boob";
    pokemons[3].name = "PDD";

    //Initial the level, hp and magics and experience of pokemons.
    for(int i=0; i<4; i++)
    {
        pokemons[i].level = 1;
        pokemons[i].hp = 24;
        pokemons[i].hpmax = 24;
        pokemons[i].experience = 0;
    }

    //Initial the characteristics of pokemons.
    pokemons[0].character = "fire";
    pokemons[1].character = "water";
    pokemons[2].character = "wood";
    pokemons[3].character = "normal";

    return;
}
